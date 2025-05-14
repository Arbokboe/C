#ifndef S21_MATH_H
#define S21_MATH_H
#include <float.h>
#include <stdio.h>

#define S21_PI 3.141592653589793238462643383L
#define S21_EXP 2.7182818284590452353602874713527L
#define S21_EPS 0.00000000000001L
#define S21_MAX 999999999999999999999999999999999.9L
#define S21_INF_P (1.0) / (+0.0)
#define S21_INF_N (1.0) / (-0.0)
#define S21_NaN (0.0) / (0.0)

#define S21_IS_NAN(x) (x != x)
#define S21_IS_INF(x) (x == S21_INF_N || x == S21_INF_P)

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_number(double x);
long double s21_factorial(int x);
long double s21_pow_int(double base, int exp);

#endif