.PROGRAMM: all clean test check s21_cat
CFLAGS= -Wall -Werror -Wextra -std=c11 -D_GNU_SOURCE

all: clean s21_cat

s21_cat:
	gcc ${CFLAGS} s21_cat.c -o s21_cat

clean:
	rm -rf s21_cat.d* s21_cat RESULT_VALGRIND.txt

check: s21_cat
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h
	python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt s21_cat

test: s21_cat
	bash test_cat.sh
	rm -rf log.txt