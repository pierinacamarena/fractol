/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    julia_init(t_setup *j)
{
    j->maxN = 255;
    j->xmin = -2.0f;
    j->xmax = 2.0f;
    j->ymin = -2.0f;
    j->ymax = 2.0f;   
    j->fractal = ft_strdup('julia');
}

void    julia(t_data *img, int x, int y)
{
    t_complex   c;
    t_complex   z;
    t_complex   temp;
    t_setup     j;
    int         i;

    julia_init(&j); 
    z = convert_to_complex(x, y, &j);
    //c.r = -0.7269;
    //c.i = 0.1889;
    //c.r = -0.8;
    //c.i = 0.156;
    i = 0;
    while ((i < j.maxN) && (z.r * z.r + z.i * z.i < 4.0))
    {
        temp.r = z.r * z.r - z.i * z.i + c.r; 
        temp.i = z.r * z.i * 2.0 + c.i;
        if (z.r == temp.r && z.i == temp.i)
        {
            i = j.maxN;
            break;
        }
        z.r = temp.r;
        z.i = temp.i;
        i++;
    }
    if (i < j.maxN) 
        my_mlx_pixel_put(img, x, y, 0xffffff);
    else
        my_mlx_pixel_put(img, x, y, 0x2b9fa3);
}