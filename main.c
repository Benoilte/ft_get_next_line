/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:58:52 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/02 16:40:18 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char 	*file;

	file = "test.txt";
	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		get_next_line(fd);
		get_next_line(fd);
		get_next_line(fd);
		close(fd);
	}
	else
		printf("error to open : %s\n", file);

	return (0);
}
