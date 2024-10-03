/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:29:49 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 14:17:22 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putnbr_hex_ptr(unsigned long nbr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_putnbr_hex_ptr(nbr / 16, count);
	ft_putchar(base[nbr % 16], count);
}
