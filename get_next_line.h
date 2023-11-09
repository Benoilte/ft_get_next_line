/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:54:17 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/09 11:05:07 by bebrandt         ###   ########.fr       */
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
	struct s_gnl_lst	*next;
}	t_gnl_lst;

char		*get_next_line(int fd);
char		*ft_read_and_check_line(int fd, char *buff, t_gnl_lst *lst);
char		*ft_get_line(char *stash, t_gnl_lst *lst);
char		*ft_copy_line(t_gnl_lst *lst);
char		*ft_strndup(const char *s1, size_t size);
int			ft_count_line_chars(t_gnl_lst *lst);
size_t		ft_check_new_line(char *str);
size_t		ft_strlen(const char *s);

// gnl_lst function

void		ft_gnl_lstadd_back(t_gnl_lst **lst, char *str);
void		*ft_safe_free(t_gnl_lst **lst, char *str);

#endif
