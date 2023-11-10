/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/10 15:25:33 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_print_gnl(int fd1, int fd2, int fd3, int fd4);

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;

	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	fd4 = open("text4.txt", O_RDONLY);
	// ft_print_gnl(fd1, fd2, fd3, fd4);
	printf("%s\n", OPEN_MAX);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}

void	ft_print_gnl(int fd1, int fd2, int fd3, int fd4)
{
	printf("fd1 : \n%s", get_next_line(fd1));
	printf("fd2 : \n%s", get_next_line(fd2));
	printf("fd3 : \n%s", get_next_line(fd3));
	printf("fd1 : \n%s", get_next_line(fd1));
	printf("fd2 : \n%s", get_next_line(fd2));
	printf("fd2 : \n%s", get_next_line(fd2));
	printf("fd2 : \n%s", get_next_line(fd2));
	printf("fd3 : \n%s", get_next_line(fd3));
	printf("fd4 : \n%s", get_next_line(fd4));
	printf("fd2 : \n%s", get_next_line(fd2));
	printf("fd2 : \n%s", get_next_line(fd2));
	printf("fd1 : \n%s", get_next_line(fd1));
	printf("fd4 : \n%s", get_next_line(fd4));
	printf("fd1 : \n%s", get_next_line(fd1));
	printf("fd4 : \n%s", get_next_line(fd4));
	printf("fd1 : \n%s", get_next_line(fd1));
	printf("fd4 : \n%s", get_next_line(fd4));
	printf("fd3 : \n%s", get_next_line(fd3));
	printf("fd3 : \n%s", get_next_line(fd3));
	printf("fd1 : \n%s", get_next_line(fd1));
	printf("fd3 : \n%s", get_next_line(fd3));
	printf("fd3 : \n%s", get_next_line(fd3));
}
