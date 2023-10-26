/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nprudenc <nprudenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:53:32 by nprudenc          #+#    #+#             */
/*   Updated: 2023/09/11 13:07:22 by nprudenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*temp;

	if (!lst || !del)
		return ;
	aux = *lst;
	while (aux)
	{	
		temp = aux->next;
		del(aux->vector);
		free(aux);
		aux = temp;
	}
	*lst = NULL;
}
