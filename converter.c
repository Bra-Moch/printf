#include "main.h"

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input base
 * @lowercase: flag if hexa values need to be lowercase
 * Return: result string
 */

char *convert(unsigned long int num, int base, int lowercase)
{
	/** Static variables for base chtrs and resulting string buffer */
	static char *rep;
	static char buff[50];
	char *ptr;

	/** Set hexadecimal characters based on lowercase flag */
	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';
	/** perform the conversion */
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
