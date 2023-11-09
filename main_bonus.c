/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/07 22:08:24 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	// int		fd_1;
	// int		fd_2;
	// int		fd_3;
	// int		fd_4;
	// int		i;
	char	*file_1;
	char	*file_2;
	char	*file_3;
	char	*file_4;
	// char	*new_line;

	file_1 = "text1.txt";
	file_2 = "text2.txt";
	file_3 = "text3.txt";
	file_4 = "text4.txt";
	// fd_1 = open(file_1, O_RDONLY);
	// fd_2 = open(file_2, O_RDONLY);
	// fd_3 = open(file_3, O_RDONLY);
	// fd_4 = open(file_4, O_RDONLY);
	// i = 0;
	// if (fd_1 > 0 && fd_2 > 0 && fd_3 > 0 && fd_4 > 0)
	// {
			// new_line = get_next_line(fd_1);
			// if (new_line)
			// {
			// 	printf("\nfd_1: %d \n", i + 1);
			// 	printf("%s", new_line);
			// 	free(new_line);
			// }
			// new_line = get_next_line(fd_2);
			// if (new_line)
			// {
			// 	printf("\nfd_2: %d \n", i + 1);
			// 	printf("%s", new_line);
			// 	free(new_line);
			// }
			// new_line = get_next_line(fd_3);
			// if (new_line)
			// {
			// 	printf("\nfd_3: %d \n", i + 1);
			// 	printf("%s", new_line);
			// 	free(new_line);
			// }
			// new_line = get_next_line(fd_4);
			// if (new_line)
			// {
			// 	printf("\nfd_4: %d \n", i + 1);
			// 	printf("%s", new_line);
			// 	free(new_line);
			// }
	int fd_1 = open(file_1, O_RDONLY);
	int fd_2 = open(file_2, O_RDONLY);
	int fd_3 = open(file_3, O_RDONLY);
	/* 1 */ printf("%s", get_next_line(fd_1));
	/* 2 */ printf("%s", get_next_line(fd_2));
	/* 3 */ printf("%s", get_next_line(fd_3));
	/* 4 */ printf("%s", get_next_line(fd_1));
	/* 5 */ printf("%s", get_next_line(fd_2));
	/* 6 */ printf("%s", get_next_line(fd_2));
	int fd_4 = open(file_4, O_RDONLY);
	/* 7 */ printf("%s", get_next_line(fd_2));
	/* 8 */ printf("%s", get_next_line(fd_3));
	/* 9 */ printf("%s", get_next_line(fd_4));
	/* 10 */ printf("%s", get_next_line(fd_2));
	/* 11 */ printf("%s", get_next_line(fd_2));
	/* 12 */ printf("%s", get_next_line(fd_1));
	/* 13 */ printf("%s", get_next_line(fd_4));
	/* 14 */ printf("%s", get_next_line(fd_1));
	/* 15 */ printf("%s", get_next_line(fd_4));
	/* 16 */ printf("%s", get_next_line(fd_1));
	/* 17 */ printf("%s", get_next_line(fd_4));
	/* 18 */ printf("%s", get_next_line(fd_3));
	/* 19 */ printf("%s", get_next_line(fd_3));
	/* 20 */ printf("%s", get_next_line(fd_1));
	/* 21 */ printf("%s", get_next_line(fd_3));
	/* 22 */ printf("%s", get_next_line(fd_3));
	close(fd_1);
	close(fd_2);
	close(fd_3);
	close(fd_4);
	// }
	// else
	// 	printf("error to open %s or %s file\n", file_1, file_2);
	// return (0);
}

// int	main(void)
// {
// 	int		fd;
// 	int		i;
// 	char	*file;
// 	char	*new_line;

// 	file = "text.txt";
// 	fd = open(file, O_RDONLY);
// 	i = 0;
// 	if (fd > 0)
// 	{
// 		while (i != 60)
// 		{
// 			new_line = get_next_line(fd);
// 			if (new_line)
// 			{
// 				printf("\nget_next_line: %d \n", i + 1);
// 				printf("%s", new_line);
// 				free(new_line);
// 			}
// 			else
// 				break;
// 			i++;
// 		}
// 		close(fd);
// 	}
// 	else
// 		printf("error to open : %s\n", file);
// 	return (0);
// }
