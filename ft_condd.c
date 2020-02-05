/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:19:33 by iariss            #+#    #+#             */
/*   Updated: 2020/01/19 15:19:34 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void			ft_condd(char **tmp, t_format *r, int *w, int *p)
{
	(*w) = r->w;
	(*p) = r->p;
	if (r->flague && r->w == 0)
		r->w = -1;
	if ((r->w && r->w > ft_strlen(*tmp) && r->w >= r->p && r->p > 0 &&
	r->p > ft_strlen(*tmp) && *tmp[0] != '0') || ((r->w > ft_strlen(*tmp) &&
	r->p <= ft_strlen(*tmp) && *tmp[0] != '0') && r->p > 0))
		(*w) = r->w - r->p;
	if ((r->w && r->w > ft_strlen(*tmp) && r->w > r->p
	&& r->p < ft_strlen(*tmp) && *tmp[0] != 0) ||
	((r->p == -1 && r->w && *tmp[0] != 0)))
		(*w) = r->w - ft_strlen(*tmp);
	if ((r->p > r->w && r->p > ft_strlen(*tmp)) ||
	(r->w && r->w > ft_strlen(*tmp) && r->w >= r->p
	&& r->p > ft_strlen(*tmp)) || ((!r->w && r->p &&
	r->p > ft_strlen(*tmp)) || (r->p >= ft_strlen(*tmp)) ||
	(r->p > ft_strlen(*tmp) - 1 && *tmp[0] == '-' && !r->j)))
		(*p) = r->p - ft_strlen(*tmp);
	if ((*tmp[0] == '0' && (r->p == 0) && !(r->j)) || (*tmp[0] == '0'
	&& (r->p == 0) && (r->j)))
	{
		(*w) = r->w;
		**tmp = '\0';
	}
}

void			ft_condd2(char **tmp, t_format *r, int *w, int *p)
{
	if ((r->j) && (*tmp[0] == '0' && ft_strlen(*tmp) == 1) && r->p <= 0)
	{
		(*p) = r->w;
		(*w) = 0;
		(!r->u) ? r->a-- : 0;
		(r->u) ? (*p) = r->w - 1 : 0;
	}
	if (r->j == 1 && *tmp[0] != '0' && !r->n)
	{
		(*p) = r->w - ft_strlen(*tmp);
		if (!r->p || (r->p == 1 && r->w == 1) || (r->w <= ft_strlen(*tmp)))
			(*w) = 0;
		else if (r->w > 0 && r->p > 0)
		{
			(*p) = r->p - ft_strlen(*tmp);
			((*p) > 0 && r->p > 0) ? (*w) = r->w - ft_strlen(*tmp) - (*p) : 0;
			if (*tmp[0] == '-' && (*p) > 0)
				(*w) = r->w - ft_strlen(*tmp) - (*p) - 1;
		}
	}
}

void			ft_condd3(char **tmp, t_format *r, int *w, int *p)
{
	if (((r->p == -1 && r->w && *tmp[0] != 0) || (r->p <= ft_strlen(*tmp) &&
	(*tmp[0] == '0' || *tmp[0] == '-')) || (r->w == r->p &&
	r->p == ft_strlen(*tmp))) && !r->j)
		(*p) = 0;
	if (r->w <= ft_strlen(*tmp) && r->p < 0 && !(r->j))
		(*w) = r->w - ft_strlen(*tmp);
	if (r->p <= ft_strlen(*tmp) && r->w <= ft_strlen(*tmp) && (!r->j))
	{
		(*w) = 0;
		(*p) = 0;
	}
	if (!r->o && (*tmp[0] == '0' && ft_strlen(*tmp) == 1) && r->p == -1)
	{
		r->w = r->w + 1;
		r->a--;
	}
	(*tmp[0] == '0' && r->w == 1) ? (*w) = r->w - 1 : 0;
	if (r->w > ft_strlen(*tmp) && !(*tmp[0] == '0' && ft_strlen(*tmp) == 1)
	&& r->p <= 0)
		(*w) = r->w - ft_strlen(*tmp);
	(*tmp[0] == '0' && r->w == 1) ? (*w) = r->w - 1 : 0;
	if (r->w > r->p && r->p > ft_strlen(*tmp) && r->p > 0)
		(*w) = r->w - r->p;
	(r->p <= ft_strlen(*tmp)) ? (*p) = 0 : 0;
}
