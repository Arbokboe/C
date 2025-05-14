CC = gcc -Wall -Werror -Wextra -std=c11
OS = $(shell uname)

ifeq ($(OS),Linux)
    Flags = -lcheck  -lm -lrt -lpthread -lsubunit
else
    Flags = -lcheck -lm -lpthread
endif

all: clean s21_string.a

s21_string: clean s21_string.a test

s21_string.a:
	$(CC) -c s21_*.c $(Flags)
	ar rcs s21_string.a *.o
	ranlib s21_string.a
	rm *.o

test:
	$(CC) --coverage *.c test_dir/*.c -o test $(Flags)
	./test

gcov_report: test
	./test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html

clean:
	rm -rf *.a *.o test *.gcno *.gcda report *.info


cn: 
	clang-format -style=Google -n *.c *.h


