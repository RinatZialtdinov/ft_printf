/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:20:17 by damerica          #+#    #+#             */
/*   Updated: 2019/11/27 17:20:24 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *ft_strjoin_one_elem(char *s1, char elem)
{
    char	*newstr;
	int		i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	newstr = (char *)malloc(sizeof(char) * (i + 2));
	if (!newstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
    newstr[i] = elem;
    newstr[i + 1] = '\0';
	return (newstr);
}

void check_flag(char **result, int *size, t_spec *elem, int number)
{
    if (elem->plus == 1)
    {
        if (number >= 0)
            result[0] = '+';
        else
            result[0] = '-';
    }
    if (elem->minus == )
}
void write_int_elem(t_spec *elem, va_list ap)
{
    int size;
    int number;
    int i;
    char *result;

    size = elem->field;
    result = (char *)malloc(sizeof(char) * (size + 1));
    number = va_arg(ap, int);
    check_flag(&result, &size, elem, number);
    check_precision(&result, &size, elem);
    check_modif(&result, &size, elem);
}

void ft_create_str(t_spec *elem, va_list ap)
{
    if (elem->conv_type == 'd' || elem->conv_type == 'i' || elem->conv_type == 'u')
    {
        write_int_elem(elem, ap);
    }
    else if (elem->conv_type == 'o')
    {;}
    else if (elem->conv_type == 'x' || elem->conv_type == 'X')
    {;}
    else if (elem->conv_type == 'c')
    {;}
    else if (elem->conv_type == 's')
    {;}
    else if (elem->conv_type == 'p')
    {;}
    else if (elem->conv_type == 'f')
    {;}
}

void ft_create_elem(const char *format, int start, int end, va_list ap)
{
    t_spec *elem;
    int i;
    int size;
    char *str;

    size = 1;
    elem = (t_spec *)malloc(sizeof(t_spec));
    elem->minus = 0;
    elem->plus = 0;
    elem->probel = 0;
    elem->nul = 0;
    elem->field = 0;
    elem->precision = 0;
    i = 0;
    while (start <= end)
    {
        while (format[start] == '+' || format[start] == '-' || format[start] == ' ' || format[start] == '0')
        {
            if (format[start] == '+')
            {
                elem->plus = 1;
            }
            if (format[start] == '-')
            {
                elem->minus = 1;
            }
            if (format[start] == ' ')
            {
                elem->probel = 1;
            }
            if (format[start] == '0')
            {
                elem->nul = 1;
            }
            start++;
        }
        // ^^^ Не закончил данную часть ^^^
        if (format[start] == '#')
        {
            elem->conv_type = (char)malloc(sizeof(char) * 1);
            elem->conv_type = format[start + 1];
            break;
        }
        while (format[start] >= '0' && format[start] <= '9')
        {
            elem->field = 10 * elem->field + (format[start] - 48);
            start++;
        }
        if (format[start] == '.')
        {
            start++;
            while (format[start] >= '0' && format[start] <= '9')
            {
                elem->precision = 10 * elem->precision + (format[start] - 48);
                start++;
            }
        }
        if (format[start] == 'h' || format[start] == 'l' || format[start] == 'L')
        {
            elem->modif = (char *)malloc(sizeof(char) * 3);
            if (format[start + 1] == 'h' || format[start + 1] == 'l')
            {
                elem->modif[0] = format[start];
                elem->modif[1] = format[start + 1];
                start = start + 2;
            }
            else
            {
                elem->modif[0] = format[start];
                start++;
            }
        }
        // ^^^ Не закончил данную часть ^^^
        elem->conv_type = (char)malloc(sizeof(char) * 2);
        elem->conv_type = format[end];
        start++;
    }
    //printf("elem->conv-type %c\n", elem->conv_type);
    //printf("elem->flag |%s|\n", elem->flag);
    //printf("elem->precision %i\n", elem->precision);
    //printf("ele->field %i\n", elem->field);
    //printf("ele->modif %s\n", elem->modif);
    ft_create_str(elem, ap);
}


int ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    int k;

    i = 0;
    va_start(ap, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            k = i;
            while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' 
            && format[i] != 'd' && format[i] != 'i' && format[i] != 'o' && 
            format[i] != 'u' && format[i] != 'x' && format[i] != 'X' && format[i] != 'f')
            {
                i++;
            }
            printf("k = %c\n i = %c\n", format[k], format[i]);
            create(format, k + 1, i, ap);
        }
        else
        {
            ft_putchar(format[i]);
        }
        i++;
    }
    ft_putchar('\n');
    va_end(ap);
    return (i);
}

int main()
{
    int a;

    a = 15;
    ft_printf("Hello% +-+-10.2ld", a);
    return (0);
}