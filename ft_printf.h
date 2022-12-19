/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:10:48 by jchapell          #+#    #+#             */
/*   Updated: 2022/11/18 17:17:03 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include "stdarg.h"

int		ft_printf(const char *s, ...);
char	*ft_int2hex(size_t val, int maj);
char	num_to_hex(int l, int maj);
int		ft_puthex(size_t val, char c);

#endif
