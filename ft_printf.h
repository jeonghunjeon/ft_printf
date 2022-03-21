/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:09:47 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/03/21 17:46:18 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		description(va_list ap, const char desc);
int		ft_printf(const char *str, ...);
int		ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		print_char(va_list ap);
int		print_str(va_list ap);
int		print_pointer(size_t nb, char *base);
int		print_int(va_list ap);
int		print_num(unsigned int nb, char *base);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif