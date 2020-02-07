#include "ft_printf.h"

void	string_print(char *str, t_format *print)
{
	int	len;

	if (!print->precision && print->dot)
		str = "";
	if (!str)
		str = "(null)";
	len = (ft_strlen(str) > (size_t)print->precision &&
			(size_t)print->precision ? print->precision : ft_strlen(str));
	print->width = (print->minus ? print->width : print->width - len);
	if (print->minus)
		string_print_minus(str, print, len);
	else
		string_print_plus(str, print, len);
}

void	string_print_minus(char *str, t_format *print, int len)
{
	write(1, str, len);
	print->width -= len;
	g_check += len;
	while (print->width > 0)
	{
		write(1, " ", 1);
		print->width--;
		g_check++;
	}
}

void	string_print_plus(char *str, t_format *print, int len)
{
	while (print->width > 0)
	{
		if (print->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		print->width--;
		g_check++;
	}
	write(1, str, len);
	g_check += len;
}
