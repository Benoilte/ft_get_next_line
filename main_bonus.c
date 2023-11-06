/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/06 21:17:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main(void)
{
	int		fd_even;
	int		fd_odd;
	int		i;
	char	*file_even;
	char	*file_odd;
	char	*new_line;

	file_even = "even.txt";
	file_odd = "odd.txt";
	fd_even = open(file_even, O_RDONLY);
	fd_odd = open(file_odd, O_RDONLY);
	i = 0;
	if (fd_even > 0)
	{
		while (i != 60)
		{
			new_line = get_next_line(fd_even);
			// printf("\033[31mfd_even: %d\033[0m\n", fd_even);
			if (new_line)
			{
				printf("\neven_gnl: %d \n", i + 1);
				printf("%s", new_line);
				free(new_line);
			}
			new_line = get_next_line(fd_odd);
			// printf("\033[32mfd_odd: %d\033[0m\n", fd_odd);
			if (new_line)
			{
				printf("\nodd_gnl: %d \n", i + 1);
				printf("%s", new_line);
				free(new_line);
			}
			else
				break;
			i++;
		}
		close(fd_even);
		close(fd_odd);
	}
	else
		printf("error to open %s or %s file\n", file_even, file_odd);
	return (0);
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
