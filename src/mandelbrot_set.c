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

double map_to_real(int x, int image_width, double min_r, double max_r)
{
    double range;

    range = max_r - min_r;
    return ((double)x * (range / image_width) + min_r);
}

double map_to_imaginary(int y, int image_height, double min_i, double max_i)
{
    double range;

    range = max_i - min_i;
    return ((double)y * (range / image_height) + min_i);
}

int findMandelbrot(double cr, double ci, int maxN)
{
    int i;
    i = 0;
    double zr = 0.0;
    double zi = 0.0;
    while ((i < maxN) && ((zr * zr + zi * zi)< 4.0))
    {
        double temp = zr * zr - zi * zi + cr;
        zi = 2.0 * zr * zi + ci;
        zr = temp;
        i++;
    }
    return (i);
}

void    mandelbrot(t_mlx *tmlx, t_data *img)
{
    int x;
    int y;
    int n;
    t_mandel mandel;
    
    y = 0;
    mandel.min_r = -1.5;
    mandel.max_r = 0.7;
    mandel.min_i = -1.0;
    mandel.max_i = 1.0;
    mandel.maxN = 255;
    //for every pixel 
    while (y < win_height) //rows
    {
        x = 0;
        while (x < win_width) //pixels in row
        {
            //  ...find the real and imaginary values for c, corresponding
            //      to that x,y pixel in the image
            mandel.cr = map_to_real(x, win_width, mandel.min_r, mandel.max_r);
            mandel.ci = map_to_imaginary(y, win_height, mandel.min_i, mandel.max_i); 
            //  ...find the number of instructions in the mandelbrot formula
            //      using said c.
            n = findMandelbrot(mandel.cr, mandel.ci, mandel.maxN);
            //  ...Map the resulting number to an RGB VALUE
            if (n < mandel.maxN) 
                my_mlx_pixel_put(img, x, y, 0xffffff);
            else
                my_mlx_pixel_put(img, x, y, 0xf2954e);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(tmlx->mlx, tmlx->mlx_win, img->img, 0, 0);
}
/*
void    mandelbrot(t_mlx *tmlx, t_data *img)
{
    int maxN;
    double min_r;
    double max_r;
    double min_i;
    double max_i;
    
    min_r = -1.5;
    max_r = 0.7;
    min_i = -1.0;
    max_i = 1.0;
    maxN = 255;
    //for every pixel 
    for(int y = 0; y < win_height; y++) //rows
    {
        for (int x = 0; x < win_width; x++) //pixels in row
        {
            //  ...find the real and imaginary values for c, corresponding
            //      to that x,y pixel in the image
            double cr = map_to_real(x, win_width, min_r, max_r);
            double ci = map_to_imaginary(y, win_height, min_i, max_i); 
    //  ...find the number of instructions in the mandelbrot formula
    //      using said c.
            int n = findMandelbrot(cr, ci, maxN);
    //  ...Map the resulting number to an RGB VALUE
            if (n < maxN) 
                my_mlx_pixel_put(img, x, y, 0xffffff);
            else
                my_mlx_pixel_put(img, x, y, 0xf2954e);
        }
    }
    mlx_put_image_to_window(tmlx->mlx, tmlx->mlx_win, img->img, 0, 0);
}
*/