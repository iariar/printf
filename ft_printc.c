/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 15:09:35 by iariss            #+#    #+#             */
/*   Updated: 2020/01/01 15:35:40 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void	ft_printc(char c, t_format *r, int *d)
{
	int		p;
	int		w;

	w = r->w;
	p = 0;
	ft_condc(r, &p, &w, c);
	if (r->flague == 1)
	{
		if (r->j)
		{
			w = p + 1;
			p = 0;
		}
		ft_first(d, p, c, w);
	}
	else if (r->flague == 0)
		ft_second(d, p, c, w);
	else if (!r->w)
		ft_wiz(c, d);
}

void	ft_first(int *d, int p, char c, int w)
{
	ft_print0(p, d);
	ft_wiz(c, d);
	ft_printwid(w - 1, d);
}

void	ft_second(int *d, int p, char c, int w)
{
	if (w > 0)
		ft_printwid(w - 1, d);
	ft_print0(p, d);
	ft_wiz(c, d);
}

void	ft_condc(t_format *r, int *p, int *w, char c)
{
	if (r->j)
	{
		*p = r->w - 1;
		*w = 0;
	}
	if (c == '%')
	{
		if ((r->j) && !r->flague)
		{
			*p = r->w - 1;
			r->w = 0;
		}
	}
}
