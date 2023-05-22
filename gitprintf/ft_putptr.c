/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:38:48 by dgarizad          #+#    #+#             */
/*   Updated: 2022/12/13 23:31:29 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *printed);

void	ft_puthex(unsigned long long nb, int *printed, int uppcase)
{
	if (nb / 16 != 0)
	{
		ft_puthex(nb / 16, printed, uppcase);
	}
	if (nb % 16 <= 9)
		ft_putchar((nb % 16) + 48, printed);
	else
		ft_putchar((nb % 16) + uppcase, printed);
}

void	ft_putptr(unsigned long long ptr, int *printed, const char c)
{
	int	uppcase;

	uppcase = 87;
	if (c == 'p')
	{
		write(1, "0x", 2);
		*printed += 2;
		ft_puthex(ptr, printed, uppcase);
	}
	if (c == 'X')
	{
		uppcase -= 32;
		ft_puthex((unsigned int)ptr, printed, uppcase);
	}
	if (c == 'x')
	{
		ft_puthex((unsigned int)ptr, printed, uppcase);
	}
}
