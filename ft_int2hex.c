/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int2hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:25:23 by jchapell          #+#    #+#             */
/*   Updated: 2022/11/18 17:16:23 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	num_to_hex(int l, int maj)
{
	if (maj == 'x' && l > 9 && l < 16)
		l += 'a' - 10;
	else if (maj == 'X' && l > 9 && l < 16)
		l += 'A' - 10;
	else
		l += '0';
	return (l);
}

char	*ft_int2hex(size_t val, int maj)
{
	char		*res;
	size_t		val2;
	int			i;

	val2 = val;
	i = 0;
	while (val2 > 0 && i++ >= 0)
		val2 = val2 / 16;
	res = ft_calloc((i + 1) * sizeof(char), sizeof(char));
	if (!res)
		return (0);
	while (--i >= 0)
	{
		res[i] = num_to_hex((val % 16), maj);
		val = val / 16;
	}
	return (res);
}

int	ft_puthex(size_t val, char c)
{
	char	*res;
	int		rint;

	if (val > 0)
	{
		res = ft_int2hex(val, c);
		rint = ft_putstr_fd(res, 1) - 1;
		free(res);
		return (rint);
	}
	return (ft_putstr_fd("0", 1) - 1);
}
