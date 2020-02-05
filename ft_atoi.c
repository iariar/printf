/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:05:46 by iariss            #+#    #+#             */
/*   Updated: 2020/01/15 21:58:33 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c.h"

int		ft_atoi(char *str)
{
	long int	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	if (str)
	{
		if (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\n'))
			i++;
		(str[i] == '-' && str[i]) ? sign = -1 : 0;
		((str[i] == '-' || str[i] == '+') && str[i]) ? i++ : 0;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - '0');
			if (res > 2147483647 && sign == 1)
				return (-1);
			if (res > 2147483648 && sign == -1)
				return (0);
			i++;
		}
	}
	return (sign * res);
}
