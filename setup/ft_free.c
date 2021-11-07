/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:17:20 by njaros            #+#    #+#             */
/*   Updated: 2021/11/06 16:29:44 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

void	ft_free(struct s_amove **jeu, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (jeu[i] != NULL)
			free(jeu[i]);
		i++;
	}
	free(jeu);
}
