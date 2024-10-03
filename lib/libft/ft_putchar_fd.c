/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:18:19 by moni              #+#    #+#             */
/*   Updated: 2024/05/07 14:13:47 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// affiche a tel endroit (fd) un caractere 

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int main(void)
{
    // Voici où notre héroïque caractère 'a' prend la scène du terminal.
    ft_putchar_fd('a', 1);
    // Et tada! Un 'a' sauvage apparaît! 😄🎉
    return (0);
}*/