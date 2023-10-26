/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:24:43 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/26 01:42:24 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif 

# include <libft.h>
# include <mlx.h>

typedef struct s_vi2d {
	int	x;
	int	y;
}				t_vi2d;

typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		scale;
	t_vi2d	max;
}				t_data;

t_data		*init_machine(void);
void		destroy_machine(t_data *machine);
int			check_key(int key, void *param);
void		mlx_loop_management(t_data *data);
void		put_pixel(t_data *data, int y, int x, int color);
char		*read_map(char	*map);
t_vector	*new_vector(t_data *machine, int x, int y, int z, int color);
t_list		*define_vector(t_data *machine, char **map);
void		print_list(t_list *list);
int			find_map_size(t_data *data, char *file);
void		free_map(char	**map);
void		draw_map(t_list *map, t_data *machine);
void		draw_map(t_list *map, t_data *machine);
t_list	*create_list(char *untreated_map, t_data *machine);

#endif
