/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:30:21 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/26 01:47:26 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > WIDTH - 1 || y < 0 || y > HEIGHT - 1)
		return ;
	dst = data->addr + ((-y + HEIGHT) * data->line_length + x
			* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	main(int argc, char **argv)
{
	t_list	*map;
	t_list	*head;
	t_data	*machine;

	machine = init_machine();
	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments in argc passed to call!\n", 0);
		return (1);
	}
	map = create_list(argv[1], machine);
	if (!map)
	{
		destroy_machine(machine);
		ft_putstr_fd("Invalid map!", 0);
		return (1);
	}
	head = map;
	draw_map(map, machine);
	mlx_loop_management(machine);
	destroy_machine(machine);
	ft_lstclear(&head, free);
	return (0);
}
