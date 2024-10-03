/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:14:30 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// cherche une suite de caracteres dans une string

char	*ft_strnstr(const char *fullstr, const char *substr, size_t len)
{
	size_t	ifull;
	size_t	isub;
	size_t	sub_len;
	char	*temp_fullstr;

	ifull = 0;
	isub = 0;
	temp_fullstr = (char *)fullstr;
	sub_len = ft_strlen(substr);
	if (sub_len == 0)
		return (temp_fullstr);
	while (fullstr[ifull] != '\0' && ifull < len)
	{
		while (fullstr[ifull + isub] == substr[isub] && (ifull + isub) < len)
		{
			isub++;
			if (isub == sub_len)
				return (temp_fullstr + ifull);
		}
		isub = 0;
		ifull++;
	}
	return (NULL);
}
