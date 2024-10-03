/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:14:49 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// alloue de la mémoire pour un tableau d'éléments, tous initialisés à zéro

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (nb == 0 || size == 0 || nb > (~(size_t)0 / size))
		return (NULL);
	total_size = nb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
