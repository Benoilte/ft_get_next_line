/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/06 15:41:46 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*file;
	char	*new_line;

	file = "text.txt";
	fd = open(file, O_RDONLY);
	i = 0;
	if (fd > 0)
	{
		while (i != 60)
		{
			new_line = get_next_line(fd);
			if (new_line)
			{
				// printf("\nget_next_line: %d \n", i + 1);
				printf("%s", new_line);
				free(new_line);
			}
			else
				break;
			i++;
		}
		close(fd);
	}
	else
		printf("error to open : %s\n", file);
	return (0);
}
