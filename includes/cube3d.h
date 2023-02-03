/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:00:29 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/03 09:34:45 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"

# define NB_CHAR 7
# define NB_CHAR_B 10
# define FOV 90
# define HEIGTH 720
# define WIDTH 1080
# define SPEED 0.05f
# define SENSI 0.05f
# define MSIZE 30
# define MPSIZE 6
# define MPLAYERSIZE 10
# define MWALLCOLOR 6109329 
# define MOTHERCOLOR 15262434
# define MPLAYERCOLOR 16356375
# define IMGS 256

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

typedef struct s_pos
{
	int	x;
	int	y;
}t_pos;

typedef struct s_posd
{
	double	x;
	double	y;
}t_posd;

typedef struct s_input
{
	int	b_front;
	int	b_back;
	int	b_right;
	int	b_left;
	int	b_rot_right;
	int	b_rot_left;
}t_input;

typedef struct s_line
{
	int				drawstart;
	int				drawend;
	unsigned int	color;
	int				ipix;
}t_line;

typedef struct s_ray
{
	int		ipix;
	t_posd	deltadist;
	t_posd	sidedist;
	t_pos	map;
	t_pos	step;
	double	walldist;
	int		lineheight;
	int		drawstart;
	int		drawend;
	t_data	*frame;
}t_ray;

typedef struct s_raycst
{
	t_posd	raydir;
	int		i;
	double	w;
	t_data	frame;
	t_data	minimap;
	t_data	playermini;
	double	camx;
}t_raycst;

typedef struct s_ptex
{
	int				texnum;
	double			wallx;
	int				tex_x;
	double			step;
	double			texpos;
	double			tex_y;
	int				y;
	unsigned int	color;
	t_ray			*ray;
}t_ptex;

typedef struct s_player
{
	t_pos	case_pos;
	t_posd	pos;
	t_posd	plane;
	int		fov;
	double	dir;
	t_posd	rotation;
	int		speed;
}t_player;

typedef struct s_texture
{
	unsigned int		*txts[4];
	char				*n_texture;
	char				*s_texture;
	char				*w_texture;
	char				*e_texture;
	t_data				no;
	t_data				so;
	t_data				we;
	t_data				ea;
}t_texture;

typedef struct s_system
{
	int			argc;
	char		**argv;
	char		*mapfile;
	char		sprite[10];
	char		**map;
	char		**minimap;
	int			init_ok;
	char		**play_map;
	void		*mlx;
	void		*mlx_win;
	int			end;
	int			sizex;
	int			sizey;
	int			front;
	int			rotate;
	t_player	*player;
	t_texture	*txt;
	t_data		*frame;
	t_input		input;
	long		back_color[2];
}t_system;

//				PARSING				//
void	*ft_memchr_cb(const void *s, int c, size_t n);
void	*ft_memcpy_cb(void *dest, const void *src, size_t n);
char	*ft_strtrim_cb(char *s1, char *set);
int		pars_hub(t_system *sys);
int		free_char_tab(char **tab);
char	**ft_split_cb(char const *s, char c);
int		print_char_tab(char **tab);
int		ft_strlen_cb(char *str);
int		verif_format_no(t_system *sys);
int		verif_format_so(t_system *sys);
int		verif_format_we(t_system *sys);
int		verif_format_ea(t_system *sys);
char	*ft_itoa_base_cub(int nbr, int len);
int		ft_atoi_base(char *str, char *base);
char	*ft_strdup_cb(const char *s);
char	**make_map(t_system *sys);
void	make_tab_char(char *tab);
int		exe_hub(t_system	*sys);
int		raycasting(t_system	*sys, t_player *player, double div);
void	ft_minimap(t_data *minimap, t_data *player, t_system *sys);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_line line, t_data *frame);
int		print_mini2(t_system *sys, int posox, int posoy, t_pos *pos);
void	print_mini(t_data *frame, t_system *sys, int posox, int posoy);
void	init_minimap(t_system *sys, int i, int j, int k);
void	free_all_cb(t_system *sys);
char	*ft_strjoin_cub(char *s1, char *s2);
char	*remove_nl(char *str);
int		check_rgb(char **s, int ln, int count, int comac);

#endif