/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:09:47 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/03/17 21:46:03 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		description(va_list ap, const char desc);
int		ft_printf(const char *str, ...);
void	ft_putchar_fd(char c, int fd);
int		print_char(va_list ap);
int		print_str(va_list ap);
int		print_pointer(va_list ap);
int		print_int(va_list ap);
int		print_uint(unsigned int nb, char *base);
int		print_hex(va_list ap);

#endif