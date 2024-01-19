/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2024/01/19 11:04:10 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*new_line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	new_line = get_next_line(fd);
	while (new_line)
	{
		if (new_line)
		{
			printf("%s", new_line);
			free(new_line);
		}
		new_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
