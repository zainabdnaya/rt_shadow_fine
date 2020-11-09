/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <diyanazizo13@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 09:00:02 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/07 07:42:01 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void error(double nbr)
{
    if (nbr == 0)
        write(2, "Error(0): Failed to Initial Minilibx", 40);
    else if (nbr == 1)
        write(2, "Error(1): Wrong Number of Arguments!\n", 38);
    else if (nbr == 2)
        write(2, "Error(2): Extension (.rt) needed! \n", 35);
    else if (nbr == 3)
        write(2, "Error(3): There is No such file or directory!\n", 45);
    else if (nbr == 4)
        write(2, "Error(4): Invalid extension!\n", 25);
    else if (nbr == 5)
        write(2, "Error(5): Parsing error in file !\n", 35);
    else if (nbr == 6)
        write(2, "Error(6): Small Resolution!\n", 28);
    else if (nbr == 7)
        write(2, "Error(7):fov should be in rage of [1,180]\n", 45);
    else if (nbr == 8)
        write(2, "Error(8): Allocation failed !\n", 33);
    else if (nbr == 9)
        write(2, "Error(9): No Resolution !\n", 28);
    else if (nbr == 0.1)
        write(2, "Error(0.1): Try Integer type resolution!\n", 50);
}

void p_error(long nbr1)
{
    if (nbr1 == 10 )
        write(2, "Error(10): Camera Parsing is wrong!\n", 33);
    else if (nbr1 == 11)
        write(2, "Eroor(11): Vector Parsing is wrong!\n", 37);
    else if (nbr1 == 12)
        write(2, "Error(12): No Camera !\n", 20);
    else if (nbr1 == 13)
        write(2, "Error(13): Allocation failed!\n", 35);
    else if (nbr1 == 14)
        write(2, "Error(14): Problem in light parsing!\n", 45);
    else if (nbr1 == 15)
        write(2, "Error(15): light Parsing is wrong!\n", 33);
    else if (nbr1 == 16)
        write(2, "Error(16): Ambient Parsing is wrong!\n", 41);
    else if (nbr1 == 17)
        write(2, "Error(17): Ambient Ratio  is wrong!\n", 43);
    else if (nbr1 == 18)
        write(2, "Error(18): put 3 variables in a forme of vector and split it with 2 comma!\n", 80);
    else if (nbr1 == 19)
        write(2, "Error(19): the number of RGB color should be in range [0,255]\n", 80);
    else if (nbr1 == 20)
        write(2, "Error(20): light Ratio  is wrong!\n", 43);
}

void obj_error(long nbr)
{
    if (nbr == 21)
        write(2, "Error(21): Sphere configuration is wrong!\n", 44);
    if (nbr == 22)
        write(2, "Error(22): Enter positive radius in sphere\n", 50);
    if(nbr == 23)
        write(2, "Error(23): Allocation objects failed!\n", 44);
    if(nbr == 24)
        write(2,"Error(24): The Normale Coordinates should be between [-1,1]",60);
    if (nbr == 25)
        write(2, "Error(25): Plan configuration is wrong!\n", 44);  
    if (nbr == 26)
        write(2, "Error(26): Triangle configuration is wrong!\n", 47);
    if (nbr == 27)
        write(2, "Error(27): square configuration is wrong!\n", 47);
    if (nbr == 28)
        write(2, "Error(28): cylindre configuration is wrong!\n", 50);
    if (nbr == 29)
        write(2, "Error(29): Enter positive diametre and height in cylindre\n", 60);
    if (nbr == 30)
        write(2,"Error(30): Enter positive Side_size is negative\n",50);
}
