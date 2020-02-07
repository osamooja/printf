#include "ft_printf.h"

long long int			get_value_s(va_list *ap, t_format *print)
{
	long long int	k;

	k = 0;
	if (print->length_mod == 'H')
		k = (char)va_arg(*ap, int);
	else if (print->length_mod == 'h')
		k = (short int)va_arg(*ap, int);
	else if (print->length_mod == '\0')
		k = va_arg(*ap, int);
	else if (print->length_mod == 'l')
		k = va_arg(*ap, long int);
	else if (print->length_mod == 'L')
		k = va_arg(*ap, long long int);
	return (k);
}

unsigned long long int	get_value_u(va_list *ap, t_format *print)
{
	unsigned long int		k;

	k = 0;
	if (print->type == 'p')
		k = (unsigned long long int)va_arg(*ap, unsigned long long int);
	else
	{
		if (print->length_mod == 'H')
			k = (unsigned char)va_arg(*ap, int);
		if (print->length_mod == 'h')
			k = (unsigned short int)va_arg(*ap, int);
		if (print->length_mod == '\0')
			k = (unsigned long long int)va_arg(*ap, unsigned int);
		if (print->length_mod == 'l')
			k = (unsigned long long int)va_arg(*ap, unsigned long long int);
		if (print->length_mod == 'L')
			k = (unsigned long long int)va_arg(*ap, unsigned long long int);
	}
	return (k);
}

long double				get_value_l_d(va_list *ap, t_format *print)
{
	long double				x;

	x = 0;
	if (print->length_mod == 'l')
		x = (long double)va_arg(*ap, double);
	if (print->length_mod == 'L')
		x = (long double)va_arg(*ap, long double);
	if (print->length_mod == '\0')
		x = (long double)va_arg(*ap, double);
	return (x);
}

int						int_l_s(long long int k, int base)
{
	int		count;

	count = 1;
	if (k == 0)
		return (1);
	while ((k = k / base) != 0)
		count++;
	return (count);
}

int						int_l_u(unsigned long long int k, int base)
{
	int		count;

	count = 1;
	if (k == 0)
		return (1);
	while ((k = k / base) != 0)
		count++;
	return (count);
}
