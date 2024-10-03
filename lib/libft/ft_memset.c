/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:55:03 by monoguei          #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// remplit les n premiers octets de la mémoire pointée par s avec l'octet c

void	*ft_memset(void *ptr, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (count > i)
	{
		((char *)ptr)[i] = value;
		i++;
	}
	return (ptr);
}
