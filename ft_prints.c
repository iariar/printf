/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:03:15 by iariss            #+#    #+#             */
/*   Updated: 2019/12/22 21:18:59 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void	ft_prints(char *s, t_format *r, int *d)
{
	int		n;
	int		i;
	int		l;
	int		x;
	int		o;

	l = ft_strlen(s);
	i = 0;
	n = r->w;
	x = 0;
	if (r->c && r->p < ft_strlen(s))
		r->p = ft_strlen(s);
	if (r->j && (r->p == -1 || r->p == 0) && !r->flague && s)
	{
		x = r->w - ft_strlen(s);
		n = 0;
	}
	ft_conds(r, &x, &n, s);
	ft_conds2(r, &x, &n, s);
	if (r->flague == 0 && (r->w || r->p >= 0))
		(*d) = (*d) + ft_firsts(s, r->p, x, n);
	else if (r->flague == 1)
		(*d) = (*d) + ft_seconds(s, r->p, x, n);
	else if (r->p <= 0 && !r->w && !r->flague)
		ft_putstr(s, d);
}

int		ft_firsts(char *s, int p, int x, int n)
{
	int d;

	d = 0;
	ft_printwid(n, &d);
	ft_print0(x, &d);
	if (s && p > 0)
	{
		while (p && *s)
		{
			ft_wiz(*s, &d);
			s++;
			p--;
		}
	}
	return (d);
}

int		ft_seconds(char *s, int p, int x, int n)
{
	int d;

	d = 0;
	if (x)
	{
		n = x;
		x = 0;
	}
	ft_print0(x, &d);
	if (p > 0)
	{
		while (p > 0 && *s)
		{
			ft_wiz(*s, &d);
			s++;
			p--;
		}
	}
	ft_printwid(n, &d);
	return (d);
}

void	ft_conds(t_format *r, int *x, int *n, char *s)
{
	if (r->p == -1 && !(r->j) && r->o)
		r->p = ft_strlen(s);
	if (r->p == 0 && !(r->j))
		r->p = 0;
	if (r->p < r->w && r->p > 0 &&
	r->p >= ft_strlen(s) && r->w > ft_strlen(s) && !(r->j))
	{
		(*n) = r->w - ft_strlen(s);
		r->p = ft_strlen(s);
	}
	if (r->p > ft_strlen(s) && r->p > 0 && !(r->j))
	{
		r->p = ft_strlen(s);
		(*n) = r->w - ft_strlen(s);
	}
	if (r->w < r->p && r->w > 0 && !(r->j) && r->p > ft_strlen(s))
	{
		r->p = ft_strlen(s);
		(*n) = r->w - ft_strlen(s);
	}
	(r->w < ft_strlen(s) && r->p == -1 && !(r->j)) ? (*n) = 0 : 0;
}

void	ft_conds2(t_format *r, int *x, int *n, char *s)
{
	if (r->p > r->w && r->w > 0 && r->p > ft_strlen(s) && !(r->j))
	{
		(*n) = 0;
		r->p = r->p;
	}
	(r->p < ft_strlen(s) && r->p && !r->w && !(r->j)) ? r->p = r->p : 0;
	if (r->w > ft_strlen(s) && (r->p < r->w) &&
	r->p < ft_strlen(s) && !(r->j))
		(*n) = r->w - r->p;
	else if (r->w > ft_strlen(s) && (r->p < r->w)
	&& r->p > ft_strlen(s) && !r->j)
		(*n) = r->w - ft_strlen(s);
	if (r->j != 0 && r->w)
	{
		(*x) = r->w - ft_strlen(s);
		if (r->p < ft_strlen(s))
			(*x) = r->w - r->p;
		(*n) = 0;
	}
	(r->w > r->p && r->p < ft_strlen(s) && r->p <= 0) ? (*n) = r->w : 0;
	(r->p == -1 && !r->o && r->w > ft_strlen(s)) ? (*n) = r->w : 0;
	(r->p < ft_strlen(s) && r->w > r->p && !r->j) ? (*n) = r->w - r->p : 0;
	if ((r->p < ft_strlen(s) && r->w <= r->p) || ((r->p == ft_strlen(s))
	&& r->w <= ft_strlen(s)))
		(*n) = 0;
}
