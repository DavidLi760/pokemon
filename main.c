/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:02:33 by davli             #+#    #+#             */
/*   Updated: 2024/12/03 18:05:34 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_win(t_var *var)
{
    mlx_destroy_window(var->mlx, var->win);
    exit(0);
}

int key_press(int keycode, t_var *var)
{
    if (keycode == 65307)
        close_win(var);
    if (keycode == 'a')
        var->a_pressed = 1;
    if (keycode == 'd')
        var->d_pressed = 1;
    if (keycode == 'w')
        var->w_pressed = 1;
    if (keycode == 's')
        var->s_pressed = 1;
    return (0);
}

int key_release(int keycode, t_var *var)
{
    if (keycode == 'a')
        var->a_pressed = 0;
    if (keycode == 'd')
        var->d_pressed = 0;
    if (keycode == 'w')
        var->w_pressed = 0;
    if (keycode == 's')
        var->s_pressed = 0;
    return (0);
}

void	my_pixel_put(t_var *var, int x, int y, int color)
{
	char	*dst;

	dst = var->addrimg1 + (y * var->lenimg1 + x * (var->bitimg1 / 8));
	*(unsigned int *)dst = color;
}

int	my_pixel_from_texture(t_var *var, int x, int y, char no)
{
	int		color;
	char	*pixel;

    pixel = 0;
	if (no == 'n')
		pixel = var->addrwe1 + (y * var->lenwe1 + x * (var->bitwe1 / 8));
    if (no == 'a')
		pixel = var->addrvoi + (y * var->lenvoi + x * (var->bitvoi / 8));
	color = *(unsigned int *)pixel;
	return (color);
}

void	my_put_image_to_image(t_var *var, int x, int y)
{
	int	color;
	int	i;
	int	j;

	i = y;
	while (++i < y + 50)
	{
		j = x;
		while (++j < x + 50)
		{
			color = my_pixel_from_texture(var, j - x, i - y, 'n');
			if (j < 1920 && i < 1010 && j > 0 && i > 0 && color != 0x000000)
					my_pixel_put(var, j, i, color);
		}
	}
}

void	my_put_image_to_image2(t_var *var, int x, int y)
{
	int	color;
	int	i;
	int	j;

	i = y;
	while (++i < y + 50)
	{
		j = x;
		while (++j < x + 50)
		{
			color = my_pixel_from_texture(var, j - x, i - y, 'a');
			if (j < 1920 && i < 1010 && j > 0 && i > 0)
					my_pixel_put(var, j, i, color);
		}
	}
}

int update(t_var *var)
{
    if (var->w_pressed)
        var->y1 -= 1;
    if (var->s_pressed)
        var->y1 += 1;
    if (var->a_pressed)
        var->x1 -= 1;
    if (var->d_pressed)
        var->x1 += 1;
    if (var->s_pressed)
        my_put_image_to_image2(var, var->x1, var->y1 - 1);
    my_put_image_to_image2(var, var->x1, var->y1);
    my_put_image_to_image(var, var->x1, var->y1);
    mlx_put_image_to_window(var->mlx, var->win, var->img1, 0, 0);
    return (0);
}

void    init(t_var *var)
{
    var->x1 = 0;
    var->y1 = 0;
    var->x2 = 0;
    var->y2 = 0;
}

void    init_img(t_var *var)
{
    var->img1 = mlx_new_image(var->mlx, 1920, 1010);
    var->addrimg1 = mlx_get_data_addr(var->img1, &var->bitimg1, &var->lenimg1, &var->endianimg1);
    var->no1 = mlx_xpm_file_to_image(var->mlx, "xpms/NO1.xpm", &var->widthno1, &var->heightno1);
    var->addrno1 = mlx_get_data_addr(var->no1, &var->bitno1, &var->lenno1, &var->endianno1);
    var->no2 = mlx_xpm_file_to_image(var->mlx, "xpms/NO2.xpm", &var->widthno2, &var->heightno2);
    var->addrno2 = mlx_get_data_addr(var->no2, &var->bitno2, &var->lenno2, &var->endianno2);
    var->no3 = mlx_xpm_file_to_image(var->mlx, "xpms/NO3.xpm", &var->widthno3, &var->heightno3);
    var->addrno3 = mlx_get_data_addr(var->no3, &var->bitno3, &var->lenno3, &var->endianno3);
    var->ea1 = mlx_xpm_file_to_image(var->mlx, "xpms/EA1.xpm", &var->widthea1, &var->heightea1);
    var->addrea1 = mlx_get_data_addr(var->ea1, &var->bitea1, &var->lenea1, &var->endianea1);
    var->ea2 = mlx_xpm_file_to_image(var->mlx, "xpms/EA2.xpm", &var->widthea2, &var->heightea2);
    var->addrea2 = mlx_get_data_addr(var->ea2, &var->bitea2, &var->lenea2, &var->endianea2);
    var->ea3 = mlx_xpm_file_to_image(var->mlx, "xpms/EA3.xpm", &var->widthea3, &var->heightea3);
    var->addrea3 = mlx_get_data_addr(var->ea3, &var->bitea3, &var->lenea3, &var->endianea3);
    var->we1 = mlx_xpm_file_to_image(var->mlx, "xpms/WE1.xpm", &var->widthwe1, &var->heightwe1);
    var->addrwe1 = mlx_get_data_addr(var->we1, &var->bitwe1, &var->lenwe1, &var->endianwe1);
    var->we2 = mlx_xpm_file_to_image(var->mlx, "xpms/WE2.xpm", &var->widthwe2, &var->heightwe2);
    var->addrwe2 = mlx_get_data_addr(var->we2, &var->bitwe2, &var->lenwe2, &var->endianwe2);
    var->we3 = mlx_xpm_file_to_image(var->mlx, "xpms/WE3.xpm", &var->widthwe3, &var->heightwe3);
    var->addrwe3 = mlx_get_data_addr(var->we3, &var->bitwe3, &var->lenwe3, &var->endianwe3);
    var->so1 = mlx_xpm_file_to_image(var->mlx, "xpms/SO1.xpm", &var->widthso1, &var->heightso1);
    var->addrso1 = mlx_get_data_addr(var->so1, &var->bitso1, &var->lenso1, &var->endianso1);
    var->so2 = mlx_xpm_file_to_image(var->mlx, "xpms/SO2.xpm", &var->widthso2, &var->heightso2);
    var->addrso2 = mlx_get_data_addr(var->so2, &var->bitso2, &var->lenso2, &var->endianso2);
    var->so3 = mlx_xpm_file_to_image(var->mlx, "xpms/SO3.xpm", &var->widthso3, &var->heightso3);
    var->addrso3 = mlx_get_data_addr(var->so3, &var->bitso3, &var->lenso3, &var->endianso3);
    var->voi = mlx_xpm_file_to_image(var->mlx, "xpms/Void.xpm", &var->widthvoi, &var->heightvoi);
    var->addrvoi = mlx_get_data_addr(var->voi, &var->bitvoi, &var->lenvoi, &var->endianvoi);
}

int	main(int argc, char **argv)
{
    t_var var;

    if (argc != 2)
        return (0);
    (void)argv;
    init(&var);
    if (!parsing(&var, argv))
        return (0);
    var.mlx = mlx_init();
    if (!var.mlx)
        return (0);
    var.win = mlx_new_window(var.mlx, 1920, 1010, "Pokemon 42");
    if (!var.win)
        return (0);
    init_img(&var);
    mlx_hook(var.win, 2, 1L << 0, key_press, &var);
    mlx_hook(var.win, 3, 1L << 1, key_release, &var);
    mlx_hook(var.win, 17, 0, close_win, &var);
    mlx_loop_hook(var.mlx, update, &var);
    mlx_loop(var.mlx);
    return (0);
}
