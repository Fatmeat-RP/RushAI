/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:24:47 by njaros            #+#    #+#             */
/*   Updated: 2021/11/07 16:04:11 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

void	ft_display(struct s_amove **jeu, int widht, int height)
{
	int	i;
	int	j;

	i = widht - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < height)
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
