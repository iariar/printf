/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:33:34 by iariss            #+#    #+#             */
/*   Updated: 2019/12/31 18:31:33 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_H
# define C_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_lolo
{
	int				i;
	int				j;
	char			*lo;
	char			*c;
	int				n;
	unsigned int	t;
	char			*p;
	int				k;
	int				l;
	int				b;
	int				m;
	int				z;
	int				w;
	int				o;
	char			*h;
	int				d;
	int				a;
	va_list			ap;
	int				g;
}				t_lolo;

typedef struct	s_format
{
	int			flague;
	int			w;
	int			p;
	char		data_type;
	int			j;
	int			pr;
	int			a;
	int			n;
	int			t;
	int			o;
	int			b;
	int			c;
	int			u;
	int			z;
}				t_format;

void			ft_putchar(char c);
void			printx(int n);
void			ft_ss(unsigned int n, int *d);
int				ft_printf(const char *format, ...);
void			printcod(char c);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_atoi(char *str);
size_t			ft_strlen(const char *str);
void			ft_prints(char *s, t_format *r, int *d);
void			ft_printc(char	c, t_format *r, int *d);
void			ft_printwid(int n, int *d);
size_t			ft_strlen(const char *str);
void			ft_printcod(char c);
void			ft_printn(int n, t_format *r, int *d, int *z);
void			ft_printhexa(unsigned int n, int *d);
void			ft_printp(unsigned long long n, t_format *r, int *d);
void			ft_print0(int n, int *d);
int				ft_numberlen(unsigned int nbr);
int				ft_number(long long nbr);
void			ft_putstr(char *s, int *d);
char			*ft_itoa(int n);
int				ftt_number(long long nbr);
void			ft_printu(unsigned int n, t_format *r, int *d);
void			ft_printx(unsigned int n, t_format *r, int *d);
int				ft_convert(unsigned int n);
void			ft_printhx(unsigned int n, int *d);
void			ft_sb(unsigned int n, int *d);
void			ft_putnu(unsigned int n, int *d);
int				ft_small(t_format *r, va_list ap, t_lolo *x, int z);
int				ft_box(int i, t_format r, int *d);
int				ft_flague(t_lolo *x, char *s, t_format *r);
void			ft_wn(t_format *r, t_lolo *x, va_list ap);
int				ft_isdt(char c);
void			ft_whatever(char *s, t_lolo *x, t_format *r, va_list ap);
void			ft_ss_convert(unsigned int n, int *i);
void			ft_wiz(char c, int *d);
void			ft_redirect(t_format *r, va_list ap, int *d, int *z);
int				ft_hp(t_format *r, char *s, va_list ap, t_lolo *a);
void			ft_first(int *d, int p, char c, int w);
void			ft_second(int *d, int p, char c, int w);
void			ft_condc(t_format *r, int *p, int *w, char c);
int				ft_firsts(char *s, int p, int x, int n);
int				ft_seconds(char *s, int p, int x, int n);
void			ft_conds(t_format *r, int *x, int *n, char *s);
void			ft_conds2(t_format *r, int *x, int *n, char *s);
int				ft_neg(int p, int w, char *tmp, t_format *r);
void			ft_condd(char **tmp, t_format *r, int *w, int *p);
int				ft_firstd(t_format *r, int w, int p, char *tmp);
int				ft_secondd(t_format *r, int w, int p, char *tmp);
void			ft_condd2(char **tmp, t_format *r, int *w, int *p);
int				ft_firstu(t_format *r, int w, int p, int n);
int				ft_secondu(t_format *r, int w, int p, int n);
void			ft_condu(int n, t_format *r, int *w, int *p);
void			ft_condu2(int n, t_format *r, int *w, int *p);
int				ft_firstx(int w, int p, int n, t_format *r);
int				ft_secondx(int w, int p, int n, t_format *r);
void			ft_condx(t_format *r, int n, int *w, int *p);
void			ft_printalter(unsigned long long n, int *d);
void			ft_ssalter(unsigned long long n, int *d);
int				ft_firstp(unsigned long long n, int w, int p, t_format *r);
int				ft_secondp(unsigned long long n, int w, int p, t_format *r);
void			ft_condp(t_format *r, unsigned long long n, int *w, int *p);
int				ft_new(t_format *r, va_list ap, t_lolo *x);
void			ft_ss_stk(unsigned long long n, int *i);
int				ft_stk(unsigned long long n);
void			ft_condd3(char **tmp, t_format *r, int *w, int *p);
void			ft_ball(int n, t_lolo *a, t_format *r, char *s);
void			ft_ball2(va_list ap, t_lolo *a, t_format *r, char *s);
void			ft_data(t_format *r);
void			ft_tea(char *s, t_lolo *a, t_format *r, int n);
void			ft_tea2(char *s, t_lolo *a, t_format *r, int n);
int				ft_strchr(const char *s, int c, t_format *r);
void			ft_more(char *s, t_format *r, t_lolo *a);
void			ft_tt(t_format *r, char *s, t_lolo *a);
void			ft_ll(char *s, t_lolo *a, t_format *r);
void			ft_rest(t_lolo *x, t_format *r);
void			ft_init(t_format *r, t_lolo *x);
void			ft_no(t_format *r, t_lolo *a);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
