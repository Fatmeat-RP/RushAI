/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:57:27 by njaros            #+#    #+#             */
/*   Updated: 2021/11/06 16:30:35 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

t_amove	**ft_init_struct(int widht, int height)
{
	t_amove	**init;
	int	h;
	int w;
	int	s;

	s = sizeof(t_amove);
	h = 0;
	init = malloc((sizeof(t_amove*)) * height);
	if (!init)
		return (NULL);
	while (h < height)
	{
		w = 0;
		init[h] = malloc(s * widht);
		if (!init[h])
			return (NULL);
		while (w < widht)
		{
			init[h][w].x = w;
			init[h][w].y = h;
			init[h][w].etats = 0;
			w++;
		}
		h++;
	}
	return (init);
}