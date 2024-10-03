/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_xup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:29:49 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 14:17:37 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putnbr_hex_xup(int nb, int *count)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nb >= 16)
		ft_putnbr_hex_xup(nb / 16, count);
	ft_putchar(base[nb % 16], count);
}
