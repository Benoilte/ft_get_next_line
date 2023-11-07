/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:57:30 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/07 17:14:06 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
Returns number of characters that precede the terminating NULL character
*/
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*
Allocates sufficient memory for a copy of the string s1, does the copy, and
returns a pointer to it. If insufficient memory is available, NULL is returned
*/
char	*ft_strndup(const char *s1, size_t size)
{
	char		*dest;
	size_t		i;

	if (size > ft_strlen(s1))
		size = ft_strlen(s1);
	dest = (char *)malloc((size + 1) * sizeof(char));
	if (!dest)
		return ((void *)0);
	i = 0;
	while (s1[i] && i < size)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
Add new elem. at the end of the list and set new->next as null
set new elem. as first elem. of the list if '*lst' is null.
*/
void	ft_gnl_lstadd_back(t_gnl_lst **lst, char *str, size_t length)
{
	// t_gnl_lst	*last;
	t_gnl_lst	*new;

	new = (t_gnl_lst *)malloc(sizeof(t_gnl_lst));
	if (!new || !str || !lst)
	{
		ft_gnl_lstclear(lst);
		return ;
	}
	new->len = length;
	new->next = (void *)0;
	if (!*lst)
		new->str = str;
	else
	{
		new->str = ft_strjoin((*lst)->str, str);
		ft_gnl_lstclear(lst);
		free(str);
	}
	*lst = new;
	// if (!*lst)
	// 	*lst = new;
	// else
	// {
	// 	last = *lst;
	// 	while (last->next)
	// 		last = last->next;
	// 	last->next = new;
	// }
}

/*
Deletes and free the memory of the element passed as parameter
and all the following elements
*/
void	*ft_gnl_lstclear(t_gnl_lst **lst)
{
	t_gnl_lst	*next_el;

	if (!lst)
		return ((void *)0);
	while (*lst)
	{
		next_el = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = next_el;
	}
	free(*lst);
	*lst = (void *)0;
	return ((void *)0);
}

/*
Allocate and returns a new string resulting from the concatenation 
of s1 and s2. returns the new string; NULL if the memory allocation failed.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen((s1));
	s2_len = ft_strlen((s2));
	dest = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!dest)
		return ((void *)0);
	i = 0;
	while (*s1)
		dest[i++] = *s1++;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}
