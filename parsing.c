/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <davli@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:38:14 by davli             #+#    #+#             */
/*   Updated: 2024/12/12 17:38:17 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    get_map(t_var *var, char **argv)
{
    int rid = 1;

    var->fd = open(argv[1], O_RDONLY);
    if (var->fd == -1)
        return (0);
    var->temp = malloc(sizeof(char) * 6900);
        rid = read(var->fd, var->temp, 6899);
        if (rid == -1)
            return (close(var->fd), 0);
    var->map = ft_split(var->temp, "\n", -1, 0);
    close(var->fd);
    return (1);
}

int is_rectangle(t_var *var)
{
    int i = 0;
    int j = 0;

    var->max_x = 0;
    while (var->map[i])
    {
        j = 0;
        while (var->map[i][j])
            j++;
        if (j != var->max_x && var->max_x != 0)
            return (printf("Error :\nMap is not rectangle\n"), 0);
        var->max_x = j;
        i++;
    }
    var->max_y = i;
    return (1);
}

int wall_is_closed(t_var *var)
{
    int i;
    int j;

    i = 0;
    while (i < var->max_y)
    {
        j = 0;
        while (j < var->max_x)
        {
            if (i == 0 || j == 0 || j == var->max_x - 1|| i == var->max_y - 1)
            {
                if (var->map[i][j] == '0')
                    return (printf("Error :\nWall is not closed\n"), 0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int parsing(t_var *var, char **argv)
{
    if (!get_map(var, argv))
        return (0);
    if (!is_rectangle(var))
        return (0);
    if (!wall_is_closed(var))
        return (0);
    return (1);
}
