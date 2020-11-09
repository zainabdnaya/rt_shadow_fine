/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdnaya <zdnaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 22:06:47 by zdnaya            #+#    #+#             */
/*   Updated: 2020/11/09 12:17:50 by zdnaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT
#define MINI_RT

#include    "../minilibx_opengl_20191021/mlx.h"
#include    "get_next_line.h"
#include    "use.h"
#include    "objects.h"
#include    <stdlib.h>
#include    <unistd.h>
# include   <stdlib.h>
# include   <unistd.h>
# include   <stdarg.h>
# include   <string.h>
# include   <stdio.h>
#include    <math.h>
#include    <pthread.h>
#include    <errno.h>
#include    <sys/uio.h>
#include    <fcntl.h>
#include    <limits.h>
#define     Width 1000
#define     Height 800
#define     PI 3.14159


#define max(a, b) ((double)a >= (double)b ? (double)a : (double)b)
#define min(a, b) ((double)a <= (double)b ? (double)a : (double)b)


typedef struct s_list
{
    void             *content;
    struct s_list   *next;
}           t_list;

typedef struct s_mlx
{
    void        *mlx_ptr;
    void        *img_ptr;
    void        *win;
    int         *data_image;
    int         *image;
    int         size_l;
    int         bpp;
    int         endian;
    double      x;
    double      y;
    double      z;
    double draw_x;
    double draw_y;
} t_mlx;

typedef     struct s_hit
{
    double  hit_sphere;
}  t_hit;

typedef struct s_objects
{
    t_vector    center;
    double      radius;
    t_color     color;
    double      solution;
    t_vector    position;
    t_vector    normal;
    t_vector    light_norm;
    t_vector    point;
    t_vector    p_norm;
    t_vector    point_a;
    t_vector    point_b;
    t_vector    point_c;
    t_vector    tr_normal;
    t_vector    sq_center;
    t_vector     cy_center;
    double      side_size;
    double      diameter;
    double      height;
    t_vector    cy_normal;
    int         wich_objects;
    
    struct s_objects   *next;
}t_objects;

typedef struct s_list_lights{

    double      intensity;
    t_vector    color;
    t_vector    position;
    double      ratio;
    t_color     rgb;

    struct s_list_lights *next;
}t_list_lights;

typedef struct s_list_camera{

    double      fov;
    t_vector    look_from;
    t_vector    look_at;
    

    struct s_list_camera *next;
}t_list_camera;


typedef struct s_minirt
{
    t_mlx       mlx;
    t_vector    vect;
    t_ray       ray;
    t_color     color;
    t_vector    pixel_position;
    t_vector    ray_direction;
    t_pars      pars;
    t_resol     resol;
    t_ambient   ambient;
    t_phong     phong;
    t_camera    *cam;
    
    t_objects       *list_obj;
    t_list_lights   *list_light;
    t_list_camera   *list_camera;

    int         wich_object;
    int         object_number;
    char        *line;
    char        *name;
    double      solution;
    double      aspectRatio;
    double      half_height;
    double      half_width;
    double      exist;
    double      hit1;
    t_color     result_color;  
    t_vector     l_norm;
    t_vector      n_norm;
    t_vector      position;
    double         m;
    t_vector       pol;
    int            check;
    int             it_sphere;
    int             it_plan; 
    int             it_cylindre;
    int             it_square;
    int             it_triangle;
    t_color         color_result;
    double          ratio;
    t_color         light_rgb;
    double          hit_shadow;
    t_vector        Id;
    t_vector        Spec;
    t_vector        amb;
    double          shadow;
    int             test;
    t_vector        shadow_origin;
    t_vector        shadow_direction;
    double          percent_shadow;
    double          var;
}t_minirt;


/***********************Vectors *************************************/
t_vector    vectorSplit(char *str);
t_vector    vectorAdd(t_vector v1, t_vector v2);
t_vector    vectorSub(t_vector v1, t_vector v2);
t_vector    vectorScale(t_vector v1, double m);
t_vector    vectorDiv(t_vector v1, double d);
double      vectorDot(t_vector v1, t_vector v2);
t_vector    vectorCross(t_vector v1, t_vector v2);
double      vectorLenght(t_vector v);
t_vector    vectorNorme(t_vector p);
t_vector    produit_Vect(t_vector v1, t_vector v2);
t_color     org(t_color r);
double      distance(t_vector one, t_vector two);
 /******************************************************************/

/*************Errors**********************************************/
void          error(double nbr);
void          p_error(long nbr1);
void          obj_error(long nbr);
/******************************************************************/

/**************Window / Camera************************************/
void            init_graphics(t_minirt *rt, t_mlx *mlx, int WIDTH, int HEIGHT);
void            config_window(t_minirt *rt,double fov);
void config_camera(t_minirt *rt, t_vector look_from, t_vector look_at);
void calcul_direction(t_minirt *rt, t_vector w, t_vector u, t_vector v);
void build_image(t_minirt *rt, t_vector look_from, t_vector look_at);
/******************************************************************/

/**************Parsing *****************************************/
void            parsing_RT(char *file, t_minirt *rt) ;
void            configuration(t_minirt *rt);
void            resolution_parsing(t_minirt *rt);
void            ambient_parsing(t_minirt *rt);
void            camera_parsing(t_minirt *rt);
void            sphere_parsing(t_minirt *rt);
void            light_parsing(t_minirt *rt);
void            plan_parsing(t_minirt *rt);
void            triangle_parsing(t_minirt *rt);
void            square_parsing(t_minirt *rt);
void            cylindre_parsing(t_minirt *rt);
/******************************************************************/
/*************Intersection  Objects ******************************/
double          sphere_equation(t_minirt *rt,t_vector ray_direction,t_vector origin);
double          plan_equation(t_minirt *rt,t_vector ray_direction,t_vector origin);
double          triangle_equation(t_minirt *rt,t_vector  ray_direction,t_vector origin);
double          square_equation(t_minirt *rt,t_vector ray_direction,t_vector origin);
double          cylindre_equation(t_minirt *rt,t_vector ray_direction,t_vector origin);

/******************************************************************/
/**************************Objects*********************************/
void            calcul_sphere(t_minirt *rt);
void            calcul_plan(t_minirt *rt);
void            calcul_triangle(t_minirt *rt);
void            calcul_square(t_minirt *rt);
void            calcul_cylindre(t_minirt *rt);
void            initial_all_objects(t_minirt *rt);
void            objects_intersection(t_minirt *rt);
/******************************************************************/

/****************Phong*********************************************/
t_vector        spec(t_minirt *rt);
t_vector        ambiant(t_minirt *rt);
t_vector        diffuse(t_minirt *rt);
/******************************************************************/

/**********Colors**************************************************/
int            ft_color(double ir, double ig, double ib);
t_color        colorSplit(t_minirt *rt, char *str);
void           object_coloration(t_minirt *rt);
void           light_coloration(t_minirt *rt,t_vector *l_norm,double *ratio,t_color *light_rgb);
/******************************************************************/

/***************Raytracing*****************************************/
t_color         ray_Tracing(t_minirt *rt);
t_color         hit_sphere(t_minirt *rt);
t_color         hit_objects(t_minirt *rt);
void            wich_object(t_minirt *rt,double *cmp);
void            calcul_data(t_minirt *rt);
/******************************************************************/

/***********************Linked_List  *******************************/
t_color         wich_object_color(t_minirt *rt);
void            add_list_back(t_list *(*head), t_list *last);
t_objects       *copy_spher(t_vector center, double radius, t_color color);
void            add_objects(t_objects  **objs, t_objects  *new_obj);
double          counting_list(t_list *lst);
int             ft_countObjects(t_list *lst);
t_objects       *copy_plan(t_vector point,t_vector norm, t_color color);
t_objects       *copy_triangle(t_vector point_a, t_vector point_b, t_vector point_c, t_color color);
t_objects       *copy_square(t_vector center, t_vector normal, double side_size, t_color color);
t_objects       *copy_cylindre(t_vector center, t_vector normal,double diameter,double height,t_color color);
void            print_list_sphere(t_objects *ip);
void            print_list_pal(t_objects *ip);
void            print_list_tr(t_objects *ip);
void            print_list(t_minirt *rt,t_objects *ip);
t_list_lights   *copy_light(t_vector position, double ratio, t_color color_light);
void            add_lights(t_list_lights **head, t_list_lights *new_obj);
void            print_light(t_list_lights *light);
void            print_light1(t_minirt *rt);
t_list_camera   *copy_camera(t_vector look_from, t_vector look_at, double fov);
void            add_camera(t_list_camera **head, t_list_camera *new_obj);
/**********************************************************************/

/*************************TOOLS***************************************/
int         ft_compare_end(char *str, char *end);
int         ft_count(char **str);
void        ft_node_back(t_list **head, t_list *next);
t_list      *creat_new_node(void *data);
int         ft_charCount(char *str, char c);
void        ft_stringdel(char **string);
char        **ft_free_split(char **split);
char        **ft_charSplit(char const *s, char *set);
double      convert_to_double(char *string) ;
int         ft_samestr(char *s1, char *s2);
int         resol_check(char *resolution);
double      my_power(double number, int power);
int         ft_atoi(char *str);
static int  words(char *str, char c);
char        **ft_split(char *s, char c);
int         ft_isdigit(int c);
char        *ft_strdup(char *src);
unsigned int ft_strlen(const char *s);
char         *ft_strjoin(char const *s1, char const *s2);
/***********************************************************************/
/*************************Shadows***************************************/
void wich_shadow(t_minirt *rt);
void       shadow_objects(t_minirt *rt);
/******************************************************************/

#endif // DEBUG