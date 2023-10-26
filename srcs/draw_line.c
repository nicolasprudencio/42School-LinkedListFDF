/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:15:25 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/26 01:24:14 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	to_isometric(t_list *map)
{
	t_list		*head;
	double		pi_div;
	double		radians_cos;
	double		radians_sin;
	int			old_x;

	head = map;
	pi_div = M_PI / 180;
	radians_cos = cos(45 * (pi_div));
	radians_sin = sin(-30 * (pi_div));
	while (head)
	{	
		old_x = head->vector->x;
		head->vector->x = (head->vector->x - head->vector->y) * radians_cos;
		head->vector->y = (-head->vector->z + old_x + head->vector->y) * radians_sin;
		head = head->next;
	}
}

void	draw_line(t_vector *beg, t_vector *end, int color, t_data *machine)
{
	double	t;
	int		x;
	int		y;
	double	precision;

	t = 0;
	precision = 0.001;
	while (t <= 1)
	{
		x = ((1 - t) * beg->x + (t * end->x)) + (WIDTH / 2);
		y = ((1 - t) * beg->y + (t * end->y)) + (HEIGHT / 2);
		put_pixel(machine, x, y, color);
		t += precision;
	}
}

void	draw_map(t_list *map, t_data *machine)
{
	t_list		*current;
	t_list		*line_up;
	int			i;
	int			col_counter;
	int			first_pos;

	current = map;
	line_up = current;
	first_pos = line_up->vector->y;
	while (line_up->vector->y == first_pos)
		line_up = line_up->next;
	to_isometric(map);
	i = 0;
	col_counter = 0;
	while (current->next)
	{
		if (i < machine->max.x - 1)
		{
			draw_line(current->vector, current->next->vector,
				current->vector->color, machine);
		}
		if (line_up && col_counter < machine->max.y - 1)
		{
			draw_line(current->vector, line_up->vector,
				current->vector->color, machine);
			line_up = line_up->next;
		}
		if (++i == machine->max.x)
		{
			i = 0;
			col_counter++;
		}	
		current = current->next;
	}
	mlx_put_image_to_window(machine->mlx, machine->mlx_win, machine->img, 0, 0);
}		
