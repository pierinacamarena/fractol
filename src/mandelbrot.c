/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_alternative.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:28:50 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/07 15:46:16 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void    mandel_init(t_setup *m)
{
    m->maxN = 255;
    m->xmin = -2.0f;
    m->xmax = 2.0f;
    m->ymin = -1.0f;
    m->ymax = 1.0f;
    m->fractal = ft_strdup("mandelbrot");
}

void    mandelbrot(t_mlx *tmlx, int x, int y)
{
    t_complex   c;
    t_complex   z;
    t_complex   temp;
    t_setup     m;
    int         i;
    
    mandel_init(&m);
    c = convert_to_complex(x, y, &m);
    z = convert_to_complex(x, y, &m);
    i = 0;
    while ((i < m.maxN) && (z.r * z.r + z.i * z.i < 4.0))
    {
        temp.r = z.r * z.r - z.i * z.i + c.r; 
        temp.i = z.r * z.i * 2.0 + c.i;
        if (z.r == temp.r && z.i == temp.i)
        {
            i = m.maxN;
            break;
        }
        z.r = temp.r;
        z.i = temp.i;
        i++;
    }
    if (i < m.maxN) 
        my_mlx_pixel_put(tmlx, x, y, 0xffffff);
    else
        my_mlx_pixel_put(tmlx, x, y, 0x2b9fa3);
}
