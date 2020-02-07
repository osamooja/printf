#include "ft_printf.h"

static int	charcheck(char c)
{
	return (c != 'i' && c != 'd' && c != 's' && c != 'S'
	&& c != '%' && c != 'c' && c != 'p' && c != 'U' &&
	c != 'o' && c != 'u' && c != 'u' && c != 'x' && c != 'C'
	&& c != 'X' && c != 'f' && c != 'D' && c != 'O');
}

static int	parce_convs(t_format *print, int i, const char *format)
{
	if ((format[i - 1] == 'l' && format[i - 2] == 'l')
	|| format[i - 1] == 'L')
		print->length_mod = 'L';
	else if (format[i - 1] == 'l')
		print->length_mod = 'l';
	else if ((format[i - 1] == 'h' && format[i - 2] == 'h')
	|| format[i - 1] == 'H')
		print->length_mod = 'H';
	else if (format[i - 1] == 'h')
		print->length_mod = 'h';
	print->type = format[i];
	print->index = i;
	i -= (print->type == '%' ? 1 : 0);
	while (format[i] != '%')
		i--;
	i++;
	return (i);
}

static void	fill_format(t_format *print, int i, const char *format)
{
	int		flag;

	flag = 0;
	while (format[i] && charcheck(format[i]))
	{
		if (format[i] > '0' && format[i] <= '9')
			flag = 1;
		if (flag == 1 && !(format[i] >= '0' && format[i] <= '9'))
			flag = 0;
		if (format[i] == '-')
			print->minus = 'A';
		if (format[i] == '+')
			print->plus = 'A';
		if (format[i] == '0' && flag == 0)
			print->zero = 'A';
		if (format[i] == '#')
			print->hash = 'A';
		if (format[i] == ' ')
			print->space = 'A';
		if (format[i] == '.')
			flag = 2;
		i++;
	}
}

static int	parce_flags(t_format *print, int i, const char *format)
{
	fill_format(print, i, format);
	while (format[i] && !(format[i] > '0' && format[i] <= '9') &&
	format[i] != '.' && charcheck(format[i]))
		i++;
	print->width = ((format[i] >= '0' && format[i] <= '9') ?
	ft_atoi(&format[i]) : 0);
	return (i);
}

int			parce(const char *format, t_format *print, int i, va_list *ap)
{
	init_print(print);
	while (charcheck(format[i]))
	{
		if (format[i] == '.')
			print->dot = 'A';
		if (!format[i])
		{
			print->error = 'A';
			return (-1);
		}
		i++;
	}
	i = parce_convs(print, i, format);
	i = parce_flags(print, i, format);
	if (print->dot)
	{
		while (format[i] != '.')
			i++;
		print->precision = (format[i + 1] == '*' ? va_arg(*ap, int) :
			ft_atoi(&format[i + 1]));
	}
	return (1);
}
