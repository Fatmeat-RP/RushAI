/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:02:09 by njaros            #+#    #+#             */
/*   Updated: 2021/11/07 15:13:02 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

int	ft_minimax(struct s_amove **jeu_sim, int x, int y, int widht, int height, int depht, int joueur)
{
	int i;
	int value;
	int	played;

	played = 0;
	value = 0;
	i = 0;
	if (depht == 0)
		return ft_count_win(jeu_sim, x, y, widht, height, 4);
	if (y == -1)
		return (0);
	if (joueur == 1)
	{
		while (i <= widht)
		{
			played = ft_add_token(jeu_sim, i, joueur, widht, height);
			value = ft_max(value, ft_minimax(jeu_sim, i, played, widht, height, depht - 1, 2));
			jeu_sim[i][played].etats = 0;
			i++;
		}
	}
	//je pouvais faire en une seule boucle, mais c'est plus lisible ainsi pour le deboggage
	if (joueur == 2)
	{
		while (i <= widht)
		{
			played = ft_add_token(jeu_sim, i, joueur, widht, height);
			value = ft_min(value, ft_minimax(jeu_sim, i, played, widht, height, depht - 1, 1));
			jeu_sim[i][played].etats = 0;
			i++;
		}
	}
	return (value);
}
