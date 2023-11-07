/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:54:17 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/07 17:05:01 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl_lst
{
	char				*str;
	int					len;
	struct s_gnl_lst	*next;
}	t_gnl_lst;

char		*get_next_line(int fd);
char		*ft_read_and_check_line(int fd, char *buff, t_gnl_lst *lst);
char		*ft_get_line(char *stash, t_gnl_lst *lst);
char		*ft_copy_new_line(t_gnl_lst *lst);
char		*ft_strndup(const char *s1, size_t size);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_check_new_line(char *str);
size_t		ft_strlen(const char *s);

// gnl_lst function

void		ft_gnl_lstadd_back(t_gnl_lst **lst, char *str, size_t length);
void		*ft_gnl_lstclear(t_gnl_lst **lst);

#endif
