/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    draw_line_vertical(t_data *img, int x, int y, int len, int color)
{
    int i;

    i = 0;
    while (i < len)
    {
        my_mlx_pixel_put(img, x, y, color);
        y++;
        i++;
    }
}

void    draw_line_slope_upwards(t_data *img, int x, int y, int len, int color)
{
    int i;

    i = 0;
    while (i < (len/2))
    {
        my_mlx_pixel_put(img, x, y, color);
        x++;
        y++;
        i++;   
    }
}

void    draw_line_slope_downwards(t_data *img, int x, int y, int len, int color)
{
    int i;
    int x1;
    int y1;

    i = 0;
    x1 = x + len/2;
    y1 = y + len/2;
    while (i < (len/2))
    {
        my_mlx_pixel_put(img, x1, y1, color);
        x1++;
        y1--;
        i++;
    }
}

void    draw_line_horizontal(t_data *img, int x, int y, int len, int color)
{
    int i;

    i = 0;
    while (i < len)
    {
        my_mlx_pixel_put(img, x, y, color);
        x++;
        i++;
    }
}

void    draw_square(t_data *img, int x, int y, int len, int color)
{
    int x2;
    int y2;

    x2 = x + len;
    y2 = y + len;
    draw_line_horizontal(img, x, y, len, color);
    draw_line_vertical(img, x, y, len, color);
    draw_line_horizontal(img, x, y2, len, color);
    draw_line_vertical(img, x2, y, len, color);
}

void    draw_triangle(t_data *img, int x, int y, int len, int color)
{
    draw_line_horizontal(img, x, y, len, color);
    draw_line_slope_upwards(img, x, y, len, color);
    draw_line_slope_downwards(img, x, y, len, color);
}

void    midpointcircle(t_data *img, int x, int y, int r, int color)
{
    int x1;
    int y1;
    int p;

    x1 = r;
    y1 = 0;
    my_mlx_pixel_put(img, x1 + x, y1 + y, color);
    if (r > 0)
    {
        my_mlx_pixel_put(img, x1 + x, -y1 + y, color);
        my_mlx_pixel_put(img, y1 + x, x1 + y, color);
        my_mlx_pixel_put(img, -y1 + x, x1 + y, color);
    }
    p = 1 - r;
    while (x1 > y1)
    {
        y1++;
        if (p <= 0)
            p = p + 2*y1 + 1;
        else
        {
            x1--;
            p = p + 2*y1 - 2*x1 + 1;
        }
        if (x1 < y1)
            break;
        my_mlx_pixel_put(img, x1 + x, y1 + y, color);
        my_mlx_pixel_put(img, -x1 + x, y1 + y, color);
        my_mlx_pixel_put(img, x1 + x, -y1 + y, color);
        my_mlx_pixel_put(img, -x1 + x, -y1 + y, color);
        if (x1 != y1)
        {
            my_mlx_pixel_put(img, y1 + x, x1 + y, color);
            my_mlx_pixel_put(img, -y1 + x, x1 + y, color);
            my_mlx_pixel_put(img, y1 + x, -x1 + y, color);
            my_mlx_pixel_put(img, -y1 + x, -x1 + y, color);
        }
    }
}