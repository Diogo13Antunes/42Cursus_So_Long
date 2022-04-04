/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcandeia <dcandeia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:08:18 by dcandeia          #+#    #+#             */
/*   Updated: 2022/04/04 10:33:24 by dcandeia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//================================= Defines ====================================
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <time.h>
# include "get_next_line.h"
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define I_BORDER 		"imagens/border_icon.xpm"
# define I_GROUND 		"imagens/ground_icon.xpm"
# define I_CHERRY 		"imagens/cherry_icon.xpm"
# define I_EXIT_OPEN 	"imagens/exit_icon_open.xpm"
# define I_EXIT_CLOSE 	"imagens/exit_icon_close.xpm"
# define I_PACMAN1 		"imagens/pacman_icon_1.xpm"
# define I_PACMAN2 		"imagens/pacman_icon_2.xpm"
# define I_PACMAN3 		"imagens/pacman_icon_3.xpm"
# define I_PACMAN4 		"imagens/pacman_icon_4.xpm"
# define I_GHOST1 		"imagens/ghost_roxinho_icon_1.xpm"
# define I_GHOST2 		"imagens/ghost_roxinho_icon_2.xpm"
# define I_GHOST3 		"imagens/ghost_roxinho_icon_3.xpm"
# define I_GHOST4 		"imagens/ghost_roxinho_icon_4.xpm"
# define TRUE 			1
# define FALSE 			0
# define WHITE			"\e[1;37m"
# define GREEN			"\e[1;32m"
# define RESET			"\e[0m"
//================================= Structs ====================================
typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		size;
}				t_image;
typedef struct s_wind
{
	int			lenght;
	int			width;
}				t_wind;
typedef struct s_pict
{
	t_image		ground;
	t_image		wall;
	t_image		exit_close;
	t_image		exit_open;
	t_image		collectible;
	t_image		player1;
	t_image		player2;
	t_image		player3;
	t_image		player4;
	t_image		ghost1;
	t_image		ghost2;
	t_image		ghost3;
	t_image		ghost4;
}				t_pict;
typedef struct s_elements
{
	int				c;
	int				e;
	int				p;
}				t_elements;
typedef struct s_map
{
	t_pict		pictures;
	char		**map;
	int			steps;
}				t_map;
//================================== So_Long ===================================
int		so_long(int fd);
void	so_long2(void);
//================================ Player Stuff ================================
int		*player_pos(char c);
int		find_player_pos(void);
//================================= Enemy Stuff ================================
int		*enemy_pos(char choice);
int		exist_enemy(t_map map);
void	enemy_moves(t_map map);
int		enemy(t_map *map);
int		enemy_make_move(t_map map, int new_x, int new_y, int rotation);
void	enemy_rotate_move(t_pict pictures, int rotation);
//================================= Moves Stuff ================================
int		make_moves(int keycode, t_map *map);
int		make_rotation(int keycode);
//================================ Screen Stuff ================================
void	**start_program(void);
t_wind	window_size(char **map);
void	**wind_new(void);
void	wind_open(void);
int		key(int keycode, t_map *map);
t_image	image_creator(char *path);
void	wall_printing(t_pict pictures, int keycode);
t_pict	pictures_creator(void);
//================================= Map Stuff ==================================
t_list	**map(void);
char	***arr_map(void);
void	error_msg(char *error);
void	get_map(int fd);
void	check_map_rules(void);
int		map_len(void);
int		check_top_bot(void);
int		check_border(void);
void	check_elements(void);
void	errors_elements(t_elements elem);
int		check_map_build(void);
void	matrix_map(void);
void	map_printers(int choice);
//=================================== Utils ====================================
int		ft_putstr(char *s);
char	*ft_strrchr(const char *str, int c);
char	*ft_itoa(long int nbr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	free_mem(t_pict pictures);
int		leave_game(t_pict pictures);
//==============================================================================

#endif