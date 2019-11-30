/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:19:39 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/30 17:20:28 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_FUNCTION_H
# define _FT_FUNCTION_H
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# define SCREENSHOT_PATH	"screen.bmp"
# define BYTES_PER_PIXEL 	3
# define FILE_HEADER_SIZE	14
# define INFO_HEADER_SIZE	40

typedef struct		s_list
{
	int				wdw_height;
	int				wdw_width;
	void			*mlx_co;
	void			*mlx_wdw;
	double			x;
	double			y;
	double			speed;
	double			angle;
	double			rotate_speed;
	int				color;
	void			**mlx_wall;
	int				width;
	int				height;
	int				bitpx;
	int				endian;
	int				size_line;
	int				**cast;
	int				*new_wdw;
	int				bit_pix_wdw;
	int				size_line_wdw;
	int				endian_wdw;
	int				*data_wdw;
	int				lineheight;
	int				texx;
	int				*sprite;
	int				*sprite_data;
	int				sprite_bpx;
	int				sprite_size;
	int				sprite_endian;
	int				sprite_width;
	int				sprite_size_line;
	int				sprite_height;
	double			diry;
	double			dirx;
	double			planey;
	double			planex;
	double			*zbuffer;
	int				side;
	char			*string;
	int				fd;
	int				color_floor;
	int				color_ciel;
	int				**map;
	int				map_height;
	int				lenstring;
	int				pos_ok;
	char			*file;
	int				error;
	int				nbr_texture;
	char			**path_wall;
	char			*path_sprite;
	int 			number_path;
	int				number_sprite;
}					t_list;

typedef struct		s_sprit
{
	int				*sprite;
	int				*img;
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_prite
{
	int				texture;
	double			spritx;
	double			sprity;
	double			invdet;
	int				numsprite;
	int				*spriteorder;
	double			*spritedistance;
	double			transformx;
	double			transformy;
	int				spritescreen;
	int				spriteheight;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				drawstartx;
	int				drawendx;
	int				y_start;
	int				sprites;
	int				texx;
	int				d;
	int				y;
	int				texy;
	int				lenght;
}					t_prite;

typedef struct		s_rc
{
	double			ratio;
	double			dirx;
	double			diry;
	int				mapx;
	int				mapy;
	double			deltadistx;
	double			deltadisty;
	int				stepx;
	int				stepy;
	double			sidedistx;
	double			sidedisty;
	double			perpdualist;
	int				side;
	int				hit;
	double			wallx;
	int				drawstart;
	int				drawend;
}					t_rc;

int					ft_deal_key(int key, void *param);
void				ft_move(int nb, t_list *stock);
void				ft_position(int nb, t_list *stock);
void				ft_compass(t_list *stock);
void				ft_miniwall(int y, int x, t_list *stock);
void				ft_minimap(int **map, t_list *stock);
void				ft_draw_window(t_list *stock, int x, int ymin, int ymax);
void				ft_pixel(t_list *stock, int x, int ymin, int ymax);
void				ft_drawline(double y0, double dx, double dy, t_list *stock);
void				ft_rc(t_list *stock);
void				ft_place_sprite(t_list *stock, t_sprite *sprite);
int					ft_count_sprite(t_list *stock);
void				ft_swap(double a, double b);
int					ft_parsing(t_list *stock);
int					ft_len(char *str);
int					ft_free(t_list *stock);
int					ft_message(int number, t_list *stock);
void				ft_correct_resolution(t_list *stock);
int					ft_resolution(t_list *stock);
int					ft_bg(char *str, int order);
int					ft_check_i(int i, t_list *stock);
int					ft_open(t_list *stock);
int					ft_isnum(char c);
void				ft_adding_height(t_list *stock, int *i);
int					ft_gnl_pos(t_list *stock, char c1, char c2);
int					ft_free_error(int number, t_list *stock);
int					ft_message(int number, t_list *stock);
void				ft_putstr(char *str);
void				ft_putchar(char c);
int					ft_free(t_list *stock);
int					ft_open(t_list *stock);
int					ft_isnum(char c);
int					ft_convert(char *str);
int					ft_texture(t_list *stock);
int					ft_color(t_list *stock);
int					ft_conv(int *array, char *str);
int					ft_search_map(t_list *stock, int *i);
void				ft_player(t_list *stock, int dir, int y, int x);
int					ft_map(t_list *stock);
int					ft_check_map(t_list *stock);
int					ft_init_pos(t_list *stock);
void				ft_position(int key, t_list *stock);
void				ft_correct_pos_right(t_list *stock);
void				ft_correct_pos_left(t_list *stock);
void				ft_set(t_rc *rc, t_list *stock, int x);
void				ft_order_sprite(t_sprite *sprite, t_prite *prite,
t_list *stock);
void				ft_set_sprite(t_sprite *sprite, t_prite *prite,
t_list *stock);
void				ft_combsort(int *order, double *dist, int amount);
int					ft_count_sprite(t_list *stock);
int					ft_save(char *str, t_list *stock);
int					create_bmp(t_list *stock);
void				write_rgb(t_list *stock, int height, int width, int fd);
void				generate_bitmap_image(t_list *stock, int height, int width);
unsigned char		*create_bitmap_file_header(int height,
int width, int padding_size);
unsigned char		*create_bitmap_info_header(int height, int width);
void				ft_mlx_stop(t_list *stock);
int					ft_redcross(t_list *stock);
int					ft_cpy(char *dst, char *src);
int					ft_init_texture(t_list *stock);
int					ft_texturing(t_list *stock);
int					ft_spriting(t_list *stock);
int					ft_parsing_map(t_list *liste);
int					ft_errormap(char *str);
#endif
