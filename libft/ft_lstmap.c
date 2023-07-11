/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 08:38:52 by shikim            #+#    #+#             */
/*   Updated: 2023/04/04 15:36:40 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;
	void	*temp_content;

	new_list = 0;
	while (lst != 0)
	{
		temp_content = lst->content;
		new_content = f(temp_content);
		new_node = ft_lstnew(new_content);
		if (new_node == 0)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (0);
		}
		if (new_list == 0)
			new_list = new_node;
		else
			ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
