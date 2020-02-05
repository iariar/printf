/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:53:25 by iariss            #+#    #+#             */
/*   Updated: 2020/01/14 21:53:33 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void		ft_printn(int n, t_format *r, int *d, int *z)
{
	char	*tmp;
	int		w;
	int		p;

	tmp = ft_itoa(n);
	if ((*z) == 1 && n > 0 && r->p > 0)
		ft_wiz(' ', d);
	ft_condd(&tmp, r, &w, &p);
	ft_condd2(&tmp, r, &w, &p);
	ft_condd3(&tmp, r, &w, &p);
	if (((r->p > r->w && !(r->j)) || ((r->w == r->p && r->p == ft_strlen(tmp)
	&& !r->j) || (r->p > r->w && r->p > ft_strlen(tmp) && !r->j) || ((r->j)
	&& (r->p < 0) && tmp[0] != '0'))))
		w = 0;
	if (n < 0)
		(*d) = (*d) + ft_neg(p, w, tmp, r);
	else if (r->flague == 0)
		(*d) = (*d) + ft_firstd(r, w, p, tmp);
	else if (r->flague == 1)
		(*d) = (*d) + ft_secondd(r, w, p, tmp);
	else if ((!r->w && !r->flague && !r->p) || (!r->w && r->flague && !r->p))
	{
		ft_putstr(tmp, d);
		free(tmp);
	}
}

int			ft_neg(int p, int w, char *tmp, t_format *r)
{
	int d;

	d = 0;
	if (!r->j && w > 0 && p > 0)
		w = w - 1;
	if ((r->w <= 0 && r->j) || (r->p > 0 && r->p > ft_strlen(tmp) - 1))
		p = p + 1;
	if (!r->flague)
	{
		ft_printwid(w, &d);
		ft_wiz('-', &d);
		ft_print0(p, &d);
		ft_putstr(tmp + 1, &d);
	}
	else if (r->flague)
	{
		ft_wiz('-', &d);
		ft_print0(p, &d);
		ft_putstr(tmp + 1, &d);
		ft_printwid(w, &d);
	}
	free(tmp);
	return (d);
}

int			ft_firstd(t_format *r, int w, int p, char *tmp)
{
	int		i;
	int		d;

	d = 0;
	ft_printwid(w, &d);
	ft_print0(p, &d);
	i = 0;
	if (r->a)
	{
		while (tmp[i])
		{
			ft_putchar(tmp[i]);
			d++;
			i++;
		}
	}
	free(tmp);
	return (d);
}

int			ft_secondd(t_format *r, int w, int p, char *tmp)
{
	int		d;
	int		i;

	d = 0;
	if (r->j && r->p <= 0)
	{
		w = p;
		p = 0;
	}
	ft_print0(p, &d);
	i = 0;
	if (r->a)
	{
		while (tmp[i])
		{
			ft_putchar(tmp[i]);
			d++;
			i++;
		}
	}
	ft_printwid(w, &d);
	free(tmp);
	return (d);
}
