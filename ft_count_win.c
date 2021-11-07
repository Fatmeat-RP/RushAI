/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 14:11:20 by njaros            #+#    #+#             */
/*   Updated: 2021/11/07 15:09:28 by njaros           ###   ########lyon.fr   */
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
	while ((jeu[x + i][y].etats != 2) && ((x + i) < widht))
		i++;
	while ((jeu[x + j][y].etats != 2) && ((x + j) >= 0))
		j--;
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
	while ((jeu[x][y + i].etats != 2) && ((y + i) < height))
		i++;
	while ((jeu[x][y + j].etats != 2) && ((y + j) >= 0))
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
	while ((jeu[x + i][y + i].etats != 2) && ((x + i) < widht) && ((y + i) < height))
		i++;
	while ((jeu[x + j][y + j].etats != 2) && ((x + j) >= 0) && ((y + j) >= 0))
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
	while ((jeu[x + i][y - i].etats != 2) && ((x + i) < widht) && ((y - i) >= 0))
		i++;
	while ((jeu[x + j][y - j].etats != 2) && ((x + j) >= 0) && ((y - j) < height))
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