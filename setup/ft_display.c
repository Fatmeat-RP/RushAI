/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:24:47 by njaros            #+#    #+#             */
/*   Updated: 2021/11/06 15:48:18 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

void	ft_display(struct s_amove **jeu, int widht, int height)
{
	int	i;
	int	j;

	i = height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < widht)
		{
			write(1, "[", 1);
			ft_putnbr_fd(jeu[i][j].x, 1);
			write(1, ", ", 2);
			ft_putnbr_fd(jeu[i][j].y, 1);
			write(1, "] = ", 4);
			ft_putnbr_fd(jeu[i][j].etats, 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
}
