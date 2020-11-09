/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:52:23 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/05 14:10:04 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//note : Diffuse objects do not receive light from other objects. 
//k_a \in [0,1] : constante liée à la composante ambiante, la proportion de lumière renvoyée ;
//La composante ambiante représente les parasites provenant d'autre chose que la source considérée,
//la lumière réfléchie par d'autres points par exemple. 
//La lumière ambiante est supposée égale en tout point de l'espace



t_vector ambiant(t_minirt *rt)
{
    t_vector amb;

    amb.x = rt->ambient.color.r * rt->ambient.ratio * rt->result_color.r;
    amb.y = rt->ambient.color.g * rt->ambient.ratio * rt->result_color.g;
    amb.z = rt->ambient.color.b * rt->ambient.ratio * rt->result_color.b;    
    amb.x = min(1, amb.x);  
    amb.y = min(1, amb.y);
    amb.z = min(1, amb.z);
    return (amb);
}

//Ambient lighting by itself doesn't produce the most interesting results, 
//but diffuse lighting however will start to give a significant visual impact on the object. 
//Diffuse lighting gives the object more brightness the closer its fragments are aligned to the light rays from a light source. 
//the lower the angle between two unit vectors, the more the dot product is inclined towards a value of 1
//Amount of light energy that falls on surface is proportional to incidence angle, θ in our case it's m 
t_vector diffuse(t_minirt *rt)
{
    t_vector Id;
    double m;

    m = vectorDot(rt->l_norm, rt->n_norm);
    m = max(0.0,m);
    Id.x = rt->ratio  * m *  rt->result_color.r * rt->light_rgb.r ;
    Id.y = rt->ratio  * m *  rt->result_color.g * rt->light_rgb.g ;
    Id.z = rt->ratio  * m *  rt->result_color.b * rt->light_rgb.b ;
    return (Id);
}



t_vector spec(t_minirt *rt)
{
    double dot;
    t_vector scal;
    t_vector specular;
    t_vector reflection;
    t_vector view;
    double ks = 1;
    double constante = 2000;

    dot = 2 * vectorDot(rt->n_norm, rt->l_norm);
    scal = vectorScale(rt->n_norm, dot);
    reflection = vectorSub(rt->l_norm,scal );
     reflection = vectorNorme(reflection);
    view = vectorScale(rt->position, 1);
    view = vectorNorme(view);
    dot = vectorDot(reflection, view);
    dot = max(0.0,dot);
    specular.x = ks * rt->light_rgb.r * pow(dot, constante) ;
    specular.y = ks * rt->light_rgb.g * pow(dot, constante) ;
    specular.z = ks * rt->light_rgb.b * pow(dot, constante) ;
    return (specular);
}
