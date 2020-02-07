#include "ft_printf.h"

unsigned long long int		int_after_decimal(long double x, int precision)
{
	unsigned long long int		l;

	l = 1;
	x = x - (long double)(unsigned long long int)x;
	if (precision > 20)
		precision = 20;
	while (precision-- > 0)
		x = x * 10;
	l = (unsigned long long int)x;
	return (l);
}

static void					my_precision(t_format *print)
{
	int		precision;

	precision = -1;
	if (print->dot == '\0')
		precision = 6;
	if (print->dot == 'A' && print->precision > 0)
		precision = print->precision;
	if (print->hash == 'A' && precision < 0)
		precision = 0;
	print->precision = precision;
}

static char					*l_d_print_start(long double x, t_format *print)
{
	char	*res;
	char	*tmp;

	res = ft_strnew(1);
	res[0] = '\0';
	if (print->precision > 0)
		res = ft_itoa_base_u(int_after_decimal(x, print->precision),
			print->precision, 10);
	if (print->precision >= 0)
	{
		tmp = ft_strnew(ft_strlen(res) + 1);
		tmp[0] = '.';
		ft_strncpy(tmp + 1, res, ft_strlen(res));
		if (print->precision > 0)
			free(res);
		res = tmp;
	}
	return (res);
}

long double					ft_round_double(long double x, int precision)
{
	long double				res;

	if (precision < 0)
		precision = 0;
	if (precision > 20)
		precision = 20;
	res = 0.5;
	while (precision-- > 0)
		res = res / 10;
	return (x + res);
}

void						long_double_print(long double x, t_format *print)
{
	int		len;
	int		sign;
	char	*res;
	char	*res2;
	char	*res3;

	sign = (x < 0 ? -1 : 1);
	x = x * sign;
	my_precision(print);
	x = ft_round_double(x, print->precision);
	res = l_d_print_start(x, print);
	len = 1;
	if (print->minus == '\0' && print->zero == 'A')
		len = print->width - ft_strlen(res) -
			(print->space == 'A' || print->plus == 'A' || sign == -1 ? 1 : 0);
	len = (len < 1 ? 1 : len);
	res2 = ft_itoa_base_u((unsigned long long int)x, len, 10);
	res3 = ft_strjoin(res2, res);
	free(res2);
	free(res);
	res2 = ft_strjoin((sign == -1 ? "-" : ""), res3);
	free(res3);
	res2 = int_print_pt2(res2, print);
	local_str_print(res2);
	free(res2);
}
