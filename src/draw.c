/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    draw(t_mlx *tmlx, t_data *img, char *param)
{
    int x;
    int y;

    y = 0;
    while (y < win_height)
    {
        x = 0;
        while (x < win_width)
        {
            if (param[0] == 'm')
                mandelbrot(img, x, y);
            else if (param[0] == 'j')
                julia(img, x, y);
            x++;
        }
        y++;
    }
    free(param);
    mlx_put_image_to_window(tmlx->mlx, tmlx->mlx_win, img->img, 0, 0);
}

t_complex   convert_to_complex(int x, int y, t_setup *m)
{
    t_complex   c;
    double      range_x;
    double      range_y;
    
    range_x = m->xmax - m->xmin;
    range_y = m->ymax - m->ymin;
    c.r = ((double)x * (range_x / win_width) + m->xmin);
    c.i = ((double)y * (range_y /win_height) + m->ymin);
    return (c);
}