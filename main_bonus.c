/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/19 11:07:07 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*fd1_line;
	char	*fd2_line;

	(void)argc;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd1_line = get_next_line(fd1);
	fd2_line = get_next_line(fd2);
	while (fd1_line || fd2_line)
	{
		if (fd1_line)
			printf("%s", fd1_line);
		if (fd1_line)
			free(fd1_line);
		fd1_line = get_next_line(fd1);
		if (fd2_line)
			printf("%s", fd2_line);
		if (fd2_line)
			free(fd2_line);
		fd2_line = get_next_line(fd2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
