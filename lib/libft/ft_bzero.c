/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:12:12 by monoguei          #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// met à zéro ('/0') les n premiers bytes du bloc de mémoire pointé par s

void	*ft_memset(void *ptr, int value, size_t count);

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>
int	main(void)
{
	void	*s = malloc (sizeof"lily");
	size_t	n = 4;
	printf("%s", ft_bzero(s, n));
	return (0);
}*/