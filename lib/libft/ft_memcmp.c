/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:39:30 by monoguei          #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// Compare les n premiers octets entre s1 et s2. 
// Retourne 0 si identiques, un nombre négatif ou positif sinon.

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;

	ptr_s1 = (const unsigned char *)s1;
	ptr_s2 = (const unsigned char *)s2;
	while (n > 0)
	{
		if (*ptr_s1 == *ptr_s2)
		{
			ptr_s1++;
			ptr_s2++;
			n--;
		}
		else
			return (*ptr_s1 - *ptr_s2);
	}
	return (0);
}
