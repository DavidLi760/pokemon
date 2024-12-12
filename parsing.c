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
    int rid = 0;
    var->fd = open(argv[1], O_RDONLY);
    if (var->fd == -1)
        return (0);
    rid = read(var->fd, var->temp, 7000);
    if (rid == 0 || rid == -1)
        return (close(var->fd), 0);
    // if (rid > 0)
    //     var->split = ft_split(var->temp);
    close(var->fd);
    return (1);
}

int parsing(t_var *var, char **argv)
{
    if (!get_map(var, argv))
        return (0);
    return (1);
}
