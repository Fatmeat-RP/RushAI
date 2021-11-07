/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_poids_feuille.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:25:12 by njaros            #+#    #+#             */
/*   Updated: 2021/11/07 18:02:35 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

int	ft_poids_feuille(struct s_amove **jeu, int x, int y, int widht, int height, int win_cond)
{
	int	i;
	int	j;

	//WIN?
	i = 0;
	j = 0;
	while (((x + i) + 1 < widht) && (jeu[y][x + 1].etats == 1))
		i++;
	while (((x + j - 1) >= 0) && (jeu[y][x + j - 1].etats == 1))
		j--;
	if ((i - j + 1) >= win_cond)
		return (1000);
	i = 0;
	j = 0;
	while (((y + i - 1) >= height) && (jeu[y + i][x].etats == 1))
		i--;
	if ((-i + 1) >= win_cond)
		return (1000);
	i = 0;
	while (((x + i + 1) < widht) && ((y + i + 1) < height) && (jeu[y + i + 1][x + i + 1].etats == 1))
		i++;
	while (((x + j - 1) >= 0) && ((y + j - 1) >= 0) && (jeu[y + j - 1][x + j - 1].etats == 1))
		j--;
	if ((i - j + 1) >= win_cond)
		return (1000);
	i = 0;
	j = 0;
	while (((x + i + 1) < widht) && ((y - i - 1) >= 0) && (jeu[y - i - 1][x + i + 1].etats == 1))
		i++;
	while (((x + j - 1) >= 0) && ((y - j + 1) < height) && (jeu[y - j + 1][x + j - 1].etats == 1))
		j--;
	if ((i - j + 1) >= win_cond)
		return (1000);
	i = 0;
	j = 0;
	//DEF
	while (((x + i) + 1 < widht) && (jeu[y][x + 1].etats == 2))
		i++;
	while (((x + j - 1) >= 0) && (jeu[y][x + j - 1].etats == 2))
		j--;
	if ((i - j + 1) >= win_cond)
		return (500);
	i = 0;
	j = 0;
	while (((y + i - 1) >= height) && (jeu[y + i][x].etats == 2))
		i--;
	if ((-i + 1) >= win_cond)
		return (500);
	i = 0;
	while (((x + i + 1) < widht) && ((y + i + 1) < height) && (jeu[y + i + 1][x + i + 1].etats == 2))
		i++;
	while (((x + j - 1) >= 0) && ((y + j - 1) >= 0) && (jeu[y + j - 1][x + j - 1].etats == 2))
		j--;
	if ((i - j + 1) >= win_cond)
		return (500);
	i = 0;
	j = 0;
	while (((x + i + 1) < widht) && ((y - i - 1) >= 0) && (jeu[y - i - 1][x + i + 1].etats == 2))
		i++;
	while (((x + j - 1) >= 0) && ((y - j + 1) < height) && (jeu[y - j + 1][x + j - 1].etats == 2))
		j--;
	if ((i - j + 1) >= win_cond)
		return (500);
	//cas neutre
	return(ft_count_win(jeu, x, y, widht, height, win_cond));
}