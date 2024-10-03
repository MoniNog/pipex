/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:40:29 by moni              #+#    #+#             */
/*   Updated: 2024/08/09 12:04:01 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// creer une nouvelle perle

t_list	*ft_lstnew(void *content)
{
	t_list	*tab;

	if (!content)
		return (NULL);
	tab = malloc(sizeof(t_list));
	if (tab == NULL)
		return (NULL);
	tab->content = content;
	tab->next = NULL;
	return (tab);
}
