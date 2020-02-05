/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 18:27:09 by iariss            #+#    #+#             */
/*   Updated: 2020/01/15 22:12:58 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

void	ft_printhx(unsigned int n, int *d)
{
	if (n <= 15 && n >= 10)
	{
		ft_putchar(n + 55);
		(*d)++;
	}
	if (n > 15)
	{
		ft_printhx(n / 16, d);
		ft_sb(n, d);
	}
	else if (n <= 9)
	{
		ft_putchar(n + '0');
		(*d)++;
	}
}

void	ft_sb(unsigned int n, int *d)
{
	if (n % 16 == 10)
		ft_wiz('A', d);
	if (n % 16 == 11)
		ft_wiz('B', d);
	if (n % 16 == 12)
		ft_wiz('C', d);
	if (n % 16 == 13)
		ft_wiz('D', d);
	if (n % 16 == 14)
		ft_wiz('E', d);
	if (n % 16 == 15)
		ft_wiz('F', d);
	else if (n % 16 > 15 || n % 16 < 10)
		ft_wiz((n % 16) + '0', d);
}
