#include "s21_grep.h"

int main(int argc, char *argv[]) {
  opt options = {};
  AnalysOption(argc, argv, &options);
  if (CheckOptions(argc, argv, &options)) {
    FileProcessing(argc, argv, &options);
  }
  return 0;
}

void AnalysOption(int argc, char *argv[], opt *options) {
  ParserFlag(argc, argv, options);
  if (!options->e && !options->f) {
    WritePattern(options->regex_pattern, argv[optind], 0);
  } else {
    options->regex_pattern[strlen(options->regex_pattern) - 1] = '\0';
  }
}

void ParserFlag(int argc, char *argv[], opt *options) {
  int flag_opt = 0;
  while (!options->error_option && !options->f_no_pattern_er &&
         ((flag_opt = getopt_long(argc, argv, "e:f:ivclnhso", NULL, NULL)) !=
          -1)) {
    switch (flag_opt) {
      case 'e':
        options->e = 1;
        WritePattern(options->regex_pattern, optarg, 1);
        break;
      case 'i':
        options->i = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'c':
        options->c = 1;
        break;
      case 'l':
        options->l = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 'h':
        options->h = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 'f':
        options->f = 1;
        if (optarg != NULL) {
          OptionF(optarg, options);
        }
        break;
      case 'o':
        options->o = 1;
        break;
      case '?':
        options->error_option = 1;
        break;
    }
  }
}

int CheckOptions(int argc, char *argv[], opt *options) {
  int flag_there = 1;
  if (options->f_no_pattern_er) {
    fprintf(stderr, "No such file or directory.\n");
    flag_there = 0;
  } else if (!argv[optind] || (optind == 1 && argc == 2)) {
    fprintf(stderr,
            "usage: grep [-abcdDEFGHhIiJLlMmnOopqRSsUVvwXxZz] [-A num] [-B "
            "num] [-C[num]]\n\t[-e pattern] [-f file] [--binary-files=value] "
            "[--color=when]\n\t[--context[=num]] [--directories=action] "
            "[--label] [--line-buffered]\n\t[--null] [pattern] [file ...]");
    flag_there = 0;
  }
  return flag_there;
}

void FileProcessing(int argc, char *argv[], opt *options) {
  int only_file = NumFilesArgv(argv, options);
  if (options->e != 1 && options->f != 1) {
    optind++;
  }

  while (optind < argc) {
    FILE *file = fopen(argv[optind], "r");
    if (file == NULL) {
      if (options->s != 1) {
        fprintf(stderr, "No such file or directory.\n");
      }
    } else {
      SearchPattern(file, argv[optind], options, only_file);
      fclose(file);
    }
    optind++;
  }
}

int SearchPattern(FILE *file, char *file_name, opt *options, int only_file) {
  regex_t preg;

  regmatch_t arr_match_reg[1];

  int num_match = 0;
  int num_str_file = 0;
  int comp_flag = 0;
  if (options->i) {
    comp_flag = regcomp(&preg, options->regex_pattern,
                        REG_EXTENDED | REG_ICASE | REG_NEWLINE);
  } else {
    comp_flag = regcomp(&preg, options->regex_pattern, REG_EXTENDED);
  }
  if (comp_flag != 0) {
    fprintf(stderr, "Compilation error.\n");
    return 0;
  }
  while (fgets(options->strs_file, BUFFSIZE, file) != NULL) {
    num_str_file++;
    char *str = options->strs_file;
    if (options->o && !options->v &&
        (!regexec(&preg, str,
                  sizeof((arr_match_reg)) / sizeof((arr_match_reg)[0]),
                  arr_match_reg, 0))) {
      ProcessStringOutput(options, only_file, file_name, &num_match,
                          num_str_file, &preg);
    } else if (regexec(&preg, options->strs_file, 0, NULL, 0) == 0 &&
               !options->v && strcmp(options->strs_file, "\n")) {
      ProcessStringOutput(options, only_file, file_name, &num_match,
                          num_str_file, &preg);
    } else if (regexec(&preg, options->strs_file, 0, NULL, 0) != 0 &&
               options->v) {
      ProcessStringOutput(options, only_file, file_name, &num_match,
                          num_str_file, &preg);
    }
  }
  OptionC(options, only_file, file_name, num_match);
  OptionL(options, file_name, num_match);
  regfree(&preg);
  return 1;
}

int NumFilesArgv(char *argv[], opt *options) {
  int flag_num_files;
  if (options->e || options->f) {
    if (argv[optind + 1] == NULL) {
      flag_num_files = 0;
    } else {
      flag_num_files = 1;
    }
  } else {
    if (argv[optind + 2] == NULL) {
      flag_num_files = 0;
    } else {
      flag_num_files = 1;
    }
  }
  return flag_num_files;
}

void ProcessStringOutput(opt *options, int only_file, char *file_name,
                         int *num_match, int num_str_file, regex_t *preg) {
  (*num_match)++;
  if (!options->c && !options->l) {
    PrintFileName(only_file, file_name, options);
    if (options->o && !options->v) {
      OptionO(options, preg, num_str_file);
    } else {
      if (options->n) {
        printf("%d:", num_str_file);
      }
      if (options->o && !options->v) {
        OptionO(options, preg, num_str_file);
      } else {
        fputs(options->strs_file, stdout);
      }
      if (options->strs_file[strlen(options->strs_file)] == '\0' &&
          options->strs_file[strlen(options->strs_file) - 1] != '\n')
        printf("\n");
    }
  }
}

void PrintFileName(int only_file, char *file_name, opt *options) {
  if (only_file && !options->h) {
    printf("%s:", file_name);
  }
}

void OptionF(char *optarg, opt *options) {
  char temp_str_file[BUFFSIZE];
  FILE *temp_file_reg = NULL;
  if ((temp_file_reg = fopen(optarg, "r")) != NULL) {
    while (fgets(temp_str_file, BUFFSIZE, temp_file_reg) != NULL) {
      if (temp_str_file[0] == '\n') {
        continue;
      }
      if (temp_str_file[strlen(temp_str_file) - 1] == '\n') {
        temp_str_file[strlen(temp_str_file) - 1] = '\0';
      }
      WritePattern(options->regex_pattern, temp_str_file, 1);
    }
    if (fclose(temp_file_reg) != 0) {
      perror("Error closing file");
    }
  } else {
    options->f_no_pattern_er = 1;
    fprintf(stderr, "No such file or directory.\n");
  }
}

void OptionO(opt *options, regex_t *preg, int num_str_file) {
  char *str = options->strs_file;

  regmatch_t arr_match_reg[1];

  regoff_t len;

  while (!regexec(preg, str,
                  sizeof((arr_match_reg)) / sizeof((arr_match_reg)[0]),
                  arr_match_reg, 0)) {
    len = arr_match_reg[0].rm_eo - arr_match_reg[0].rm_so;

    if (options->n) {
      printf("%d:", num_str_file);
    }
    printf("%.*s\n", (int)len, str + arr_match_reg[0].rm_so);
    str += arr_match_reg[0].rm_eo;
  }
}

void OptionC(opt *options, int only_file, char *file_name, int num_match) {
  if (options->c) {
    PrintFileName(only_file, file_name, options);
    if (!options->l) {
      printf("%d\n", num_match);
    } else if (options->l && num_match > 1) {
      printf("%d\n", 1);
    } else {
      printf("%d\n", num_match);
    }
  }
}

void OptionL(opt *options, char *file_name, int num_match) {
  if (options->l && num_match) {
    printf("%s\n", file_name);
  }
}

void WritePattern(char *all_patterns, char *pattern, int reg_operator) {
  if (pattern) {
    strcat(all_patterns, pattern);
    if (reg_operator) {
      all_patterns = strcat(all_patterns, "|");
    }
  }
}
