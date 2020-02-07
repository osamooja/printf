#include "ft_printf.h"

int						init_print(t_format *print)
{
	print->length_mod = '\0';
	print->hash = '\0';
	print->index = 0;
	print->minus = '\0';
	print->plus = '\0';
	print->precision = 0;
	print->space = '\0';
	print->type = '\0';
	print->width = 0;
	print->zero = '\0';
	print->dot = '\0';
	print->error = '\0';
	return (1);
}

int						define_base(char type)
{
	if (type == 'd' || type == 'i' || type == 'u' || type == 'U')
		return (10);
	else if (type == 'o')
		return (8);
	else if (type == 'x' || type == 'X')
		return (16);
	else
		return (0);
}

int						is_di(char *c)
{
	if (*c == 'd' || *c == 'i')
		return (1);
	return (0);
}

int						is_ouxx(char *c)
{
	if (*c == 'o' || *c == 'u' || *c == 'U' || *c == 'x' || *c == 'X')
		return (1);
	return (0);
}
