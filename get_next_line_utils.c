/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:57:30 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/09 11:42:04 by bebrandt         ###   ########.fr       */
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

	if (size == 0 || ft_strlen(s1) == 0)
		return ((void *)0);
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
void	ft_gnl_lstadd_back(t_gnl_lst **lst, char *str)
{
	t_gnl_lst	*last;
	t_gnl_lst	*new;

	if (!lst)
	{
		ft_safe_free(lst, str);
		return ;
	}
	new = (t_gnl_lst *)malloc(sizeof(t_gnl_lst));
	if (!new)
	{
		ft_safe_free(lst, str);
		return ;
	}
	new->str = str;
	new->next = (void *)0;
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
void	*ft_safe_free(t_gnl_lst **lst, char *str)
{
	t_gnl_lst	*next_el;

	if (str)
		free(str);
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

int	ft_count_line_chars(t_gnl_lst *lst)
{
	int			len;
	t_gnl_lst	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	len = 0;
	while (tmp)
	{
		len += ft_strlen(tmp->str);
		tmp = tmp->next;
	}
	return (len);
}
