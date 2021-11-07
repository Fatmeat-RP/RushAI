/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:03:08 by njaros            #+#    #+#             */
/*   Updated: 2021/11/07 10:31:31 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

int	ft_add_token(struct s_amove **jeu, int column, int side, int widht, int height)
{
	int	i;

	if ((column < 0) || (column >= widht) || (jeu[height - 1][column].etats != 0))
		return (-1);
	i = 0;
	while (jeu[i][column].etats != 0)
		i++;
	jeu[i][column].etats = side;
	return (i);
}
