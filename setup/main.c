/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:33:55 by njaros            #+#    #+#             */
/*   Updated: 2021/11/07 18:09:22 by acarle-m         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "rushai.h"

int	ft_intoi(void)
{
	struct s_parms	param;
	int				i;
	char			*str;
	int				n;

	i = 0;
	while(42)
	{
		printf("index : %i\n", i);
		str = strdup(getinput());
		n = atoi(str);
		if ((strcmp(str, "nope")) == 0)
			return (0);
		if (i <= 6)
		{
			switch(i)
			{
				case '1' :
					param.height = n;
					break;
				case '2' :
					param.widht = n;
					break;
				case '3' :
					param.win_cond = n;
					break;
				case '4' :
					param.start = n;
					break;
				case '5' :
					param.tot_time = n;
					break;
				case '6' :
					param.time_gain = n;
					break;
			}
		}
		printf("input : %i\n", atoi(str));
		i++;
	}
	return (n);
}


int	main(int ac, char **av)
{
	struct s_amove	**jeu;
	struct s_parms	param;
	int				i;
	int				play;

	i = 3;
	while (42)
		play = ft_intoi();
	jeu = ft_init_struct(param.widht, param.height);
	while (play)
	{
		if (i % 2 == 0)
			ft_putnbr_fd(ft_add_token(jeu, play, 1, param.widht, param.height), 1);
		else
			ft_putnbr_fd(ft_add_token(jeu, play, 2, param.widht, param.height), 1);
		write(1, "\n", 1);
		i++;
	}
	ft_display(jeu, param.widht, param.height);
	ft_putnbr_fd(ft_count_win(jeu, 3, 0, param.widht, param.height, 4), 1);
	ft_putchar_fd('\n', 1);
	ft_free(jeu, param.widht);
	return (0);
}
