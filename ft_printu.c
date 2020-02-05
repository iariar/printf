/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 17:14:07 by iariss            #+#    #+#             */
/*   Updated: 2019/12/25 17:14:09 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void	ft_printu(unsigned int n, t_format *r, int *d)
{
	char	*tmp;
	int		w;
	int		p;

	p = r->p;
	w = r->w;
	ft_condu(n, r, &w, &p);
	ft_condu2(n, r, &w, &p);
	if ((r->p == 0 || r->p == -1) && r->w && n && !r->j)
	{
		p = 0;
		w = r->w - ft_number(n);
	}
	if (r->p > ft_number(n))
		p = r->p - ft_number(n);
	if (r->p <= ft_numberlen(n) && !r->j)
		p = 0;
	if (r->flague == 0)
		(*d) = (*d) + ft_firstu(r, w, p, n);
	else if (r->flague == 1)
		(*d) = (*d) + ft_secondu(r, w, p, n);
	else if ((!r->w && !r->flague && !r->p) ||
	(!r->w && r->flague && !r->p))
		ft_putnu(n, d);
}

void	ft_putnu(unsigned int n, int *d)
{
	if (n == 2147483648)
	{
		ft_putchar('2');
		n = 147483648;
		(*d)++;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		(*d)++;
	}
	if (n >= 10)
	{
		ft_putnu(n / 10, d);
		ft_putchar(n % 10 + '0');
		(*d)++;
	}
}

int		ft_firstu(t_format *r, int w, int p, int n)
{
	int		d;

	d = 0;
	if (r->j && r->p <= 0 && p)
	{
		p = w;
		w = 0;
	}
	ft_printwid(w, &d);
	ft_print0(p, &d);
	if (r->a)
		ft_putnu(n, &d);
	return (d);
}

int		ft_secondu(t_format *r, int w, int p, int n)
{
	int		d;

	d = 0;
	if (r->j && r->p <= 0 && p)
	{
		w = p;
		p = 0;
	}
	ft_print0(p, &d);
	if (r->a)
		ft_putnu(n, &d);
	ft_printwid(w, &d);
	return (d);
}

void	ft_condu(int n, t_format *r, int *w, int *p)
{
	if (r->w && r->w > ft_numberlen(n) &&
	r->w >= r->p && r->p > ft_numberlen(n))
	{
		(*p) = r->p - ft_numberlen(n);
		(*w) = r->w - r->p;
	}
	if (r->w && r->w > ft_numberlen(n) &&
	r->w > r->p && r->p < ft_numberlen(n))
		(*w) = r->w - ft_numberlen(n);
	if (r->p > r->w && r->p > ft_numberlen(n))
	{
		(*p) = r->p - ft_numberlen(n);
		(*w) = 0;
	}
	if (r->w <= ft_numberlen(n))
		(*w) = 0;
}
