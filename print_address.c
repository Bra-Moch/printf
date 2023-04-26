#include "main.h"

/**
 * print_address - prints address of input in hexa format
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */

int print_address(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	/** prevent unused parameter warning */
	(void)f;

	if (!p)
		/** print nill for NULL pointer */
		return (_puts("(nil)"));
	/** convert pointer to hexadecimal string */
	str = convert(p, 16, 1);
	/** print the leading '0x' */
	count += _puts("0x");
	/** print the hexadecimal string */
	count += _puts(str);
	return (count);
}
