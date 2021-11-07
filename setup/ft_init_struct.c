/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:57:27 by njaros            #+#    #+#             */
/*   Updated: 2021/11/07 16:10:18 by njaros           ###   ########lyon.fr   */
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
	w = 0;
	init = malloc((sizeof(t_amove*)) * widht);
	if (!init)
		return (NULL);
	while (w < widht)
	{
		h = 0;
		init[w] = malloc(s * height);
		if (!init[w])
			return (NULL);
		while (h < height)
		{
			init[w][h].x = w;
			init[w][h].y = h;
			init[w][h].etats = 0;
			h++;
		}
		w++;
	}
	return (init);
}