#include "ft_printf.h"

int		flag_mngr(va_list *ap, t_format *print)
{
	if (print->type == '%')
		percent_print(print);
	else if (is_di(&print->type) == 1)
		ft_print_int_s(get_value_s(ap, print), print);
	else if (is_ouxx(&print->type) == 1)
		ft_print_int_u(get_value_u(ap, print), print);
	else if (print->type == 's')
		string_print((va_arg(*ap, char *)), print);
	else if (print->type == 'c')
		char_print((char)va_arg(*ap, int), print);
	else if (print->type == 'p')
		pointer_print(get_value_u(ap, print), print);
	else if (print->type == 'f')
		long_double_print(get_value_l_d(ap, print), print);
	return (1);
}

void	read_string(const char *format, va_list *ap)
{
	t_format	var_format;
	int			i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parce(format, &var_format, i, ap);
			if (var_format.error)
				break ;
			flag_mngr(ap, &var_format);
			i = var_format.index + (format[i] ? 1 : 0);
		}
		if (format[i] && format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			g_check++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	g_check = 0;
	if (!format)
		exit(-1);
	read_string(format, &ap);
	va_end(ap);
	return (g_check);
}
