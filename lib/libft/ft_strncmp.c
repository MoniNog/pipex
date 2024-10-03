/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:27:51 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// compare n caracteres entre deux strings

int	ft_strncmp(const char *first, const char *second, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (first[i] != second[i] || first[i] == '\0' || second[i] == '\0')
			return ((unsigned char)first[i] - (unsigned char)second[i]);
		i++;
	}
	return (0);
}
