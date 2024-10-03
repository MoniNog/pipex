/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:07:57 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// creer une deuxieme string ou sont supprimes les caracteres spécifiés au 
// début et à la fin d'une string 

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s2;
	size_t	i;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	s2 = malloc((end - start + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		s2[i] = s1[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
