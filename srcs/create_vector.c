/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:50:41 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/08 20:22:12 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_vector	*new_vector(t_data *machine, int x, int y, int z, int color)
{
	t_vector	*vector;
	int			scale;
	int			offset_x;
	int			offset_y;

	if (WIDTH / (machine->max.y - 1) < HEIGHT / (machine->max.x - 1))
		scale = WIDTH / (machine->max.y - 1);
	else
		scale = HEIGHT / (machine->max.x - 1);
	offset_x = machine->max.x / 2;
	offset_y = machine->max.y / 2;
	vector = (t_vector *)malloc(sizeof(t_vector));
	vector->x = (x - offset_x) * scale;
	vector->y = (y - offset_y) * scale;
	// printf("y: %d\n", vector->y);
	vector->z = z * ((scale / 3));
	vector->color = color;
	machine->scale = scale;
	return (vector);
}

t_list	*define_vector(t_data *machine, char **map)
{
	int		x;
	int		y;
	t_list	*head;
	int		i;

	y = 0;
	i = -1;
	head = NULL;
	while (y < machine->max.y)
	{		
		x = 0;
		while (x < machine->max.x && map[++i])
		{	
			if (ft_strchr(map[i], ','))
				ft_lstadd_back(&head, ft_lstnew(new_vector(machine, x, y,
							ft_atoi(map[i]),
							ft_atox(ft_strchr(map[i], ',')))));
			else
				ft_lstadd_back(&head, ft_lstnew(new_vector(machine, x, y,
							ft_atoi(map[i]), 0xFFFFFF)));
			x++;
		}
		y++;
	}
	return (head);
}

t_list	*create_list(char *untreated_map, t_data *machine)
{
	char	*map;
	char	**treated_map;
	t_list	*head;

	map = read_map(untreated_map);
	find_map_size(machine, map);
	if (machine->max.x <= 1 || machine->max.y <= 1)
	{
		free(map);
		return (NULL);
	}
	treated_map = ft_split(map, ' ');
	head = define_vector(machine, treated_map);
	free_map(treated_map);
	free(map);
	return (head);
}
