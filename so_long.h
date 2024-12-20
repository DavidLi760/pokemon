/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:06:07 by davli             #+#    #+#             */
/*   Updated: 2024/12/03 18:07:25 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "fcntl.h"
# include "mlx/mlx.h"

typedef struct	s_var
{
	void	*mlx;
	void	*win;

	void	*img1;
	char	*addrimg1;
	int		lenimg1;
	int		bitimg1;
	int		endianimg1;

	void	*img2;
	char	*addrimg2;
	int		lenimg2;
	int		bitimg2;
	int		endianimg2;

	void	*no1;
	int		widthno1;
	int		heightno1;
	char	*addrno1;
	int		lenno1;
	int		bitno1;
	int		endianno1;

	void	*no2;
	int		widthno2;
	int		heightno2;
	char	*addrno2;
	int		lenno2;
	int		bitno2;
	int		endianno2;

	void	*no3;
	int		widthno3;
	int		heightno3;
	char	*addrno3;
	int		lenno3;
	int		bitno3;
	int		endianno3;
	
	void	*we1;
	int		widthwe1;
	int		heightwe1;
	char	*addrwe1;
	int		lenwe1;
	int		bitwe1;
	int		endianwe1;

	void	*we2;
	int		widthwe2;
	int		heightwe2;
	char	*addrwe2;
	int		lenwe2;
	int		bitwe2;
	int		endianwe2;

	void	*we3;
	int		widthwe3;
	int		heightwe3;
	char	*addrwe3;
	int		lenwe3;
	int		bitwe3;
	int		endianwe3;

	void	*ea1;
	int		widthea1;
	int		heightea1;
	char	*addrea1;
	int		lenea1;
	int		bitea1;
	int		endianea1;

	void	*ea2;
	int		widthea2;
	int		heightea2;
	char	*addrea2;
	int		lenea2;
	int		bitea2;
	int		endianea2;

	void	*ea3;
	int		widthea3;
	int		heightea3;
	char	*addrea3;
	int		lenea3;
	int		bitea3;
	int		endianea3;

	void	*so1;
	int		widthso1;
	int		heightso1;
	char	*addrso1;
	int		lenso1;
	int		bitso1;
	int		endianso1;

	void	*so2;
	int		widthso2;
	int		heightso2;
	char	*addrso2;
	int		lenso2;
	int		bitso2;
	int		endianso2;

	void	*so3;
	int		widthso3;
	int		heightso3;
	char	*addrso3;
	int		lenso3;
	int		bitso3;
	int		endianso3;

	void	*voi;
	int		widthvoi;
	int		heightvoi;
	char	*addrvoi;
	int		lenvoi;
	int		bitvoi;
	int		endianvoi;

	void	*gr1;
	int		widthgr1;
	int		heightgr1;
	char	*addrgr1;
	int		lengr1;
	int		bitgr1;
	int		endiangr1;

	int		x1;
	int		y1;
	int		x2;
	int		y2;
	
	int		max_x;
	int		max_y;

	int		fd;
	char 	*temp;
	char	**split;
	char	**map;

	int		w_pressed;
	int		s_pressed;
	int		a_pressed;
	int		d_pressed;
    

	int		dim;
}	t_var;

int		parsing(t_var *var, char **argv);
char	**ft_split(char *str, char *set, int i, int j);

#endif
