/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/18 15:22:14 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*new_line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (i != 1000)
	{
		new_line = get_next_line(fd);
		if (new_line)
		{
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
