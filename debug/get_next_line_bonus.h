/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:54:17 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/06 20:48:05 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (42)
# endif

typedef struct s_gnl_lst
{
	char				*str;
	int					len;
	struct s_gnl_lst	*next;
}	t_gnl_lst;

typedef struct s_fd_lst
{
	int					fd;
	char				str[BUFFER_SIZE + 1];
	struct s_gnl_lst	*gnl;
	struct s_fd_lst		*next;
}	t_fd_lst;

char		*get_next_line(int fd);
char		*get_next_line_fd(int fd, t_fd_lst *fd_lst);
char		*ft_strndup(const char *s1, int size);
char		*ft_get_line(char *stash, t_gnl_lst *lst);
char		*ft_end_line(char *stash, t_gnl_lst *lst, int bytes);
char		*ft_copy_new_line(t_gnl_lst *lst);
int			ft_check_new_line(char *str);
size_t		ft_strlen(const char *s);

// gnl_lst function

void		ft_gnl_lstadd_back(t_gnl_lst **lst, char *str);
void		ft_gnl_lstclear(t_gnl_lst **lst);

#endif
