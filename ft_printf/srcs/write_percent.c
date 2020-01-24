/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:23:19 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:23:20 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right_prec(int *size, char *numb, char **result, t_spec *el)
{
	int i;
	int len_num;
	int copy_precision;

	copy_precision = el->precision;
	len_num = ft_strlen(numb);
	i = 0;
	while ((*size) != i)
	{
		if (len_num != 0)
		{
			(*result)[(*size) - 1] = numb[len_num - 1];
			copy_precision--;
			len_num--;
		}
		else if (copy_precision > 0)
		{
			(*result)[(*size) - 1] = '0';
			copy_precision--;
		}
		(*size)--;
	}
}

void	write_left_prec_1(char **result, char *numb, int i, int *i1)
{
	if (numb[*i1] != '\0')
	{
		(*result)[i] = numb[*i1];
		(*i1)++;
	}
}

void	write_left_prec(char **result, int *size, char *numb, t_spec *el)
{
	int i;
	int len_num;
	int copy_precision;
	int i1;

	i1 = 0;
	copy_precision = el->precision;
	len_num = ft_strlen(numb);
	i = 0;
	if (el->plus == 1 || el->negative == 1 || el->probel == 1)
		i = 1;
	while (i != (*size))
	{
		if (copy_precision > len_num)
		{
			copy_precision--;
			(*result)[i] = '0';
		}
		else
			write_left_prec_1(result, numb, i, &i1);
		i++;
	}
}

void	check_precision(char **result, int *size, t_spec *el, char *numb)
{
	int i;

	i = 0;
	if (el->minus == 1)
	{
		write_left_prec(result, size, numb, el);
	}
	else
	{
		write_right_prec(size, numb, result, el);
	}
}