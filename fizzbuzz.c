/**
 * FizzBuzz that uses no coditions and no logical operatos.
 * Only "write" function is used from stdlib.
 * It's so ugle, I love it <3
 *
 * Compile and run:
 *
 *	$ cc -o fizzbuzz fizzbuzz.c
 *	$ ./fizzbuzz
 *	1
 *	2
 *	fizz
 *	...
 */

/* Hacky way to print the same instruction N times. */
#define NTH_15(a)  a;a;a;a;a;a;a;a;a;a;a;a;a;a;a;
#define NTH_10(a)  a;a;a;a;a;a;a;a;a;a;
#define NTH_100(a) NTH_10(NTH_10(a))

enum  str  { NUL=0,  FIZZ,   BUZZ,   FIZZBUZZ  };
char *str[] = { "", "fizz", "buzz", "fizzbuzz" };

/* FizzBuzz is a pattern that repeats every 15 values. */
enum str arr[15] = {
	NUL, NUL, FIZZ, NUL, BUZZ, FIZZ,
	NUL, NUL, FIZZ, BUZZ, NUL, FIZZ,
	NUL, NUL, FIZZBUZZ
};

/* Return 1 if NUM is 0, otherwise return 0. */
int
zero(char num)
{
	static const int map[256] = {1,0};
	return map[num];
}

/* Unsigned to ANSI.  Convert NUM unsigned number to number in form of
 * string in BUF buffer.  Return pointer to result string.  A lot of
 * assumptions here.  You can convert only positive number and buffer
 * has to be 8 bytes long so it fits 8-1 digit long numbers. */
char *
utoa(unsigned num, char buf[8])
{
	int siz = 8;
	buf[--siz] = 0;
	NTH_15(buf[--siz] = (num % 10) + '0'; num /= 10)
	NTH_15(siz += zero(buf[siz]-'0'))
	return &buf[siz];
}

/* Write STR string to standard output. */
void
putstr(char *str)
{
	int write(int, void*, int);
	int len = 0;
	NTH_15(len += zero(zero(str[len])))
	write(1, str, len);
}

int
main(void)
{
	int i=0;
	static char buf[8] = {0};

	NTH_100(putstr(utoa(++i, buf));
		putstr("\r");	/* Magic */
		putstr(str[arr[(i-1)%15]]);
		putstr("\n"))
	return 0;
}
