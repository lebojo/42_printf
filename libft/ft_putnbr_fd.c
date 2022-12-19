/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 02:09:29 by jchapell          #+#    #+#             */
/*   Updated: 2022/11/18 16:50:18 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen(int n, int neg)
{
	int	i;

	i = -1;
	if (n == -2147483648)
	{
		n = 214748364;
		i += 2;
	}
	if (neg == 1)
		i++;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putunsnbr(unsigned int n)
{
	int	i;

	i = -1;
	if (n >= 10)
	{
		ft_putunsnbr(n / 10);
		ft_putunsnbr(n % 10);
	}
	else
	{
		ft_putchar_fd(n + 48, 1);
	}
	while (n > 9 && ++i >= 0)
		n = n / 10;
	return (i);
}

int	printnbr(int n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + 48, fd);
	}
	return (n);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	neg;

	neg = 0;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
		neg = 1;
	}
	else
	{
		printnbr(n, fd);
	}
	return (intlen(n, neg));
}
