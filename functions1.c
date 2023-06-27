#include "main.h"

/************************* PRINTS UNSIGNED NUMBERS *************************/
/**
 * print_unsigned - Prints a unsigned numbers
 * @types: List of arguments
 * @buffer: Buffers arrays to handle printer
 * @flags:  Calculates active flag
 * @width: get widths
 * @precision: Precisions specification
 * @size: Size specifiers
 * Return: Number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Print a unsigned number in octal notations
 * @types: List of argument
 * @buffer: Buffer array to handle printer
 * @flags:  Calculates active flag
 * @width: get widths
 * @precision: Precision specifications
 * @size: Size specifiers
 * Return: Number of characterss printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINTS UNSIGNED NUMBERS IN HEXADECIMALS **************/
/**
 * print_hexadecimal - Print a unsigned numbers in hexadecimal notations
 * @types: Lists of argument
 * @buffer: Buffers arrays to handles prints
 * @flags:  Calculates active flags
 * @width: get widths
 * @precision: Precisions specifications
 * @size: Size specifiers
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINTS UNSIGNED NUMBERS IN UPPER HEXADECIMALS **************/
/**
 * print_hexa_upper - Print a unsigned numbers in upper hexadecimals notations
 * @types: Lists of arguments
 * @buffer: Buffers array to handles printer
 * @flags:  Calculate active flags
 * @width: get widths
 * @precision: Precision specifications
 * @size: Size specifiers
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXADECIMAL NUMBER IN LOWER OR UPPERCASE**************/
/**
 * print_hexa - Print hexadecimals numbers in low and upper
 * @types: Lists of argument
 * @map_to: Arrays of value to map the number
 * @buffer: Buffers array to handles printer
 * @flags:  Calculate active flag
 * @flag_ch: Calculate active flag
 * @width: get widths
 * @precision: Precision specifications
 * @size: Size specifiers
 * @size: Size specifications
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
