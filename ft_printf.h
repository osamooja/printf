#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/includes/libft.h"

typedef struct			s_format
{
	char				minus;
	char				plus;
	char				space;
	char				hash;
	char				zero;
	char				dot;
	char				error;
	int					index;
	int					width;
	int					precision;
	char				length_mod;
	char				type;
}						t_format;

int						g_check;

int						ft_printf(const char *format, ...);
void					read_string(const char *format, va_list *ap);
int						flag_mngr(va_list *ap, t_format *print);
void					ft_print_int_s(long long int k, t_format *print);
void					ft_print_int_u(unsigned long long int k,
	t_format *print);
char					*int_print_pt2(char *res, t_format *print);
void					local_str_print(char *str);
void					pointer_print(unsigned long long int k,
	t_format *print);
int						init_print(t_format *print);
int						is_di(char *c);
int						is_ouxx(char *c);
int						define_base(char type);
long long int			get_value_s(va_list *ap, t_format *print);
unsigned long long int	get_value_u(va_list *ap, t_format *print);
long double				get_value_l_d(va_list *ap, t_format *print);
int						int_l_s(long long int k, int base);
int						int_l_u(unsigned long long int k, int base);
int						parce(const char *format,
	t_format *print, int i, va_list *ap);
void					percent_print(t_format *print);
char					*ft_itoa_base_s(long long int n,
	int precision, int base);
char					*ft_itoa_base_u(unsigned long long int n,
	int precision, int base);
char					*improve_str(char *s, char *type);
void					string_print(char *str, t_format *print);
void					string_print_minus(char *str, t_format *print, int len);
void					string_print_plus(char *str, t_format *print, int len);
void					char_print(char str, t_format *print);
void					char_print_minus(char str, t_format *print);
void					char_print_plus(char str, t_format *print);
void					long_double_print(long double x, t_format *print);

#endif
