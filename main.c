/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:33:55 by njaros            #+#    #+#             */
/*   Updated: 2021/11/06 17:10:20 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

int	main(int ac, char **av)
{
	struct s_amove	**jeu;
	int 			widht;
	int 			height;
	int				i;

	i = 3;
	height = ft_atoi(av[1]);
	widht = ft_atoi(av[2]);
	jeu = ft_init_struct(widht, height);
	ft_display(jeu, widht, height);
	while (av[i])
	{
		if (i % 2 == 0)
			ft_putnbr_fd(ft_add_token(jeu, ft_atoi(av[i]), 1, widht, height), 1);
		else
			ft_putnbr_fd(ft_add_token(jeu, ft_atoi(av[i]), 2, widht, height), 1);
		write(1, "\n", 1);
		i++;
	}
	ft_display(jeu, widht, height);
	ft_free(jeu, height);
	return (0);
}
