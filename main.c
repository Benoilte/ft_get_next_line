/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/03 17:33:18 by bebrandt         ###   ########.fr       */
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
		while (i != 42)
		{
			new_line = get_next_line(fd);
			printf("\nget_next_line\n");
			printf("%s\n", new_line);
			free(new_line);
			i++;
		}
		close(fd);
	}
	else
		printf("error to open : %s\n", file);
	return (0);
}
