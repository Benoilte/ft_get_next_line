/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:50 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/07 15:40:34 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	t_gnl_lst	*lst;

	lst = (void *)0;
	return (ft_read_and_check_line(fd, buff, lst));
}

char	*ft_read_and_check_line(int fd, char *buff, t_gnl_lst *lst)
{
	int	bytes_r;
	int	buff_len;

	bytes_r = 1;
	while (bytes_r > 0 && fd >= 0 && BUFFER_SIZE > 0)
	{
		if (!ft_check_new_line(buff))
		{
			buff_len = ft_strlen(buff);
			if (buff_len > 0)
			{
				ft_gnl_lstadd_back(&lst, ft_strndup(buff, buff_len), buff_len);
				buff[0] = '\0';
			}
			bytes_r = read(fd, buff, BUFFER_SIZE);
			if (bytes_r >= 0 && bytes_r < BUFFER_SIZE)
			{
				buff[bytes_r] = '\0';
				return (ft_get_line(buff, lst));
			}
		}
		else
			return (ft_get_line(buff, lst));
	}
	if (lst)
		ft_gnl_lstclear(&lst);
	return ((void *)0);
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
	while (stash [i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!i && !lst)
		return ((void *)0);
	if (i)
	{
		str = ft_strndup(stash, i);
		if (!str)
			return (ft_gnl_lstclear(&lst));
		ft_gnl_lstadd_back(&lst, str, ft_strlen(str));
		t = 0;
		while (stash[i])
			stash[t++] = stash[i++];
		stash[t] = '\0';
	}
	return (ft_copy_new_line(lst));
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
		len += tmp->len;
		tmp = tmp->next;
	}
	new_line = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_line)
		return (ft_gnl_lstclear(&lst));
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
