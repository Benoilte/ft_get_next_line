/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:54:17 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/03 18:42:45 by bebrandt         ###   ########.fr       */
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
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_get_line(char *stash, t_gnl_lst *lst, int *trig);
char		*ft_copy_new_line(t_gnl_lst *lst);
int			ft_check_new_line(char *str);
size_t		ft_strlen(const char *s);

// gnl_lst function

void		ft_gnl_lstadd_back(t_gnl_lst **lst, char *str, int bytes);
void		ft_gnl_lstclear(t_gnl_lst **lst);
int			ft_gnl_lstsize(t_gnl_lst *lst);

#endif
