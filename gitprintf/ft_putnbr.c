/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:01:27 by dgarizad          #+#    #+#             */
/*   Updated: 2022/12/13 22:23:09 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *printed);

void	ft_putnum(long nb, int *printed)
{
	if (nb / 10 != 0)
	{
		ft_putnum(nb / 10, printed);
	}
	ft_putchar((nb % 10) + 48, printed);
}

void	ft_putnbr(int nb, int *printed, char flag)
{
	long	lnb;

	if (flag == 'u')
	{
		ft_putnum((unsigned int) nb, printed);
		return ;
	}
	lnb = (long) nb;
	if (nb < 0)
	{
		lnb *= -1;
		write(1, "-", 1);
		*printed += 1;
	}
	ft_putnum(lnb, printed);
}
