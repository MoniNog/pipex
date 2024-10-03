/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:22:01 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// copie n caracteres

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (src[i] != 0 && size > 0)
	{
		dest[i] = src[i];
		i++;
		size--;
	}
	dest[i] = 0;
	return (dest);
}
