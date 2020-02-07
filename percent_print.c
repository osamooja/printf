#include "ft_printf.h"

static void		print_space(int n, char c)
{
	while (n > 0)
	{
		write(1, &c, 1);
		g_check++;
		n--;
	}
}

void			percent_print(t_format *print)
{
	if (print->minus == '\0')
	{
		print_space(print->width - 1, (print->zero == 'A' ? '0' : ' '));
		write(1, "%%", 1);
		g_check++;
	}
	else
	{
		write(1, "%%", 1);
		g_check++;
		print_space(print->width - 1, ' ');
	}
}
