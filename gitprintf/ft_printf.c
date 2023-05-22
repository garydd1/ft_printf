/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:59:13 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/30 20:33:08 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c, int *printed)
{
	write(1, &c, 1);
	*printed += 1;
}

void	ft_putstr(char *str, int *printed)
{
	int	index;

	if (!str)
	{
		write(1, "(null)", 6);
		*printed += 6;
		return ;
	}
	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index], printed);
		index++;
	}
}

void	ft_get_type(const char c, va_list ap, int *printed)
{
	if (c == '%')
		ft_putchar('%', printed);
	if (c == 'c')
		ft_putchar(va_arg(ap, int), printed);
	if (c == 's')
		ft_putstr(0, printed);
	if (c == 'p' || c == 'x' || c == 'X')
		ft_putptr(va_arg(ap, unsigned long long), printed, c);
	if (c == 'd' || c == 'i' || c == 'u')
		ft_putnbr(va_arg(ap, int), printed, c);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		printed;

	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	printed = 0;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			ft_get_type(s[i], ap, &printed);
		}
		else
			ft_putchar(s[i], &printed);
		i++;
	}
	va_end(ap);
	return (printed);
}

int	main(void)
{
	int i;
	int *ptr;
	char	name[]= "ismaé";

	i = 4;
	ptr = &i;
	i=ft_printf("-%c", 'c');
	printf(".%c", 'c');
	printf("\ni my name is:'%s' and i have '%p' dogs", name ,  &i, k , str);
	return 0;
}
