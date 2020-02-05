/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 19:54:47 by iariss            #+#    #+#             */
/*   Updated: 2020/01/15 22:09:46 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

int		ft_convert(unsigned int n)
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
			ft_ss_convert(n, &i);
		else if (n <= 9)
			i++;
		n /= 16;
	}
	return (i);
}

void	ft_ss_convert(unsigned int n, int *i)
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

void	ft_printalter(unsigned long long n, int *d)
{
	if (n <= 15 && n >= 10)
	{
		ft_putchar(n + 87);
		(*d)++;
	}
	if (n > 15)
	{
		ft_printalter(n / 16, d);
		ft_ssalter(n, d);
	}
	else if (n <= 9)
	{
		ft_putchar(n + '0');
		(*d)++;
	}
}

void	ft_ssalter(unsigned long long n, int *d)
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
		ft_wiz((n % 16) + '0', d);
}
