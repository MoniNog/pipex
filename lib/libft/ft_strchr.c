/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:57:53 by monoguei          #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// Recherche la première occurrence de searchedChar dans la str passée en param.

char	*ft_strchr(const char *str, int searchedChar)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)searchedChar)
			return ((char *)&str[i]);
		i++;
	}
	if (searchedChar == 0)
		return ((char *)&str[i]);
	return (NULL);
}
