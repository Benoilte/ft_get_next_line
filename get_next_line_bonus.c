/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:50 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/09 11:31:56 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[4096][BUFFER_SIZE + 1];
	t_gnl_lst	*lst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((void *)0);
	lst = (void *)0;
	return (ft_read_and_check_line(fd, buff[fd], lst));
}

char	*ft_read_and_check_line(int fd, char *buff, t_gnl_lst *lst)
{
	int		bytes_r;
	size_t	buff_len;
	char	*str;

	while (!ft_check_new_line(buff))
	{
		buff_len = ft_strlen(buff);
		if (buff_len > 0)
		{
			str = ft_strndup(buff, buff_len);
			if (!str)
				return (ft_safe_free(&lst, (void *)0));
			ft_gnl_lstadd_back(&lst, str);
			buff[0] = '\0';
		}
		bytes_r = read(fd, buff, BUFFER_SIZE);
		if (bytes_r < 0)
			return (ft_safe_free(&lst, (void *)0));
		if (bytes_r >= 0 && bytes_r < BUFFER_SIZE)
		{
			buff[bytes_r] = '\0';
			return (ft_get_line(buff, lst));
		}
	}
	return (ft_get_line(buff, lst));
}

/*
Locates if there is a '\n' in the string 'str'.
Return 1 if yes, or NULL if there is no occurence
*/
size_t	ft_check_new_line(char *str)
{
	size_t	i;

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
	size_t			i;
	size_t			t;
	char			*str;

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
			return (ft_safe_free(&lst, (void *)0));
		ft_gnl_lstadd_back(&lst, str);
		t = 0;
		while (stash[i])
			stash[t++] = stash[i++];
		stash[t] = '\0';
	}
	return (ft_copy_line(lst));
}

/*
Go through lst and concatenate all str member together.
Return a new string corresponding to a new line.
*/
char	*ft_copy_line(t_gnl_lst *lst)
{
	int			len;
	int			i;
	int			k;
	char		*line;
	t_gnl_lst	*tmp;

	len = ft_count_line_chars(lst);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (ft_safe_free(&lst, (void *)0));
	tmp = lst;
	i = 0;
	while (tmp)
	{
		k = 0;
		while (tmp->str[k])
			line[i++] = tmp->str[k++];
		tmp = tmp->next;
	}
	line[i] = '\0';
	ft_safe_free(&lst, (void *)0);
	return (line);
}
