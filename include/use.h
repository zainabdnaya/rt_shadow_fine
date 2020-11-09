/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:40:20 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/06 19:05:10 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USE_H
#define USE_H

#include "minirt.h"

typedef struct s_vector
{
    float x;
    float y;
    float z;
} t_vector;

typedef struct s_use
{
    double      scal1;
    double      t1;
    double      t2;
    double      t;
    double      s;
    t_vector    dist;
    double      scal2;
    double      rst;
    double      delta;
    t_vector    one_scal;
    double      denominator;
    t_vector    edge1;
    t_vector    edge2;
    t_vector    vect;
    t_vector    vect1;
    t_vector    vect2;
    double      determinant;
    t_vector    diffrence;
    double      inverse_determinant;
    double      v;
    double      u;
    double      one;
    double      two;
    t_vector    produit;
    t_vector    point_pos;
    t_vector    up;
    t_vector   q_ed;
    double     edge;
    double      a;
    double      b;
    double      c;
    double      discriminant;
    double      m;
    double      m1;
    double      t3;
    double      t4;
    t_vector    x_vect;

} t_use;

typedef struct s_resol
{
    int  WIDTH;
    int  HEIGHT;
} t_resol;

typedef struct s_pars
{
    char    **splitrest;
    double  i;
    double  j;
    double  parsed;
} t_pars;


typedef struct s_ray
{
    t_vector origin;
    t_vector direction;
} t_ray;

typedef struct s_color
{
    double r;
    double g;
    double b;
} t_color;

typedef struct s_shown
{
    t_vector *origin;
    double total_intensity;
    int nb_camera;
    int background_color;
    int depth;
    double t_min;
    double t_max;
} t_shown;

typedef struct s_ambient
{
    double      ratio;
    double      parsed;
    t_color     color;
} t_ambient;

typedef struct s_phong
{
    t_vector object;
    t_vector l;
    t_vector n;
    t_vector p;
    t_vector r;

} t_phong;

typedef struct s_light
{
    double      intensity;
    t_vector    color;
    t_vector    *vector;
    t_vector    position;
    double      ratio;
    t_color     rgb;

} t_light;

typedef struct s_camera
{
    t_vector    rotation;
    t_vector    direction;
    t_vector    look_from;
    t_vector    look_at;
    double      aspectRatio;
    double      fov;
    double      half_height;
    double      half_width;
    int         camera_count;
    double      tetha;
    int         point;
} t_camera;






#endif // !USE_H