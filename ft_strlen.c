/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:36:57 by iariss            #+#    #+#             */
/*   Updated: 2019/12/14 18:40:18 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

size_t		ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int			ft_strchr(const char *s, int c, t_format *r)
{
	char	*str;

	str = ((char*)s);
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (0);
		}
		str++;
	}
	r->n = 1;
	return (1);
}

void		ft_more(char *s, t_format *r, t_lolo *a)
{
	while ((s[a->i] >= '0' && s[a->i] <= '9') || s[a->i] == '-')
	{
		a->i++;
		a->j++;
	}
	ft_strchr(s + a->a, '-', r);
	a->p = ft_substr(s, a->a, a->j);
	r->p = ft_atoi(a->p);
	a->i = a->a + a->j;
	free(a->p);
	a->p = NULL;
	if (r->p < 0)
		r->flague = 1;
	while (s[a->i] == ' ')
		a->i++;
}

void		ft_tt(t_format *r, char *s, t_lolo *a)
{
	r->data_type = s[a->i];
	a->i++;
}

void		ft_ll(char *s, t_lolo *a, t_format *r)
{
	while (s && (s[a->i] == '0' || s[a->i] == '-') && (s[a->i + 1] == '0' ||
	s[a->i + 1] == '-') && s[a->i + 2] != '.' && !(s[a->i + 2] > '0' &&
	s[a->i + 2] < '9'))
	{
		if (s[a->i] == '-' && s[a->i + 1] == '-')
		{
			a->i = a->i + 2;
			r->flague = 1;
			a->b = a->b + 2;
		}
		if (s[a->i] == '-' && s[a->i + 1] == '0')
		{
			a->i = a->i + 2;
			r->flague = 1;
			a->b = a->b + 2;
		}
		if (s[a->i] == '0' && s[a->i + 1] == '-')
		{
			a->i = a->i + 2;
			r->flague = 1;
			a->b = a->b + 2;
		}
		a->i++;
	}
}
