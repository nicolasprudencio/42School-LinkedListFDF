/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:19:55 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/26 01:49:51 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_data	*init_machine(void)
{
	t_data	*machine;

	machine = ft_calloc(1, sizeof(t_data));
	machine->mlx = mlx_init();
	machine->mlx_win = mlx_new_window(machine->mlx, WIDTH, HEIGHT, "follen");
	machine->img = mlx_new_image(machine->mlx, WIDTH, HEIGHT);
	machine->addr = mlx_get_data_addr(machine->img, &machine->bits_per_pixel,
			&machine->line_length, &machine->endian);
	return (machine);
}

int	check_key(int key, void *param)
{
	if (key == 65307)
		mlx_loop_end(param);
	return (0);
}

void	mlx_loop_management(t_data *data)
{
	mlx_key_hook(data->mlx_win, check_key, data->mlx);
	mlx_hook(data->mlx_win, 17, 1L << 17, mlx_loop_end,
		data->mlx);
	mlx_loop(data->mlx);
}

void	destroy_machine(t_data *machine)
{
	if (!machine)
		return ;
	mlx_destroy_image(machine->mlx, machine->img);
	mlx_destroy_window(machine->mlx, machine->mlx_win);
	mlx_destroy_display(machine->mlx);
	free(machine->mlx);
	free(machine);
}
