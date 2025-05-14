#ifndef S21_GREP_H
#define S21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 2048

typedef struct options {
  int e, f, i, v, c, l, n, h, s, o, error_option, f_no_pattern_er;
  char regex_pattern[BUFFSIZE], strs_file[BUFFSIZE];
} opt;

void AnalysOption(int argc, char *argv[], opt *options);
void ParserFlag(int argc, char *argv[], opt *options);
int CheckOptions(int argc, char *argv[], opt *options);
void FileProcessing(int argc, char *argv[], opt *options);
int SearchPattern(FILE *file, char *file_name, opt *options, int only_file);
int NumFilesArgv(char *argv[], opt *options);
void ProcessStringOutput(opt *options, int only_file, char *file_name,
                         int *num_match, int num_str_file, regex_t *preg);
void PrintFileName(int only_file, char *file_name, opt *options);
void OptionF(char *optarg, opt *options);
void OptionO(opt *options, regex_t *preg, int num_str_file);
void OptionC(opt *options, int only_file, char *file_name, int num_match);
void OptionL(opt *options, char *file_name, int num_match);
void WritePattern(char *all_patterns, char *pattern, int reg_operator);

#endif
