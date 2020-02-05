/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:17:34 by iariss            #+#    #+#             */
/*   Updated: 2019/12/26 15:30:35 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void	ft_printx(unsigned int n, t_format *r, int *d)
{
	int		w;
	int		p;

	w = r->w;
	p = r->p;
	if (!r->o && n == 0 && r->p == -1)
	{
		r->w = r->w + 1;
		r->a--;
	}
	ft_condx(r, n, &w, &p);
	if (r->p <= ft_convert(n) && !(r->j) && n)
	{
		(r->w > ft_convert(n)) ? w = r->w - ft_convert(n) : 0;
		(r->w <= ft_convert(n)) ? w = 0 : 0;
		p = 0;
	}
	if (r->flague == 0)
		(*d) = (*d) + ft_firstx(w, p, n, r);
	else if (r->flague == 1)
		(*d) = (*d) + ft_secondx(w, p, n, r);
	else if ((!r->w && !r->flague && !r->p) ||
	(!r->w && r->flague && !r->p))
		ft_printhexa(n, d);
}

int		ft_firstx(int w, int p, int n, t_format *r)
{
	int		d;

	d = 0;
	ft_printwid(w, &d);
	ft_print0(p, &d);
	if (r->a)
	{
		if (r->data_type == 'x')
			ft_printhexa(n, &d);
		if (r->data_type == 'X')
			ft_printhx(n, &d);
	}
	return (d);
}

int		ft_secondx(int w, int p, int n, t_format *r)
{
	int		d;

	d = 0;
	if (r->j && !r->p)
	{
		w = p;
		p = 0;
	}
	ft_print0(p, &d);
	if (r->a)
	{
		if (r->data_type == 'x')
			ft_printhexa(n, &d);
		if (r->data_type == 'X')
			ft_printhx(n, &d);
	}
	ft_printwid(w, &d);
	return (d);
}

void	ft_condx(t_format *r, int n, int *w, int *p)
{
	if (r->w && r->w > ft_convert(n) &&
	r->w >= r->p && r->p > ft_convert(n))
	{
		(*p) = r->p - ft_convert(n);
		(*w) = r->w - r->p;
	}
	if (r->w && r->w > ft_convert(n) &&
	r->w > r->p && r->p < ft_convert(n) && n)
		(*w) = r->w - ft_convert(n);
	if (r->p > r->w && r->p > ft_convert(n) && r->w > 0)
		(*p) = r->p - ft_convert(n);
	if ((!r->w || r->w == -1) && r->p &&
	r->p > ft_convert(n))
		(*p) = r->p - ft_convert(n);
	if (n == 0 && r->p == 0)
		r->a--;
	if (r->p < r->w && (r->j) && r->p <= 0)
	{
		(*p) = r->w - ft_convert(n);
		(*w) = 0;
		r->a++;
	}
	(r->p > r->w && r->p > ft_convert(n)) ? (*w) = 0 : 0;
	if (n == 0 && r->w > ft_convert(n) && r->p <= 0 && !r->u)
		(*w) = r->w - 1;
}
