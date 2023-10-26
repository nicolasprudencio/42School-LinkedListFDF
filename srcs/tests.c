/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:44:26 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/13 18:47:24 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_list(t_list *list)
{
	t_vector	*temp;

	while (list)
	{
		temp = (t_vector *)list->vector;
		printf("x: %d\n", temp->x);
		list = list->next;
	}
}
