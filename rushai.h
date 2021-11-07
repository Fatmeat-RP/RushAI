/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushai.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:01:26 by acarle-m          #+#    #+#             */
/*   Updated: 2021/11/07 17:52:33 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSHAI_H
# define RUSHAI_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*			struct			*/

typedef struct	s_parms
{
	int	width;
	int	height;
	int	win_cond;
	int	start;
	int	tot_time;
	int	time_gain;
}				t_parms;

typedef struct	s_amove
{
	int 			x;
	int				y;
	int				etats;
	//struct s_amove	*next;
	//struct s_amove	*prev;
}				t_amove;

typedef struct	s_bmove
{
	int 			x;
	int 			y;
	int				etats;
	struct s_bmove	*next;
	struct s_bmove	*prev;
}				t_bmove;

int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_poids_feuille(struct s_amove **jeu, int x, int y, int widht, int height, int win_cond);
int		ft_minimax(struct s_amove **jeu_sim, int x, int y, int widht, int height, int depht, int joueur, int win_cond);
int		ft_count_win(struct s_amove **jeu, int x, int y, int widht, int height, int win_cond);
int		ft_atoi(const char *nptr);
void	ft_display(struct s_amove **jeu, int widht, int height);
t_amove	**ft_init_struct(int widht, int height);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_add_token(struct s_amove **jeu, int column, int side, int widht, int height);
void	ft_free(struct s_amove **jeu, int height);

#endif
