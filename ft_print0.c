/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 18:23:40 by iariss            #+#    #+#             */
/*   Updated: 2020/01/01 15:25:37 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void	ft_print0(int n, int *d)
{
	int		i;

	i = 0;
	if (n > 0)
	{
		while (n)
		{
			ft_putchar('0');
			n--;
			(*d)++;
		}
	}
}

int		ft_stk(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		if (n <= 15 && n >= 10)
			(i)++;
		if (n > 15)
			ft_ss_stk(n, &i);
		else if (n <= 9)
			i++;
		n /= 16;
	}
	return (i);
}

void	ft_ss_stk(unsigned long long n, int *i)
{
	if (n % 16 == 10)
		(*i)++;
	if (n % 16 == 11)
		(*i)++;
	if (n % 16 == 12)
		(*i)++;
	if (n % 16 == 13)
		(*i)++;
	if (n % 16 == 14)
		(*i)++;
	if (n % 16 == 15)
		(*i)++;
	else if (n % 16 > 15 || n % 16 < 10)
		(*i)++;
}
