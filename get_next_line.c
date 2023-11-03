/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:50 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/03 17:57:31 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	t_gnl_lst	*lst;
	char		*new_line;
	int			is_new_line;
	int			bytes_read;

	lst = (void *)0;
	new_line = (void *)0;
	is_new_line = 0;
	if (!ft_check_new_line(str))
		bytes_read = read(fd, str + ft_strlen(str), BUFFER_SIZE - ft_strlen(str));
	while (is_new_line == 0 && bytes_read > 0)
	{
		if (ft_gnl_lstsize(lst) != 0 && !ft_check_new_line(str))
			bytes_read = read(fd, str, BUFFER_SIZE);
		if (ft_check_new_line(str))
		{
			ft_next_line(str, lst);
			new_line = ft_copy_new_line(lst);
			is_new_line = 1;
		}
		else
			ft_gnl_lstadd_back(&lst, ft_strdup(str));
	}
	ft_gnl_lstclear(&lst);
	return (new_line);
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
char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((ft_strlen((char *)s1) + 1) * sizeof(char));
	if (!dest)
		return ((void *)0);
	i = 0;
	while (s1[i])
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
void	ft_next_line(char *stash, t_gnl_lst *lst)
{
	int			i;
	int			t;
	char		*str;

	i = 0;
	while (stash[i++] != '\n')
		;
	str = ft_substr(stash, 0, i);
	ft_gnl_lstadd_back(&lst, str);
	t = 0;
	while (stash[i])
		stash[t++] = stash[i++];
	stash[t] = '\0';
}
