#include "s21_math.h"

long double s21_ceil(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x)) return x;
  long long int intpart;
  intpart = (long long int)x;
  intpart += (x > 0 && (x - intpart));
  return (long double)intpart;
}

long double s21_fabs(double x) {
  long double fabs_x = x;
  if (fabs_x < 0) {
    fabs_x = -fabs_x;
  }
  return fabs_x;
}

long double s21_floor(double x) {
  long double floor_x = (long long int)x;
  if (x < 0 && x - floor_x != 0) {
    floor_x--;
  }
  return floor_x;
}

int s21_abs(int x) {
  if (x < 0) {
    x = -x;
  }
  return x;
}

long double s21_sqrt(double x) {
  long double sqrt_x = x;
  long double left = 0;
  long double right = s21_number(x);
  long double squeeze = 0;
  if (sqrt_x < 0.) {
    squeeze = S21_NaN;
  } else if (sqrt_x == 0) {
    squeeze = 0;
  } else {
    squeeze = (left + right) / 2;
    while (squeeze - left > S21_EPS) {
      if (squeeze * squeeze > sqrt_x)
        right = squeeze;
      else
        left = squeeze;
      squeeze = (left + right) / 2;
    }
  }
  return squeeze;
}

long double s21_number(double x) {
  long double num_x = x;
  long double num_ret = 0;
  if (num_x < 1.0) {
    num_ret = 1;
  } else {
    num_ret = num_x;
  }
  return num_ret;
}

long double s21_fmod(double x, double y) {
  long double fmod_x = x;
  long double fmod_y = y;
  long double result = 0;
  long long int div = 0;
  if (fmod_x != S21_INF_P && fmod_x != S21_INF_N && fmod_x == fmod_x &&
      fmod_y == fmod_y && fmod_y != 0.0) {
    div = fmod_x / fmod_y;
    if (s21_fabs(div) < S21_EPS) {
      result = fmod_x;
    } else {
      result = fmod_x - div * fmod_y;
    }
  } else {
    result = S21_NaN;
  }
  return result;
}

long double s21_exp(double x) {
  long double exp_x = x;
  long double add_value = 1;
  long double result = 1;
  long double i = 1;
  int out = 0;
  if (exp_x != S21_INF_N && exp_x != S21_NaN) {
    while (s21_fabs(add_value) > S21_EPS && !out) {
      add_value *= exp_x / i;
      i++;
      result += add_value;
      if (result > S21_MAX && exp_x > 0) {
        out = 1;
      } else if (result > S21_MAX && exp_x < 0) {
        result = 0.0;
        out = 1;
      }
    }
  } else {
    if (exp_x == S21_INF_N) result = 0;
    if (exp_x == S21_INF_P) result = S21_INF_P;
  }
  if (result < 0) result = 0.0;
  return result;
}

long double s21_log(double x) {
  long double log_x = x;
  int ex_pow = 0;
  long double resul = 0;
  long double last_result = 0;
  if (log_x == log_x && log_x != S21_INF_P && log_x > 0) {
    while (log_x >= S21_EXP) {
      log_x /= S21_EXP;
      ex_pow++;
    }
    for (int i = 0; i < 1000; i++) {
      last_result = resul;
      resul = last_result + 2 * (log_x - s21_exp(last_result)) /
                                (log_x + s21_exp(last_result));
    }
  } else {
    if (log_x != log_x) {
      resul = S21_NaN;
    } else if (log_x == S21_INF_P) {
      resul = S21_INF_P;
    } else if (log_x < 0) {
      resul = S21_NaN;
    } else if (log_x == 0) {
      resul = S21_INF_N;
    }
  }
  return resul + ex_pow;
}

long double s21_pow(double base, double exp) {
  long double result = 0;
  long double pow_base = base;
  if ((exp > S21_MAX && pow_base >= 1) || (pow_base == 0 && exp < 0)) {
    result = S21_INF_P;
  } else if (exp == 0) {
    result = 1;
  } else if ((exp != exp || pow_base != pow_base) ||
             (exp < S21_MAX && exp > 0 && pow_base > -1 && pow_base < 0 &&
              pow_base != S21_INF_N)) {
    result = S21_NaN;
  } else if ((pow_base < -1 && exp < -1) ||
             (pow_base == S21_INF_N && exp < 0 && exp > -1)) {
    result = 0.0;
  } else if (((pow_base < 0 && exp > -1 && exp < 1) && pow_base != S21_INF_N) ||
             pow_base != pow_base) {
    result = S21_NaN;
  } else if (exp > S21_MAX && ((pow_base < 1 && pow_base >= 0) ||
                               (pow_base > -1 && pow_base <= 0))) {
    result = 0.0;
  } else if ((pow_base == S21_INF_N && exp < 1 && exp > 0) ||
             (exp == S21_INF_N && pow_base < 1 && pow_base >= 0)) {
    result = S21_INF_P;
  } else if ((pow_base == S21_INF_N && exp == S21_INF_P) ||
             (pow_base == S21_INF_N && exp != 0)) {
    result = S21_INF_P;
  } else if ((exp == S21_INF_N && pow_base < 0 && pow_base >= -1) ||
             (exp > S21_MAX && pow_base < 0)) {
    result = S21_INF_P;
  } else if ((exp == S21_INF_N && pow_base > 1) ||
             (exp == S21_INF_N && pow_base < -1)) {
    result = 0.0;
  } else if (pow_base < 0) {
    pow_base = s21_fabs(pow_base);
    result = s21_exp(exp * s21_log(pow_base));
    if (s21_fmod(exp, 2) != 0) {
      result = -result;
    }
  } else {
    result = s21_exp(exp * s21_log(pow_base));
  }
  if (result != result && (pow_base < -1 && exp > 1)) {
    result = S21_INF_P;
  }
  return result;
}

long double s21_atan(double x) {
  long double atan_x = x;
  long double result = 0;
  if (atan_x == 1 || atan_x == -1) {
    result = (S21_PI / 4) * atan_x;
  } else if (atan_x > -1 && atan_x < 1) {
    for (int i = 0; i < 1000; i++) {
      result += (s21_pow(-1, i) * s21_pow_int(atan_x, 1 + 2 * i)) / (1 + 2 * i);
    }
  } else {
    for (int i = 0; i < 1000; i++) {
      result += (s21_pow_int(-1, i) * s21_pow_int(atan_x, -(1 + 2 * i))) /
                (1 + 2 * i);
    }
    result =
        ((S21_PI * s21_sqrt(s21_pow_int(atan_x, 2))) / (2 * atan_x)) - result;
  }
  return result;
}

long double s21_pow_int(double base, int exp) {
  long double result = 1;
  int exp_f = s21_fabs(exp);
  for (int j = 0; j < exp_f; j++) {
    result *= base;
  }
  if (s21_fmod(exp, 2) != 0 && exp < 0) {
    result = 1 / result;
  }
  return result;
}

long double s21_asin(double x) {
  long double asin_x = x;
  long double result = 0;
  if (asin_x > -1 && asin_x < 1) {
    result = s21_atan(asin_x / (s21_sqrt(1 - s21_pow_int(asin_x, 2))));
  } else if (asin_x == -1 || asin_x == 1 || asin_x == 0) {
    result = S21_PI / 2 * asin_x;
  } else {
    result = S21_NaN;
  }
  return result;
}

long double s21_acos(double x) {
  long double acos_x = x;
  long double result = 0;
  if (acos_x > 0 && acos_x < 1) {
    result = s21_atan((s21_sqrt(1 - s21_pow_int(acos_x, 2))) / acos_x);
  } else if (acos_x > -1 && acos_x < 0) {
    result = S21_PI + s21_atan((s21_sqrt(1 - s21_pow_int(acos_x, 2))) / acos_x);
  } else if (acos_x == -1 || acos_x == 1 || acos_x == 0) {
    result = S21_PI / 2 - (S21_PI / 2 * acos_x);
  } else {
    result = S21_NaN;
  }
  return result;
}

long double s21_sin(double x) {
  long double result = 0;
  if ((x != x) || s21_fabs(x) == S21_INF_P || s21_fabs(x) == S21_INF_N) {
    result = S21_NaN;
  }
  x = s21_fmod(x, 2 * S21_PI);
  if (x < 0) x += S21_PI * 2;
  long double taylor_row = x;
  long double i = 1;
  while (s21_fabs(taylor_row) > S21_EPS) {
    result = result + taylor_row;
    taylor_row = taylor_row * (-1) * (x * x) / ((2 * i + 1) * (2 * i));
    i++;
  }
  return result;
}

long double s21_cos(double x) {
  long double result = 0;
  if ((x != x) || s21_fabs(x) == S21_INF_P || s21_fabs(x) == S21_INF_N) {
    result = S21_NaN;
  } else {
    result = s21_sin(S21_PI / 2 - x);
  }
  return result;
}

long double s21_tan(double x) { return (s21_sin(x) / s21_cos(x)); }