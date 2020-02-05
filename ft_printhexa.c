/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:11:14 by iariss            #+#    #+#             */
/*   Updated: 2020/01/15 22:15:42 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void	ft_printhexa(unsigned int n, int *d)
{
	if (n <= 15 && n >= 10)
	{
		ft_putchar(n + 87);
		(*d)++;
	}
	if (n > 15)
	{
		ft_printhexa(n / 16, d);
		ft_ss(n, d);
	}
	else if (n <= 9)
	{
		ft_putchar(n + '0');
		(*d)++;
	}
}

void	ft_ss(unsigned int n, int *d)
{
	if (n % 16 == 10)
		ft_wiz('a', d);
	if (n % 16 == 11)
		ft_wiz('b', d);
	if (n % 16 == 12)
		ft_wiz('c', d);
	if (n % 16 == 13)
		ft_wiz('d', d);
	if (n % 16 == 14)
		ft_wiz('e', d);
	if (n % 16 == 15)
		ft_wiz('f', d);
	else if (n % 16 > 15 || n % 16 < 10)
	{
		ft_wiz((n % 16) + '0', d);
	}
}

void	ft_wiz(char c, int *d)
{
	ft_putchar(c);
	(*d)++;
}

void	ft_no(t_format *r, t_lolo *a)
{
	r->flague = 1;
	r->j = 0;
	a->i = a->i + 2;
}
