/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:51:58 by monoguei          #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// Copie n octets de src vers dest avec gestion de chevauchement.

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_p;
	const char	*src_p;

	dest_p = (char *)dest;
	src_p = (const char *)src;
	if (dest_p < src_p)
	{
		while (n > 0)
		{
			*dest_p = *src_p;
			dest_p++;
			src_p++;
			n--;
		}
	}
	dest_p = dest_p + n - 1;
	src_p = src_p + n - 1;
	while (n > 0)
	{
		*dest_p = *src_p;
		dest_p--;
		src_p--;
		n--;
	}
	return (dest);
}
