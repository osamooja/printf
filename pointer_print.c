#include "ft_printf.h"

void		pointer_print(unsigned long long int k, t_format *print)
{
	if (k == 0)
	{
		print->type = 's';
		if (print->dot == 'A' && print->dot == 'A' && print->precision < 2)
		{
			print->precision = 2;
			string_print("0x0", print);
		}
		else
		{
			string_print("0x0", print);
			while (print->dot == 'A' && print->precision > 1)
			{
				print->precision--;
				write(1, "0", 1);
				g_check++;
			}
		}
	}
	else
	{
		print->hash = 'A';
		print->type = 'x';
		ft_print_int_u(k, print);
	}
}
