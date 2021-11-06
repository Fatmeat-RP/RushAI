/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushai.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 13:01:26 by acarle-m          #+#    #+#             */
/*   Updated: 2021/11/06 14:04:40 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSHAI_H
# define RUSHAI_H

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
	int x;
	int y;
	int	etats;
	s_amove	*next;
	s_amove	*prev;
}				t_amove;

typedef struct	s_bmove
{
	int x;
	int y;
	int	etats;
	s_bmove	*next;
	s_bmove	*prev;
}				t_bmove;

#endif
