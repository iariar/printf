/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 17:04:58 by iariss            #+#    #+#             */
/*   Updated: 2020/01/15 21:57:23 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void	ft_printp(unsigned long long n, t_format *r, int *d)
{
	int		w;
	int		p;

	w = 0;
	p = 0;
	if ((r->p == -1 && n == 0 && !r->o) || (n == 0 && r->p == 0))
	{
		w = r->w - 2;
		r->a--;
	}
	ft_condp(r, n, &w, &p);
	if ((r->j) && r->p < 0)
	{
		p = r->w - ft_stk(n) - 2;
		w = 0;
	}
	if (r->flague == 0)
		(*d) = (*d) + ft_firstp(n, w, p, r);
	else if (r->flague == 1)
		(*d) = (*d) + ft_secondp(n, w, p, r);
	else if (!r->p && !r->w && !r->flague)
	{
		ft_putstr("0x", d);
		ft_printalter(n, d);
	}
}

int		ft_firstp(unsigned long long n, int w, int p, t_format *r)
{
	int		d;

	d = 0;
	ft_printwid(w, &d);
	ft_putstr("0x", &d);
	ft_print0(p, &d);
	if (r->a)
		ft_printalter(n, &d);
	return (d);
}

int		ft_secondp(unsigned long long n, int w, int p, t_format *r)
{
	int		d;

	d = 0;
	if (r->j && !r->n && r->p <= 0)
	{
		w = p;
		p = 0;
	}
	ft_putstr("0x", &d);
	ft_print0(p, &d);
	if (r->a)
		ft_printalter(n, &d);
	ft_printwid(w, &d);
	return (d);
}

int		ft_numberlen(unsigned int nbr)
{
	long int i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr >= 10)
	{
		i++;
		nbr = nbr / 10;
	}
	if (nbr > 0)
		i++;
	return (i);
}

void	ft_condp(t_format *r, unsigned long long n, int *w, int *p)
{
	int		i;

	i = ft_stk(n);
	if (r->w > i - 2 && n)
		(*w) = r->w - i - 2;
	if (((r->w <= r->p && r->p > i) || (r->p > i && r->p == r->w)))
	{
		(*w) = 0;
		(*p) = r->p - i;
	}
	else if (r->p <= 0 && r->w > 14 && !r->n && n)
	{
		(*p) = 0;
		(*w) = r->w - i - 2;
	}
	else if (r->p < r->w && r->w > i + 2 && r->p > 0)
	{
		(*p) = r->p - i;
		if ((*p) > 0)
			(*w) = r->w - i - 2 - (*p);
		else
			(*w) = r->w - i - 2;
	}
	(n == 0 && r->w > 3 && r->p < 0 && r->o) ? (*w) = r->w - 3 : 0;
	(r->p + 2 > r->w) ? (*w) = 0 : 0;
}
