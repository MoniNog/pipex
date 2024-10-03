/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:29:49 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 14:17:37 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_putptr(void *ptr, int *count)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	ft_putstr("0x", count);
	ft_putnbr_hex_ptr(addr, count);
}
