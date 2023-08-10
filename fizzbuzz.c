/**
 * FizzBuzz without logical operations.
 * v2.0 from https://github.com/ir33k/fizzbuzz
 */

#define TEN(a) a;a;a;a;a;a;a;a;a;a; /* Repeat instruction  10 times */
#define HUNDRED(a) TEN(TEN(a))      /* Repeat instruction 100 times */

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
	char *fizz[3] = {"fizz", "", ""};
	char *buzz[5] = {"buzz", "", "", "", ""};
	int i=0;
	HUNDRED(sput(utoa(++i));
		sput("\r");	/* Magic */
		sput(fizz[i%3]);
		sput(buzz[i%5]);
		sput("\n"))
	return 0;
}
