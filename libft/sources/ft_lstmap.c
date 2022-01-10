/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpolycar <fpolycar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/15 10:50:41 by fpolycar      #+#    #+#                 */
/*   Updated: 2021/12/15 10:50:42 by fpolycar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	void	*data;
	void	*element;

	ret = 0;
	while (lst)
	{
		data = f(lst->content);
		element = ft_lstnew(data);
		if (!element)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, element);
		lst = lst->next;
	}
	return (ret);
}
