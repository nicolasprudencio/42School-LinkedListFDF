/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:45:29 by nprudenc          #+#    #+#             */
/*   Updated: 2023/10/26 01:18:14 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

char	*read_map(char *map)
{
	char	*lines;
	char	*aux;
	int		fd;
	char	*temp;

	fd = open(map, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Invalid map, please type a valid map!\n", 0);
		exit(2);
	}
	lines = ft_strdup("");
	temp = lines;
	aux = get_next_line(fd);
	while (aux)
	{	
		lines = ft_strjoin(lines, aux);
		free(temp);
		temp = lines;
		free(aux);
		aux = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

int	find_map_size(t_data *data, char *file)
{
	int	i;

	i = -1;
	while (file[++i])
	{	
		if (file[i] == '\n')
		{	
			file[i] = ' ';
			data->max.y++;
		}
		if (data->max.y == 0 && file[i] != ' ' && (file[i + 1] == ' '
				|| file[i + 1] == '\n'))
			data->max.x++;
	}
	return (data->max.x * data->max.y);
}
