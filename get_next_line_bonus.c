/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:50 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/07 09:42:55 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1][4096];
	t_gnl_lst	*lst;
	int			bytes_read;
	int			str_start_len;
	int			i;

	lst = (void *)0;
	bytes_read = 1;
	while (bytes_read > 0 && fd > 0 && BUFFER_SIZE > 0)
	{
		if (!ft_check_new_line(str[fd]))
		{
			str_start_len = ft_strlen(str[fd]);
			bytes_read = read(fd, str[fd] + ft_strlen(str[fd]), BUFFER_SIZE - str_start_len);
			if (bytes_read == 0 || bytes_read < (BUFFER_SIZE - str_start_len))
				return (ft_end_line(str[fd], lst, bytes_read + str_start_len));
			else if (!ft_check_new_line(str[fd]))
			{
				ft_gnl_lstadd_back(&lst, ft_strndup(str[fd], ft_strlen(str[fd])));
				i = 0;
				while (i <= BUFFER_SIZE)
					str[fd][i++] = '\0';
			}
		}
		else
			return (ft_get_line(str[fd], lst));
	}
	if (lst)
		ft_gnl_lstclear(&lst);
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
	if (!str)
		ft_gnl_lstclear(&lst);
	ft_gnl_lstadd_back(&lst, str);
	t = 0;
	while (stash[i])
		stash[t++] = stash[i++];
	while ((t < BUFFER_SIZE) && stash[t])
		stash[t++] = '\0';
	return (ft_copy_new_line(lst));
}
