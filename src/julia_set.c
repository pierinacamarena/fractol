/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double map_to_real_julia(int x, int image_width, double min_r, double max_r)
{
    double range;

    range = max_r - min_r;
    return ((double)x * (range / image_width) + min_r);
}

double map_to_imaginary_julia(int y, int image_height, double min_i, double max_i)
{
    double range;

    range = max_i - min_i;
    return ((double)y * (range / image_height) + min_i);
}

int find_julia(double cr, double ci, int x, int y, int maxN)
{
    int     i;
    double  zr;
    double  zi;
    double  temp;

    i = 0;
    zr = 0.0;
    zi = 0.0;
    while ((i < maxN) && ((zr * zr + zi * zi)< 4.0))
    {
        temp = zr * zr - zi * zi + cr;
        zi = 2.0 * zr * zi + ci;
        zr = temp;
        i++;
    }
    return (i);
}

void    init_julia(t_julia *julia)
{
    julia->min_r = -1.5;
    julia->max_r = 0.7;
    julia->min_i = -1.0;
    julia->max_i = 1.0;
    julia->maxN = 255;
}

/*
for every pixel 
    find the real and imaginary values for c, corresponding
    to that x,y pixel in the image
    find the number of instructions in the julia formula
    using said c.
    Map the resulting number to an RGB VALUE
*/

void    julia(t_mlx *tmlx, t_data *img)
{
    int x;
    int y;
    int n;
    t_julia julia;
    
    y = 0;
    init_julia(&julia);
    while (y < win_height)
    {
        x = 0;
        while (x < win_width)
        {
            julia.cr = map_to_real_julia(x, win_width, julia.min_r, julia.max_r);
            julia.ci = map_to_imaginary_julia(y, win_height, julia.min_i, julia.max_i); 
            //julia.cr = 0.70176;
            //julia.ci = - 0.3842;
            n = find_julia(julia.cr, julia.ci, x, y, julia.maxN);
            if (n < julia.maxN) 
                my_mlx_pixel_put(img, x, y, 0xffffff);
            else
                my_mlx_pixel_put(img, x, y, 0x2b9fa3);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(tmlx->mlx, tmlx->mlx_win, img->img, 0, 0);
}
