/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 18:40:31 by damerica          #+#    #+#             */
/*   Updated: 2019/12/15 17:04:32 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_intlen(long long n)
{
	int i;

	i = 0;
	if (n <= 0)
		i = 1;
	n = n * (-1);
	if (n < 0 && n * (-1) < 0)
		i--;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
