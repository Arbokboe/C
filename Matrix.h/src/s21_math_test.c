#include "s21_math.h"

#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// test abs
START_TEST(test_s21_abs_and_abs_1) {
  ck_assert_int_eq(s21_abs(88888888), abs(88888888));
}
END_TEST

START_TEST(test_s21_abs_and_abs_2) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(test_s21_abs_and_abs_3) {
  ck_assert_int_eq(s21_abs(-88888888), abs(-88888888));
}
END_TEST

Suite *test_s21_abs(void) {
  Suite *suite = suite_create("s21_abs");
  TCase *tcase_core = tcase_create("s21_abs_case");
  tcase_add_test(tcase_core, test_s21_abs_and_abs_1);
  tcase_add_test(tcase_core, test_s21_abs_and_abs_2);
  tcase_add_test(tcase_core, test_s21_abs_and_abs_3);
  suite_add_tcase(suite, tcase_core);

  return suite;
}

// test fabs
START_TEST(test_s21_fabs_and_fabs_1) {
  ck_assert_float_eq_tol(s21_fabs(9999999999999999.5555324),
                         fabs(9999999999999999.5555324), 1e-6);
}
END_TEST

START_TEST(test_s21_fabs_and_fabs_2) {
  ck_assert_float_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-6);
}
END_TEST

START_TEST(test_s21_fabs_and_fabs_3) {
  ck_assert_float_eq_tol(s21_fabs(-9999999999999999.5555324),
                         fabs(-9999999999999999.5555324), 1e-6);
}
END_TEST

START_TEST(test_s21_fabs_and_fabs_4) {
  ck_assert_ldouble_infinite(s21_fabs(S21_INF_P));
}
END_TEST

Suite *test_s21_fabs(void) {
  Suite *suite = suite_create("s21_fabs");
  TCase *tcase_core = tcase_create("s21_fabs_case");
  tcase_add_test(tcase_core, test_s21_fabs_and_fabs_1);
  tcase_add_test(tcase_core, test_s21_fabs_and_fabs_2);
  tcase_add_test(tcase_core, test_s21_fabs_and_fabs_3);
  tcase_add_test(tcase_core, test_s21_fabs_and_fabs_4);
  suite_add_tcase(suite, tcase_core);

  return suite;
}

// test ceil
START_TEST(test_s21_ceil_and_ceil_1) {
  ck_assert_float_eq_tol(s21_ceil(1532.55), ceil(1532.55), 1e-6);
}
END_TEST

START_TEST(test_s21_ceil_and_ceil_2) {
  ck_assert_float_eq_tol(s21_ceil(0.0), ceil(0.0), 1e-6);
}
END_TEST

START_TEST(test_s21_ceil_and_ceil_3) {
  ck_assert_float_eq_tol(s21_ceil(-1532.55), ceil(-1532.55), 1e-6);
}
END_TEST

Suite *test_s21_ceil(void) {
  Suite *suite = suite_create("s21_ceil");
  TCase *tcase_core = tcase_create("s21_ceil_case");
  tcase_add_test(tcase_core, test_s21_ceil_and_ceil_1);
  tcase_add_test(tcase_core, test_s21_ceil_and_ceil_2);
  tcase_add_test(tcase_core, test_s21_ceil_and_ceil_3);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test floor
START_TEST(test_s21_floor_and_floor_1) {
  ck_assert_float_eq_tol(s21_floor(1532.55), floor(1532.55), 1e-6);
}
END_TEST

START_TEST(test_s21_floor_and_floor_2) {
  ck_assert_float_eq_tol(s21_floor(0.0), floor(0.0), 1e-6);
}
END_TEST

START_TEST(test_s21_floor_and_floor_3) {
  ck_assert_float_eq_tol(s21_floor(-1532.55), floor(-1532.55), 1e-6);
}
END_TEST

Suite *test_s21_floor(void) {
  Suite *suite = suite_create("s21_floor");
  TCase *tcase_core = tcase_create("s21_floor_case");
  tcase_add_test(tcase_core, test_s21_floor_and_floor_1);
  tcase_add_test(tcase_core, test_s21_floor_and_floor_2);
  tcase_add_test(tcase_core, test_s21_floor_and_floor_3);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test fmod
START_TEST(test_s21_fmod_and_fmod_1) {
  ck_assert_float_eq_tol(s21_fmod(1532.55, 4), fmod(1532.55, 4), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_and_fmod_2) {
  ck_assert_float_eq_tol(s21_fmod(-2.0, 1.5), fmod(-2.0, 1.5), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_and_fmod_3) {
  ck_assert_float_eq_tol(s21_fmod(-5.55, -4), fmod(-5.55, -4), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_and_fmod_4) {
  ck_assert_float_eq_tol(s21_fmod(3.4, 4), fmod(3.4, 4), 1e-6);
}
END_TEST

START_TEST(test_s21_fmod_and_fmod_5) {
  ck_assert_float_eq_tol(s21_fmod(888888.58, -958.6), fmod(888888.58, -958.6),
                         1e-6);
}
END_TEST

Suite *test_s21_fmod(void) {
  Suite *suite = suite_create("s21_fmod");
  TCase *tcase_core = tcase_create("s21_fmod_case");
  tcase_add_test(tcase_core, test_s21_fmod_and_fmod_1);
  tcase_add_test(tcase_core, test_s21_fmod_and_fmod_2);
  tcase_add_test(tcase_core, test_s21_fmod_and_fmod_3);
  tcase_add_test(tcase_core, test_s21_fmod_and_fmod_4);
  tcase_add_test(tcase_core, test_s21_fmod_and_fmod_5);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test sqrt
START_TEST(test_s21_sqrt_and_sqrt_1) {
  ck_assert_float_eq_tol(s21_sqrt(4), sqrt(4), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_and_sqrt_2) {
  ck_assert_float_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_and_sqrt_3) {
  ck_assert_float_eq_tol(s21_sqrt(9), sqrt(9), 1e-6);
}
END_TEST

START_TEST(test_s21_sqrt_and_sqrt_4) {
  ck_assert_float_eq_tol(s21_sqrt(9876543), sqrt(9876543), 1e-6);
}

START_TEST(test_s21_sqrt_nan) { ck_assert_ldouble_nan(s21_sqrt(-4)); }
END_TEST

Suite *test_s21_sqrt(void) {
  Suite *suite = suite_create("s21_sqrt");
  TCase *tcase_core = tcase_create("s21_sqqrt_case");
  tcase_add_test(tcase_core, test_s21_sqrt_and_sqrt_1);
  tcase_add_test(tcase_core, test_s21_sqrt_and_sqrt_2);
  tcase_add_test(tcase_core, test_s21_sqrt_and_sqrt_3);
  tcase_add_test(tcase_core, test_s21_sqrt_and_sqrt_4);
  tcase_add_test(tcase_core, test_s21_sqrt_nan);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test exp
START_TEST(test_s21_exp_and_exp_1) {
  ck_assert_float_eq_tol(s21_exp(4.8), exp(4.8), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_and_exp_2) {
  ck_assert_float_eq_tol(s21_exp(-14), exp(-14), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_and_exp_3) {
  ck_assert_float_eq_tol(s21_exp(0.005), exp(0.005), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_and_exp_4) {
  ck_assert_float_eq_tol(s21_exp(-999999), exp(-999999), 1e-6);
}
END_TEST

START_TEST(test_s21_exp_and_exp_5) {
  ck_assert_float_eq_tol(s21_exp(75), exp(75), 1e-6);
}

START_TEST(test_s21_exp_and_exp_6) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), 1e-6);
}
END_TEST

START_TEST(test_exp_nan) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(exp(NAN));
}
END_TEST

START_TEST(test_exp_inf) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(exp(INFINITY));
}
END_TEST

Suite *test_s21_exp(void) {
  Suite *suite = suite_create("s21_exp");
  TCase *tcase_core = tcase_create("s21_exp_case");
  tcase_add_test(tcase_core, test_s21_exp_and_exp_1);
  tcase_add_test(tcase_core, test_s21_exp_and_exp_2);
  tcase_add_test(tcase_core, test_s21_exp_and_exp_3);
  tcase_add_test(tcase_core, test_s21_exp_and_exp_4);
  tcase_add_test(tcase_core, test_s21_exp_and_exp_5);
  tcase_add_test(tcase_core, test_s21_exp_and_exp_6);
  tcase_add_test(tcase_core, test_exp_inf);
  tcase_add_test(tcase_core, test_exp_nan);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test log
START_TEST(test_s21_log_and_log_1) {
  ck_assert_float_eq_tol(s21_log(4.8), log(4.8), 1e-6);
}
END_TEST

START_TEST(test_s21_log_and_log_2) {
  ck_assert_float_eq_tol(s21_log(0.005), log(0.005), 1e-6);
}
END_TEST

START_TEST(test_s21_log_and_log_3) {
  ck_assert_float_eq_tol(s21_log(75), log(75), 1e-6);
}

START_TEST(test_log_nan) {
  ck_assert_ldouble_nan(s21_log(S21_NaN));
  ck_assert_ldouble_nan(log(S21_NaN));
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_nan(log(-1));
}
END_TEST

START_TEST(test_log_inf) {
  ck_assert_ldouble_infinite(s21_log(INFINITY));
  ck_assert_ldouble_infinite(log(INFINITY));
}
END_TEST

Suite *test_s21_log(void) {
  Suite *suite = suite_create("s21_log");
  TCase *tcase_core = tcase_create("s21_log_case");
  tcase_add_test(tcase_core, test_s21_log_and_log_1);
  tcase_add_test(tcase_core, test_s21_log_and_log_2);
  tcase_add_test(tcase_core, test_s21_log_and_log_3);
  tcase_add_test(tcase_core, test_log_inf);
  tcase_add_test(tcase_core, test_log_nan);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test pow
START_TEST(test_s21_pow_and_pow_1) {
  ck_assert_float_eq_tol(s21_pow(4.8, 4), pow(4.8, 4), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_and_pow_2) {
  ck_assert_float_eq_tol(s21_pow(824.248, 4.8), pow(824.248, 4.8), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_and_pow_3) {
  ck_assert_float_eq_tol(s21_pow(0, 4), pow(0, 4), 1e-6);
}

START_TEST(test_s21_pow_and_pow_4) {
  ck_assert_float_eq_tol(s21_pow(1, 4), pow(1, 4), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_and_pow_5) {
  ck_assert_float_eq_tol(s21_pow(824.248, 0), pow(824.248, 0), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_and_pow_6) {
  ck_assert_float_eq_tol(s21_pow(4.8, 0.5), pow(4.8, 0.5), 1e-6);
}

START_TEST(test_s21_pow_and_pow_7) {
  ck_assert_float_eq_tol(s21_pow(-824.248, 2), pow(-824.248, 2), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_and_pow_8) {
  ck_assert_float_eq_tol(s21_pow(4.8, -0.5), pow(4.8, -0.5), 1e-6);
}

START_TEST(test_s21_pow_and_pow_9) {
  ck_assert_float_eq_tol(s21_pow(-824.248, -3.2), pow(824.248, -3.2), 1e-6);
}
END_TEST

START_TEST(test_s21_pow_and_pow_10) {
  ck_assert_float_eq_tol(s21_pow(4.8, -0.5), pow(4.8, -0.5), 1e-6);
}

Suite *test_s21_pow(void) {
  Suite *suite = suite_create("s21_pow");
  TCase *tcase_core = tcase_create("s21_pow_case");
  tcase_add_test(tcase_core, test_s21_pow_and_pow_1);
  tcase_add_test(tcase_core, test_s21_pow_and_pow_2);
  tcase_add_test(tcase_core, test_s21_pow_and_pow_3);
  tcase_add_test(tcase_core, test_s21_pow_and_pow_4);
  tcase_add_test(tcase_core, test_s21_pow_and_pow_5);
  tcase_add_test(tcase_core, test_s21_pow_and_pow_6);
  tcase_add_test(tcase_core, test_s21_pow_and_pow_7);
  tcase_add_test(tcase_core, test_s21_pow_and_pow_8);
  tcase_add_test(tcase_core, test_s21_pow_and_pow_9);
  tcase_add_test(tcase_core, test_s21_pow_and_pow_10);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test atan
START_TEST(test_s21_atan_1) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(10), atan(10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-10), atan(-10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.2), atan(0.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-0.2), atan(-0.2), 1e-6);
}
END_TEST

START_TEST(test_s21_atan_nan) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

Suite *test_s21_atan(void) {
  Suite *suite = suite_create("s21_atan");
  TCase *tcase_core = tcase_create("s21_atan_case");
  tcase_add_test(tcase_core, test_s21_atan_1);
  tcase_add_test(tcase_core, test_s21_atan_nan);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test acos
START_TEST(test_s21_acos_1) {
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.2), acos(0.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.2), acos(-0.2), 1e-6);
}
END_TEST

START_TEST(test_s21_acos_nan) {
  ck_assert_ldouble_nan(s21_acos(5));
  ck_assert_ldouble_nan(acos(5));
}
END_TEST

Suite *test_s21_acos(void) {
  Suite *suite = suite_create("s21_acos");
  TCase *tcase_core = tcase_create("s21_acos_case");
  tcase_add_test(tcase_core, test_s21_acos_1);
  tcase_add_test(tcase_core, test_s21_acos_nan);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test asin
START_TEST(test_s21_asin_1) {
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.2), asin(0.2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.2), asin(-0.2), 1e-6);
}
END_TEST

START_TEST(test_s21_asin_nan) {
  ck_assert_ldouble_nan(s21_asin(10));
  ck_assert_ldouble_nan(asin(10));
}
END_TEST

Suite *test_s21_asin(void) {
  Suite *suite = suite_create("s21_asin");
  TCase *tcase_core = tcase_create("s21_asin_case");
  tcase_add_test(tcase_core, test_s21_asin_1);
  tcase_add_test(tcase_core, test_s21_asin_nan);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test sin
START_TEST(s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(1210), sin(1210), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-1240), sin(-1240), 1e-6);
  ck_assert_ldouble_nan(s21_sin(S21_NaN));
  ck_assert_ldouble_nan(s21_sin(S21_INF_P));
  ck_assert_ldouble_nan(s21_sin(S21_INF_N));
}
END_TEST

Suite *test_s21_sin(void) {
  Suite *suite = suite_create("s21_sin");
  TCase *tcase_core = tcase_create("s21_sin_case");
  tcase_add_test(tcase_core, s21_sin_test);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test cos
START_TEST(s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(1012), cos(1012), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-1110), cos(-1110), 1e-6);
  ck_assert_ldouble_nan(s21_cos(S21_NaN));
  ck_assert_ldouble_nan(s21_cos(S21_INF_P));
  ck_assert_ldouble_nan(s21_cos(S21_INF_N));
}
END_TEST

Suite *test_s21_cos(void) {
  Suite *suite = suite_create("s21_cos");
  TCase *tcase_core = tcase_create("s21_cos_case");
  tcase_add_test(tcase_core, s21_cos_test);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

// test tan
START_TEST(s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(10000), tan(10000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-1000), tan(-1000), 1e-6);
  ck_assert_ldouble_nan(s21_tan(S21_NaN));
  ck_assert_ldouble_nan(s21_tan(S21_INF_P));
  ck_assert_ldouble_nan(s21_tan(S21_INF_N));
}
END_TEST

Suite *test_s21_tan(void) {
  Suite *suite = suite_create("s21_tan");
  TCase *tcase_core = tcase_create("s21_tan_case");
  tcase_add_test(tcase_core, s21_tan_test);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  int error = 0;
  Suite *testing[] = {
      test_s21_abs(),  test_s21_fabs(), test_s21_ceil(), test_s21_floor(),
      test_s21_fmod(), test_s21_sqrt(), test_s21_exp(),  test_s21_log(),
      test_s21_pow(),  test_s21_atan(), test_s21_acos(), test_s21_asin(),
      test_s21_sin(),  test_s21_cos(),  test_s21_tan(),  NULL};
  for (int i = 0; testing[i] != NULL; i++) {
    SRunner *testing_runner = srunner_create(testing[i]);
    srunner_run_all(testing_runner, CK_NORMAL);
    error += srunner_ntests_failed(testing_runner);
    srunner_free(testing_runner);
  }
  return (error == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
