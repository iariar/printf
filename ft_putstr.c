/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 13:34:02 by iariss            #+#    #+#             */
/*   Updated: 2020/01/15 22:18:31 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void	ft_putstr(char *s, int *d)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
		(*d)++;
	}
}

void	ft_ball2(va_list ap, t_lolo *a, t_format *r, char *s)
{
	a->a = 0;
	r->o = 0;
	(r->flague == 1) ? r->t = r->t + 1 : 0;
	a->t ? r->t++ : 0;
	a->i++;
	a->a = a->i;
	a->j = 0;
	if (s[a->i] == '*')
	{
		r->p = va_arg(ap, int);
		a->i++;
		r->u = 1;
	}
	else if ((s[a->i] >= '0' && s[a->i] <= '9') || s[a->i] == '-')
		ft_more(s, r, a);
	if (r->n && r->p > 0)
	{
		r->w = r->p;
		r->p = 0;
	}
	if (r->n && r->p < 0)
	{
		r->w = -r->p;
		r->p = 0;
	}
}

void	ft_data(t_format *r)
{
	r->w = -r->w;
	r->flague = 1;
}

void	ft_tea(char *s, t_lolo *a, t_format *r, int n)
{
	if (s[a->i] == '-' && (s[a->i + 1] != 0))
	{
		a->i++;
		r->flague = 1;
	}
	if (a->b > 2)
	{
		a->b = a->b - 1;
		if (a->g == 1)
			a->b = a->b + 1;
	}
	a->p = ft_substr(s, n, r->t);
	if (a->p && a->p[0] == '0' && ft_strlen(a->p) > 1)
		r->j = 1;
	r->w = ft_atoi(a->p);
	a->l = ft_strlen(a->p);
	free(a->p);
	a->p = NULL;
}

void	ft_tea2(char *s, t_lolo *a, t_format *r, int n)
{
	a->t = 0;
	r->flague = 1;
	a->i++;
	if (s[a->i] >= '0' && s[a->i] <= '9')
	{
		n = a->i;
		a->o = n;
		while (s[a->i] >= '0' && s[a->i] <= '9')
		{
			a->i++;
			a->t++;
		}
		a->p = ft_substr(s, n, a->t);
		if (a->p && a->p[0] == '0' && ft_strlen(a->p) > 1)
			r->j = 1;
		a->l = ft_strlen(a->p);
		r->w = ft_atoi(a->p);
		a->t = a->t - 1;
		free(a->p);
	}
	r->z++;
}
