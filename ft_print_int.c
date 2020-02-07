#include "ft_printf.h"

char			*int_print_pt2(char *res, t_format *print)
{
	char	*res2;

	if (*res != '-' && (print->plus == 'A' || print->space == 'A') &&
		(is_di(&print->type) || print->type == 'f'))
	{
		res2 = ft_strjoin((print->plus == 'A' ? "+" : " "), res);
		free(res);
		res = res2;
	}
	if (print->hash == 'A' && (print->type == 'x' || print->type == 'X'))
	{
		res2 = ft_strjoin((print->type == 'x' ? "0x" : "0X"), res);
		free(res);
		res = res2;
	}
	if ((int)ft_strlen(res) < print->width)
	{
		res2 = ft_memset(ft_strnew(print->width), ' ', print->width);
		ft_strncpy((print->minus == 'A' ? res2 :
			res2 + print->width - ft_strlen(res)), res, ft_strlen(res));
		free(res);
		res = res2;
	}
	return (res);
}

void			local_str_print(char *str)
{
	write(1, str, ft_strlen(str));
	g_check = g_check + ft_strlen(str);
}

void			ft_print_int_s(long long int k, t_format *print)
{
	int		precision;
	int		base;
	char	*res;

	base = define_base(print->type);
	precision = -1;
	if (print->dot == 'A')
		precision = print->precision;
	else if (print->width > 0 && print->minus == '\0' && print->zero == 'A')
	{
		precision = print->width - (is_di(&print->type) &&
			(print->space == 'A' || print->plus == 'A' || k < 0) ? 1 : 0);
		if ((print->type == 'x' || print->type == 'X') && print->hash == 'A')
			precision -= 2;
	}
	if (print->hash == 'A' && print->type == 'o' &&
		(precision <= (k == 0 ? 1 : int_l_s(k, 8) + 1)))
		precision = (k == 0 ? 1 : int_l_s(k, 8) + 1);
	res = improve_str(ft_itoa_base_s(k, precision, define_base(print->type)),
		&print->type);
	print->hash = (k == 0 ? '\0' : print->hash);
	res = int_print_pt2(res, print);
	local_str_print(res);
	free(res);
}

void			ft_print_int_u(unsigned long long int k, t_format *print)
{
	int		precision;
	int		base;
	char	*res;

	base = define_base(print->type);
	precision = -1;
	if (print->dot == 'A')
		precision = print->precision;
	else if (print->width > 0 && print->minus == '\0' && print->zero == 'A')
	{
		precision = print->width;
		if ((print->type == 'x' || print->type == 'X') &&
			print->hash == 'A' && k != 0)
			precision -= 2;
	}
	if (print->hash == 'A' && print->type == 'o' &&
		(precision <= (k == 0 ? 1 : int_l_u(k, 8) + 1)))
		precision = (k == 0 ? 1 : int_l_u(k, 8) + 1);
	res = improve_str(ft_itoa_base_u(k, precision, define_base(print->type)),
		&print->type);
	print->hash = (k == 0 ? '\0' : print->hash);
	res = int_print_pt2(res, print);
	local_str_print(res);
	free(res);
}
