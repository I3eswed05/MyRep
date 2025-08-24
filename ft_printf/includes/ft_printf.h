/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialausud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:26:10 by ialausud          #+#    #+#             */
/*   Updated: 2025/08/19 22:26:14 by ialausud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

char		*ft_itoa(int n);
int			ft_print_char(va_list args);
int			ft_dispatch_format(char specifier, va_list args);
int			ft_printf(const char *format, ...);
char		*ft_itoa_base(unsigned long value, int base, int uppercase);
int			ft_print_d(va_list args);
int			ft_print_percent(void);
int			ft_print_ptr(va_list args);
int			ft_print_str(va_list args);
int			ft_print_u(va_list args);
int			ft_print_x(va_list args);
int			ft_print_upper_x(va_list args);
size_t		ft_strlen(const char *str);

#endif
