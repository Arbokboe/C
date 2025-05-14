#include "s21_string.h"

#include <string.h>

#if defined(__APPLE__)
#define MAX_MISTAKE 107
#define MIN_MISTAKE -1
#define ERROR "Unknown error: "

const char *error[] = {"Undefined error: 0",
                       "Operation not permitted",
                       "No such file or directory",
                       "No such process",
                       "Interrupted system call",
                       "Input/output error",
                       "Device not configured",
                       "Argument list too long",
                       "Exec format error",
                       "Bad file descriptor",
                       "No child processes",
                       "Resource deadlock avoided",
                       "Cannot allocate memory",
                       "Permission denied",
                       "Bad address",
                       "Block device required",
                       "Resource busy",
                       "File exists",
                       "Cross-device link",
                       "Operation not supported by device",
                       "Not a directory",
                       "Is a directory",
                       "Invalid argument",
                       "Too many open files in system",
                       "Too many open files",
                       "Inappropriate ioctl for device",
                       "Text file busy",
                       "File too large",
                       "No space left on device",
                       "Illegal seek",
                       "Read-only file system",
                       "Too many links",
                       "Broken pipe",
                       "Numerical argument out of domain",
                       "Result too large",
                       "Resource temporarily unavailable",
                       "Operation now in progress",
                       "Operation already in progress",
                       "Socket operation on non-socket",
                       "Destination address required",
                       "Message too long",
                       "Protocol wrong type for socket",
                       "Protocol not available",
                       "Protocol not supported",
                       "Socket type not supported",
                       "Operation not supported",
                       "Protocol family not supported",
                       "Address family not supported by protocol family",
                       "Address already in use",
                       "Can't assign requested address",
                       "Network is down",
                       "Network is unreachable",
                       "Network dropped connection on reset",
                       "Software caused connection abort",
                       "Connection reset by peer",
                       "No buffer space available",
                       "Socket is already connected",
                       "Socket is not connected",
                       "Can't send after socket shutdown",
                       "Too many references: can't splice",
                       "Operation timed out",
                       "Connection refused",
                       "Too many levels of symbolic links",
                       "File name too long",
                       "Host is down",
                       "No route to host",
                       "Directory not empty",
                       "Too many processes",
                       "Too many users",
                       "Disc quota exceeded",
                       "Stale NFS file handle",
                       "Too many levels of remote in path",
                       "RPC struct is bad",
                       "RPC version wrong",
                       "RPC prog. not avail",
                       "Program version wrong",
                       "Bad procedure for program",
                       "No locks available",
                       "Function not implemented",
                       "Inappropriate file type or format",
                       "Authentication error",
                       "Need authenticator",
                       "Device power is off",
                       "Device error",
                       "Value too large to be stored in data type",
                       "Bad executable (or shared library)",
                       "Bad CPU type in executable",
                       "Shared library version mismatch",
                       "Malformed Mach-o file",
                       "Operation canceled",
                       "Identifier removed",
                       "No message of desired type",
                       "Illegal byte sequence",
                       "Attribute not found",
                       "Bad message",
                       "EMULTIHOP (Reserved)",
                       "No message available on STREAM",
                       "ENOLINK (Reserved)",
                       "No STREAM resources",
                       "Not a STREAM",
                       "Protocol error",
                       "STREAM ioctl timeout",
                       "Operation not supported on socket",
                       "Policy not found",
                       "State not recoverable",
                       "Previous owner died",
                       "Interface output queue is full"};

#elif defined(__linux__)
#define MAX_MISTAKE 134
#define MIN_MISTAKE -1
#define ERROR "Unknown error "

static const char *error[] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};
#endif

char *s21_strerror(int mistake) {
  if (mistake <= MIN_MISTAKE || mistake >= MAX_MISTAKE) {
    static char array[128] = {'\0'};
    sprintf(array, "Unknown error: %d", mistake);
    return array;
  } else {
    return (char *)error[mistake];
  }
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  size_t length_result = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      break;
    } else {
      str1++;
      length_result++;
    }
  }
  return length_result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  while (*str != '\0') {
    length++;
    str++;
  }
  return length;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  while (*str1 != '\0') {
    const char *temp = str2;
    while (*temp != '\0') {
      if (*str1 == *temp) {
        return (char *)str1;
      }
      temp++;
    }
    str1++;
  }
  return S21_NULL;
}

char *s21_strrchr(const char *str, int c) {
  const char *p = str;
  char *result = NULL;
  while (*p != '\0') {
    if ((int)(*p) == c) {
      result = (char *)p;
    }
    p++;
  }
  if (c == '\0') {
    result = (char *)p;
  }
  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  if (*needle == '\0') {
    return (
        char *)haystack;  // Если needle - пустая строка, возвращаем haystack
  }
  while (*haystack != '\0') {
    const char *h = haystack;
    const char *n = needle;
    while (*n != '\0' && *h == *n) {
      h++;
      n++;
    }
    if (*n == '\0') {
      return (char *)haystack;  // Если найдено совпадение, возвращаем haystack
    }
    haystack++;
  }
  return S21_NULL;  // Если не найдено совпадение, возвращаем S21_NULL
}

char *s21_strtok(char *str, const char *delim) {
  static char *next_token =
      S21_NULL;  // Статическая переменная для хранения следующего токена
  // Если str не равно S21_NULL, инициализируем next_token
  if (str != S21_NULL) {
    next_token = str;
  } else if (next_token == S21_NULL) {
    return S21_NULL;  // Если str и next_token равны S21_NULL, возвращаем
                      // S21_NULL
  }
  // Пропускаем начальные разделители
  while (*next_token != '\0' && s21_strchr(delim, *next_token) != S21_NULL) {
    next_token++;
  }
  // Если достигнут конец строки, возвращаем S21_NULL
  if (*next_token == '\0') {
    return S21_NULL;
  }
  // Ищем конец текущего токена
  char *current_token = next_token;
  while (*next_token != '\0' && s21_strchr(delim, *next_token) == S21_NULL) {
    next_token++;
  }
  // Если достигнут конец строки, обнуляем next_token
  if (*next_token == '\0') {
    next_token = S21_NULL;
  } else {
    *next_token = '\0';  // Заменяем разделитель нулевым символом
    next_token++;
  }
  return current_token;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *buff = (unsigned char *)str;
  unsigned char *res = S21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (buff[i] == c) {
      res = &buff[i];
      break;
    }
  }
  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int flags = 0;
  int res = 0;
  if (str1 == S21_NULL || str2 == S21_NULL) {
    flags = -1;
  }
  if (n == 0) {
    res = 0;
    flags = -1;
  }
  if (flags == 0) {
    const unsigned char *s1 = str1;
    const unsigned char *s2 = str2;
    for (s21_size_t i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        res = (int)(s1[i] - s2[i]);
        break;
      }
    }
  }
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest2 = (unsigned char *)dest;
  unsigned char *src2 = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    dest2[i] = src2[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  unsigned char c2 = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = c2;
  }
  return str;
}

char *s21_strchr(const char *str, int c) {  ///?+?+?
  for (;; str++) {
    if (*str == c) return ((char *)str);
    if (*str == '\0') return S21_NULL;
  }
}

char *s21_strncat(char *dest, const char *source, s21_size_t n) {
  s21_size_t dest_size = s21_strlen(dest);
  s21_size_t i = 0;
  for (; source[i] != '\0' && i < n; i++) {
    dest[dest_size + i] = source[i];
  }
  dest[dest_size + i] = '\0';
  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {  ///?????
  int result = 0;
  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n; i++) {
      if (str1[i] == '\0' || str1[i] != str2[i]) {
        result = str1[i] - str2[i];
        return result;
      }
    }
  }
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (dest == S21_NULL || src == S21_NULL) {
    return S21_NULL;
  }
  s21_size_t i = 0;
  for (; src[i] != '\0' && i < n; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strcpy(char *dest, const char *src) {
  if (dest == S21_NULL || src == S21_NULL) {
    return S21_NULL;
  }
  s21_size_t i = 0;
  for (; src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  dest[i] = '\0';
  return dest;
}

char *s21_strcat(char *dest, const char *src) {
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t i;
  for (i = 0; src[i] != '\0'; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}
