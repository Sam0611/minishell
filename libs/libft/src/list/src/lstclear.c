/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:37:05 by kjimenez          #+#    #+#             */
/*   Updated: 2023/02/05 18:18:08 by kjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp_lst;
	t_list	*to_clear;

	if (!lst || !del)
		return ;
	temp_lst = *lst;
	while (temp_lst)
	{
		to_clear = temp_lst;
		temp_lst = temp_lst->next;
		(*del)(to_clear->content);
		free(to_clear);
	}
	*lst = NULL;
}
