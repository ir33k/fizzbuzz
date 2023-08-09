/**
 * FizzBuzz without logical operations.
 * So there are no conditions and no loops.
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

#define TEN(a) a;a;a;a;a;a;a;a;a;a; /* Same instruction  10 times */
#define HUNDRED(a) TEN(TEN(a))      /* Same instruction 100 times */

/* FizzBuzz is a pattern that repeats every 15 values. */
char *pattern[15] = { "", "", "fizz", "", "buzz", "fizz", "",
	"", "fizz", "buzz", "", "fizz", "", "", "fizzbuzz" };

/* Return 1 if NUM is 0, otherwise return 0. */
int
zero(char num)
{
	static const int map[256] = {1,0};
	return map[num];
}

/* Convert NUM unsigned number that is 8-1 max digits long to string.
 * Return pointer to string. */
char *
utoa(unsigned short num)
{
	static char buf[8] = {0};
	int siz = 8;
	buf[--siz] = 0;
	TEN(buf[--siz] = (num % 10) + '0'; num /= 10)
	TEN(siz += zero(buf[siz]-'0'))
	return &buf[siz];
}

/* Write STR string to standard output. */
void
sput(char *str)
{
	int write(int, void*, int);
	int len = 0;
	TEN(len += zero(zero(str[len])))
	write(1, str, len);
}

int
main(void)
{
	int i=0;
	HUNDRED(sput(utoa(++i));
		sput("\r");	/* Magic */
		sput(pattern[(i-1)%15]);
		sput("\n"))
	return 0;
}
