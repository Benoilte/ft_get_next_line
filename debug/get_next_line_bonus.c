/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:50 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/06 22:33:37 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// char	*get_next_line(int fd)
// {
// 	static char	str[BUFFER_SIZE + 1];
// 	t_gnl_lst	*lst;
// 	int			bytes_read;
// 	int			str_start_len;
// 	int			i;

// 	lst = (void *)0;
// 	bytes_read = 1;
// 	while (bytes_read > 0)
// 	{
// 		if (!ft_check_new_line(str))
// 		{
// 			str_start_len = ft_strlen(str);
// 			bytes_read = read(fd, str + ft_strlen(str), BUFFER_SIZE - str_start_len);
// 			if (bytes_read == 0 || bytes_read < (BUFFER_SIZE - str_start_len))
// 				return (ft_end_line(str, lst, bytes_read + str_start_len));
// 			else if (!ft_check_new_line(str))
// 			{
// 				ft_gnl_lstadd_back(&lst, ft_strndup(str, ft_strlen(str)));
// 				i = 0;
// 				while (i <= BUFFER_SIZE)
// 					str[i++] = '\0';
// 			}
// 		}
// 		else
// 			return (ft_get_line(str, lst));
// 	}
// 	return ((void *)0);
// }

/* count number of element of the linked list and return the value.
'lst' should be the first element of the list*/
// static int	ft_lstsize(t_fd_lst *lst)
// {
// 	int	i;
// 	t_fd_lst *el_lst;

// 	i = 0;
// 	el_lst = lst;
// 	while (el_lst)
// 	{
// 		el_lst = el_lst->next;
// 		i++;
// 	}
// 	return (i);
// }

char	*get_next_line(int fd)
{
	static t_fd_lst	fd_lst;
	t_fd_lst		*tmp;
	t_fd_lst		*ptr;
	char			*new_line;

	tmp = &fd_lst;
	ptr = (void *)0;
	// printf("fd_lst = %d\n", tmp->fd);
	if (tmp->fd == 0)
		tmp->fd = fd;
	while (tmp)
	{
		if (tmp->fd == fd)
			ptr = tmp;
		tmp = tmp->next;
	}
	if (!ptr)
	{
		tmp = &fd_lst;
		while (tmp->next)
			tmp = tmp-> next;
		ptr = (t_fd_lst *)malloc(sizeof(t_fd_lst));
		if (!ptr)
			return ((void *)0);
		tmp->next = ptr;
		ptr->fd = fd;
	}
	new_line = get_next_line_fd(fd, ptr);
	return (new_line);
}

char	*get_next_line_fd(int fd, t_fd_lst *fd_lst)
{
	t_gnl_lst	*lst;
	int			bytes_read;
	int			str_start_len;
	int			i;

	lst = (void *)0;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		if (!ft_check_new_line(fd_lst->str))
		{
			str_start_len = ft_strlen(fd_lst->str);
			bytes_read = read(fd, fd_lst->str + ft_strlen(fd_lst->str), BUFFER_SIZE - str_start_len);
			if (bytes_read == 0 || bytes_read < (BUFFER_SIZE - str_start_len))
				return (ft_end_line(fd_lst->str, lst, bytes_read + str_start_len));
			else if (!ft_check_new_line(fd_lst->str))
			{
				ft_gnl_lstadd_back(&lst, ft_strndup(fd_lst->str, ft_strlen(fd_lst->str)));
				i = 0;
				while (i <= BUFFER_SIZE)
					fd_lst->str[i++] = '\0';
			}
		}
		else
			return (ft_get_line(fd_lst->str, lst));
	}
	return ((void *)0);
}

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
char	*ft_strndup(const char *s1, int size)
{
	char	*dest;
	int		i;

	if ((size_t)size > ft_strlen(s1))
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
Locates if there is a '\n' in the string 'str'.
Return 1 if yes, or NULL if there is no occurence
*/
int	ft_check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char) str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*
Copy stash in str until the '\n' included. Add str as last element of lst.
Replace stash with the part of stash behind the '\n'
*/
char	*ft_get_line(char *stash, t_gnl_lst *lst)
{
	int			i;
	int			t;
	char		*str;

	i = 0;
	while (stash[i++] != '\n')
		;
	str = ft_strndup(stash, i);
	ft_gnl_lstadd_back(&lst, str);
	t = 0;
	while (stash[i])
		stash[t++] = stash[i++];
	while ((t < BUFFER_SIZE) && stash[t])
		stash[t++] = '\0';
	return (ft_copy_new_line(lst));
}
