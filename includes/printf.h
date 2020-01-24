/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:41:56 by damerica          #+#    #+#             */
/*   Updated: 2020/01/24 17:53:43 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H

# define PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct  s_spec
{
    int left;
    int minus;
    int plus;
    int probel;
    int nul;
    int field;
    int precision;
    char *modif;
    char conv_type;
    int negative;
    int len;
    int it_nul;
    int lat;
}               t_spec;

typedef struct s_float
{
    long long int_value;
    long double float_value;
    char *int_val_str;
    int plus_1;
    char *float_val_str;
}               t_float;

char	*ft_itoa_pf(long long n, t_spec *elem);
int     ft_intlen(long long n);
int     ft_printf(const char *format, ...);

#endif