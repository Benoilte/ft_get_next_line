/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/10 10:27:48 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*new_line;

	fd = open("text.txt", O_RDONLY);
	i = 0;
	while (i != 1000)
	{
		new_line = get_next_line(fd);
		if (new_line)
		{
			printf("\nget_next_line: %d \n", i + 1);
			printf("%s", new_line);
			free(new_line);
		}
		else
			break ;
		i++;
	}
	close(fd);
	return (0);
}
