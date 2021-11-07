/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:11:20 by njaros            #+#    #+#             */
/*   Updated: 2021/11/07 16:29:36 by acarle-m         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

int	ft_count_win(struct s_amove **jeu, int x, int y, int widht, int height, int win_cond)
{
	int count;
	int	i;
	int	j;

	count = 0;
	//on commence par le test en ligne
	//
	//
	i = 0;
	j = 0;
	while (((x + i) + 1 < widht) && (jeu[x + i + 1][y].etats != 2) && (i + 1 < win_cond))
	{
		i++;
		ft_putnbr_fd(i, 1);
		ft_putchar_fd('\t', 1);
		ft_putnbr_fd(jeu[x + i][y].etats, 1);
		ft_putchar_fd('\n', 1);
	}
	while (((x + j - 1) >= 0) && (jeu[x + j - 1][y].etats != 2) && (-j + 1 < win_cond))
	{
		j--;
		ft_putnbr_fd(j, 1);
		ft_putchar_fd('\n', 1);
	}
	if ((i - j + 1) >= win_cond)
	{
		count = count + (i - j + 1 - win_cond) + 2;
		while (j <= i)
		{
			if (jeu[x + j][y].etats == 1)
				count++;
			j++;
		}
	}
	//on enchaine avec le test en colonne
	//
	//
	i = 0;
	j = 0;
	while (((y + i + 1) < height) && (jeu[x][y + i + 1].etats != 2) && (i + 1 < win_cond))
		i++;
	while (((y + j - 1) >= 0) && (jeu[x][y + j - 1].etats != 2) && (-j + 1 < win_cond))
		j--;
	if ((i - j + 1) >= win_cond)
	{
		count = count + (i - j + 1 - win_cond) + 1;
		while (j <= i)
		{
			if (jeu[x][y + j].etats == 1)
				count++;
			j++;
		}
	}
	// test de la diagonale à dérivé positive
	//
	//
	i = 0;
	j = 0;
	while (((x + i + 1) < widht) && ((y + i + 1) < height) && (jeu[x + i + 1][y + i + 1].etats != 2) && (i + 1 < win_cond))
		i++;
	while (((x + j - 1) >= 0) && ((y + j - 1) >= 0) && (jeu[x + j - 1][y + j - 1].etats != 2) && (-j + 1 < win_cond))
		j--;
	if ((i - j + 1) >= win_cond)
	{
		count = count + (i - j + 1 - win_cond) + 2;
		while (j <= i)
		{
			if (jeu[x + j][y + j].etats == 1)
				count++;
			j++;
		}
	}
	// teste de la diagonale à dérivé négative
	//
	//
	i = 0;
	j = 0;
	while (((x + i + 1) < widht) && ((y - i - 1) >= 0) && (jeu[x + i + 1][y - i - 1].etats != 2) && (i + 1 < win_cond))
		i++;
	while (((x + j - 1) >= 0) && ((y - j + 1) < height) && (jeu[x + j - 1][y - j + 1].etats != 2) && (-j + 1 < win_cond))
		j--;
	if ((i - j + 1) >= win_cond)
	{
		count = count + (i - j + 1 - win_cond) + 2;
		while (j <= i)
		{
			if (jeu[x + j][y - j].etats == 1)
				count++;
			j++;
		}
	}
	return (count);
}
