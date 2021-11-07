/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:11:20 by njaros            #+#    #+#             */
/*   Updated: 2021/11/07 17:34:50 by njaros           ###   ########lyon.fr   */
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
	while (((x + i + 1) < widht) && (jeu[y][x + i].etats != 2) && (i + 1 < win_cond))
		i++;
	while (((x + j - 1) >= 0) && (jeu[y][x + j - 1].etats != 2) && (-j + 1 < win_cond))
		j--;
	if ((i - j + 1) >= win_cond)
	{
		count = count + (i - j + 1 - win_cond) + 2;
		while (j <= i)
		{
			if (jeu[y][x + j].etats == 1)
				count++;
			j++;
		}
	}
	//on enchaine avec le test en colonne
	//
	//
	i = 0;
	j = 0;
	while (((y + i + 1) < height) && (jeu[y + i + 1][x].etats != 2) && (i + 1 < win_cond))
		i++;
	while (((y + j - 1) >= 0) && (jeu[y + j - 1][x].etats != 2) && (-j + 1 < win_cond))
		j--;
	if ((i - j + 1) >= win_cond)
	{
		count = count + (i - j + 1 - win_cond) + 1;
		while (j <= i)
		{
			if (jeu[y + j][x].etats == 1)
				count++;
			j++;
		}
	}
	// test de la diagonale à dérivé positive
	//
	//
	i = 0;
	j = 0;
	while (((x + i + 1) < widht) && ((y + i + 1) < height) && (jeu[y + i + 1][x + i + 1].etats != 2) && (i + 1 < win_cond))
		i++;
	while (((x + j - 1) >= 0) && ((y + j - 1) >= 0) && (jeu[y + j - 1][x + j - 1].etats != 2) && (-j + 1 < win_cond))
		j--;
	if ((i - j + 1) >= win_cond)
	{
		count = count + (i - j + 1 - win_cond) + 2;
		while (j <= i)
		{
			if (jeu[y + j][x + j].etats == 1)
				count++;
			j++;
		}
	}
	// teste de la diagonale à dérivé négative
	//
	//
	i = 0;
	j = 0;
	while (((x + i + 1) < widht) && ((y - i - 1) >= 0) && (jeu[y - i - 1][x + i + 1].etats != 2) && (i + 1 < win_cond))
		i++;
	while (((x + j - 1) >= 0) && ((y - j + 1) < height) && (jeu[y - j + 1][x + j - 1].etats != 2) && (-j + 1 < win_cond))
		j--;
	if ((i - j + 1) >= win_cond)
	{
		count = count + (i - j + 1 - win_cond) + 2;
		while (j <= i)
		{
			if (jeu[y - j][x + j].etats == 1)
				count++;
			j++;
		}
	}
	return (count);
}