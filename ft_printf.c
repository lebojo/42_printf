/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:10:52 by jchapell          #+#    #+#             */
/*   Updated: 2022/11/18 17:34:47 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(unsigned long long num)
{
	int		l;
	char	*r;

	l = 0;
	l += write(1, "0x", 2);
	if (num == 0)
		l += write (1, "0", 1);
	r = ft_int2hex(num, 'x');
	l += ft_putstr_fd(r, 1);
	free(r);
	return (l - 1);
}

int	parse_arg(char c, va_list ap)
{
	int	l;

	l = 0;
	if (c == '%')
		l = ft_putchar_fd('%', 1) - 2;
	else if (c == 'c')
		l = ft_putchar_fd(va_arg(ap, int), 1) - 2;
	else if (c == 's')
		l = ft_putstr_fd(va_arg(ap, char *), 1) - 1;
	else if (c == 'p')
		l = ft_putaddr((unsigned long long)va_arg(ap, unsigned long long));
	else if (c == 'd' || c == 'i')
		l = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (c == 'u')
		l = ft_putunsnbr((unsigned long long)va_arg(ap, unsigned long long));
	else if (c == 'x' || c == 'X')
		l = ft_puthex(va_arg(ap, unsigned int), c);
	return (l);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = -1;
	len = 0;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i + 1] && s[i] == '%')
			len += parse_arg(s[++i], ap);
		else
			ft_putchar_fd(s[i], 1);
	}
	return (i + len);
}
