/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:33:55 by njaros            #+#    #+#             */
/*   Updated: 2021/11/06 14:41:54 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

int	main(int ac, char **av)
{
	struct s_amove	**tab;
	int 			widht;
	int 			height;

	widht = atoi(av[1]);
	height = atoi(av[2]);
	tab = ft_init_struct(widht, height);
	ft_display(tab, widht, height);
	return (0);
}