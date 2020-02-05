/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:51:50 by iariss            #+#    #+#             */
/*   Updated: 2020/01/17 15:29:58 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

int		ft_new(t_format *r, va_list ap, t_lolo *x)
{
	t_lolo		a;
	char		*s;

	x->c = 0;
	a.i = 0;
	r->o = 1;
	r->t = 0;
	r->n = 0;
	r->c = 0;
	s = &x->lo[x->i];
	if (s[a.i])
		a.i = ft_hp(r, s, ap, &a);
	if (r->p < -1 && r->data_type == 's')
	{
		r->c = 1;
		r->p = -r->p;
	}
	return (x->i + a.i);
}

int		ft_hp(t_format *r, char *s, va_list ap, t_lolo *a)
{
	if (s[a->i] != '.' && s[a->i])
	{
		if (((s[a->i] == '-' && s[a->i + 1] == '0') || (s[a->i] == '0'
		&& s[a->i + 1] == '-')) && s[a->i + 2] == '*')
		{
			ft_no(r, a);
			ft_wn(r, a, ap);
		}
		ft_ll(s, a, r);
		(s[a->i] == '-') ? ft_flague(a, s, r) : 0;
		if (s[a->i] == '0' && s[a->i + 1] == '*')
		{
			a->i++;
			r->j = 1;
			ft_wn(r, a, ap);
		}
		if (s[a->i] == '*')
			ft_wn(r, a, ap);
		else if ((s[a->i] >= '0' && s[a->i] <= '9'))
			ft_ball(a->k, a, r, s);
	}
	(s[a->i] == '.') ? ft_ball2(ap, a, r, s) : 0;
	(ft_isdt(s[a->i]) == 1) ? ft_tt(r, s, a) : 0;
	(r->w < -1) ? ft_data(r) : 0;
	return (a->i);
}

int		ft_isdt(char c)
{
	if (!(c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == ' ' ||
		c == 'c' || c == '%'))
		return (0);
	return (1);
}

int		ft_flague(t_lolo *x, char *s, t_format *r)
{
	r->flague = 1;
	x->i++;
	while (s[x->i] == ' ')
		x->i++;
	x->g = 1;
	return (1);
}

void	ft_ball(int n, t_lolo *a, t_format *r, char *s)
{
	r->z = 0;
	n = a->i;
	a->o = a->i;
	if (r->flague == 1)
		a->o = a->i - 1;
	while (s[a->i] >= '0' && s[a->i] <= '9')
	{
		r->t++;
		a->i++;
	}
	if (s[a->i] == '.' || ft_isdt(s[a->i]) || (s[a->i] == '-' &&
	(s[a->i + 1] == '.' || ft_isdt(s[a->i + 1]))))
		ft_tea(s, a, r, n);
	else if (s[a->i] == '-' && !(s[a->i + 1] == '.') && !ft_isdt(s[a->i + 1]))
		ft_tea2(s, a, r, n);
	while (s[a->i] == ' ')
	{
		r->z++;
		a->i++;
	}
}
