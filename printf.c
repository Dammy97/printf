#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
/**
 * _printf - A function like printf
 * @format: sample string to be used to test the function
 * @Return: counting
 */

int _printf(const char *format, ...)
{
	va_list args;

	int counting = 0;

	if (format == NULL)
		return (-1);
	
	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			counting++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == '%')
			{
				write(1, format, 1);
				counting++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				counting++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(args, char *);
				int length;

				for (length = 0; string[length] != '\0' ; length++)
					counting ++;
				length++;
				write(1, string, length);
			}
		}
		format++;
	}
	va_end(args);
	return (counting);

}
