CC = gcc -Wall -Werror -Wextra -std=c11
OS = $(shell uname)

ifeq ($(OS),Linux)
	Flags = -lcheck  -lm -lrt -lpthread -lsubunit
else
	Flags = -lcheck -lm -lpthread
endif

all: clean s21_math.a test

s21_math: clean s21_math.a test

s21_math.a:
	$(CC) -c s21_math.c -o s21_math.o
	ar rcs s21_math.a *.o
	ranlib s21_math.a
	rm *.o

test:
	$(CC) --coverage s21_math.c s21_math_test.c -o test $(Flags)

gcov_report: test
	./test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html

clang:
	clang-format -style=Google -n *.c *.h

clean:
	rm -rf *.a *.o test *.gcno *.gcda *.info report

rebuild:
	clean all
