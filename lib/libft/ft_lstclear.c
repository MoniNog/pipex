/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:20:46 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 15:11:24 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// efface le contenu d'une perle et la libere du collier

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_lst;
	t_list	*temp_next;

	if (!lst)
		return ;
	temp_lst = *lst;
	while (temp_lst != NULL)
	{
		temp_next = temp_lst->next;
		del(temp_lst->content);
		free(temp_lst);
		temp_lst = temp_next;
	}
	*lst = NULL;
}
