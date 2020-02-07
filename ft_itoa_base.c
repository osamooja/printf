#include "ft_printf.h"

char		*ft_itoa_base_s(long long int n, int precision, int base)
{
	long long int		n1;
	int					count;
	char				*res;

	if (n == 0 && precision == 0)
		return (ft_strnew(0));
	count = int_l_s(n, base);
	n1 = (n < 0 ? 1 : 0);
	count = (count < precision ? precision : count);
	res = ft_strnew(count + n1);
	if (res == NULL)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	while (--count >= 0)
	{
		res[count + n1] = '0' + (n % base) * (n < 0 ? -1 : 1);
		n = n / base;
	}
	return (res);
}

char		*ft_itoa_base_u(unsigned long long int n, int precision, int base)
{
	int							count;
	char						*res;

	if (n == 0 && precision == 0)
		return (ft_strnew(0));
	count = int_l_u(n, base);
	count = (count < precision ? precision : count);
	res = ft_strnew(count);
	if (res == NULL)
		return (NULL);
	while (--count >= 0)
	{
		res[count] = '0' + (n % base);
		n = n / base;
	}
	return (res);
}

char		*improve_str(char *s, char *type)
{
	char		*res;

	res = s;
	while (*res != '\0')
	{
		if (*res > '9')
			*res += (*type == 'X' ? 'A' - ':' : 'a' - ':');
		res++;
	}
	return (s);
}