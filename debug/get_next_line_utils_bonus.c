/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:57:30 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/06 18:37:50 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
Add new elem. at the end of the list and set new->next as null
set new elem. as first elem. of the list if '*lst' is null.
*/
void	ft_gnl_lstadd_back(t_gnl_lst **lst, char *str)
{
	t_gnl_lst	*last;
	t_gnl_lst	*new;

	new = (t_gnl_lst *)malloc(sizeof(t_gnl_lst));
	if (!new)
	{
		ft_gnl_lstclear(lst);
		return ;
	}
	new->str = str;
	new->next = (void *)0;
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

/*
Deletes and free the memory of the element passed as parameter
and all the following elements
*/
void	ft_gnl_lstclear(t_gnl_lst **lst)
{
	t_gnl_lst	*next_el;

	if (!lst)
		return ;
	while (*lst)
	{
		next_el = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = next_el;
	}
	free(*lst);
	*lst = (void *)0;
}

/*
Go through lst and concatenate all str member together.
Return a new string corresponding to a new line.
*/
char	*ft_copy_new_line(t_gnl_lst *lst)
{
	int			len;
	char		*str;
	char		*new_line;
	t_gnl_lst	*tmp;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		len += ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	new_line = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return ((void *)0);
	tmp = lst;
	while (tmp)
	{
		str = tmp->str;
		while (*str)
			*new_line++ = *str++;
		tmp = tmp->next;
	}
	*new_line = '\0';
	ft_gnl_lstclear(&lst);
	return (new_line - len);
}


char	*ft_end_line(char *stash, t_gnl_lst *lst, int bytes)
{
	char		*str;

	if (ft_check_new_line(stash))
		return (ft_get_line(stash, lst));
	stash[bytes] = '\0';
	if (bytes == 0)
		return ((void *)0);
	str = ft_strndup(stash, ft_strlen(stash));
	ft_gnl_lstadd_back(&lst, str);
	stash[0] = '\0';
	return (ft_copy_new_line(lst));
}
