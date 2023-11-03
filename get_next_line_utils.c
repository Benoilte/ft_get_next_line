/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:57:30 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/03 19:13:13 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Count number of element of the linked list and return the value.
*/
int	ft_gnl_lstsize(t_gnl_lst *lst)
{
	int			i;
	t_gnl_lst	*el_lst;

	i = 0;
	el_lst = lst;
	while (el_lst)
	{
		el_lst = el_lst->next;
		i++;
	}
	return (i);
}

/*
Add new elem. at the end of the list and set new->next as null
set new elem. as first elem. of the list if '*lst' is null.
*/
void	ft_gnl_lstadd_back(t_gnl_lst **lst, char *str, int bytes)
{
	t_gnl_lst	*last;
	t_gnl_lst	*new;

	new = (t_gnl_lst *)malloc(sizeof(t_gnl_lst));
	if (!new)
	{
		ft_gnl_lstclear(lst);
		return ;
	}
	new->len = bytes;
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
Allocate and return a new string from the string 's'.
This new string starts at index 'start' and has a maximum size of 'len'.
NULL is returned if the memory allocation failed.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_len;
	char			*dest;

	i = 0;
	s_len = ft_strlen((char *)s);
	if (!s_len || start > s_len - 1)
		return (ft_strdup(""));
	s += start;
	s_len -= start;
	if (len < s_len)
	{
		dest = (char *)malloc((len + 1) * sizeof(char));
		if (!dest)
			return ((void *)0);
		while (s[i] && i < len)
		{
			dest[i] = s[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (ft_strdup(s));
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
