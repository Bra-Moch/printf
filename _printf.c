#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of the formatted output string
 */

int _printf(const char *format, ...)
{
	/** Initialize variables */
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};
	register int count = 0;

	/** Start the variable argument list */
	va_start(arguments, format);

	/** Check for edge cases */
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	/** Loop through each character in the format string */
	for (p = format; *p; p++)
	{
		/** If a percent sign is encountered, look for any optional flags */
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				/** If the next character is also a percent sign, output a single percent sign*/
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		}
		else
		{
			/** If the character is not a percent sign, output it as is */
			count += _putchar(*p);
		}
	}
	/** Output the end-of-output marker and end the variable argument list */
	_putchar(-1);
	va_end(arguments);

	/** Return the total length of the formatted output string */
	return (count);
}
