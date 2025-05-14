#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *buff = 0;
  if (str != S21_NULL) {
    int n = s21_strlen(str);
    buff = (char *)calloc(n + 1, sizeof(char *));
    if (buff != S21_NULL) {
      for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
          buff[i] = str[i] - 32;
        } else
          buff[i] = str[i];
      }
      buff[n] = '\0';
    }
  }
  return buff;
}

void *s21_to_lower(const char *str) {
  char *buff = 0;
  if (str != S21_NULL) {
    int n = s21_strlen(str);
    buff = (char *)calloc(n + 1, sizeof(char *));
    if (buff != S21_NULL) {
      for (int i = 0; i < n; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
          buff[i] = str[i] + 32;
        } else
          buff[i] = str[i];
      }
      buff[n] = '\0';
    }
  }
  return buff;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (!src || !str || (int)start_index < 0 || s21_strlen(src) < start_index) {
    return S21_NULL;
  }
  s21_size_t len = s21_strlen(src) + s21_strlen(str);
  s21_size_t s = start_index + s21_strlen(str);
  s21_size_t t = s21_strlen(str);
  char *result = (char *)calloc(len, sizeof(char *));
  if (result != S21_NULL) {
    for (s21_size_t i = 0; i < len; i++) {
      if (i < start_index) {
        result[i] = src[i];
      } else if (i >= start_index && i < s) {
        result[i] = str[i - start_index];
      } else if (i >= s) {
        result[i] = src[i - t];
      }
    }
    result[len] = '\0';
  }
  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (!src) {
    return S21_NULL;
  }

  if (!trim_chars) {
    return (void *)s21_strdup(src);
  }

  char *start = (char *)src;
  char *end = (char *)src + s21_strlen(src) - 1;

  while (*start && s21_strchr(trim_chars, *start)) {
    start++;
  }

  while (end > start && s21_strchr(trim_chars, *end)) {
    end--;
  }

  void *new_str = malloc((end - start + 2) * sizeof(char));
  if (!new_str) {
    return S21_NULL;
  }

  s21_memcpy(new_str, start, end - start + 1);
  ((char *)new_str)[end - start + 1] = '\0';

  return new_str;
}

char *s21_strdup(const char *s) {
  char *copy = malloc(s21_strlen(s) + 1);
  if (copy) {
    s21_strcpy(copy, s);
  }
  return copy;
}