/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:50 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/03 07:25:18 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	text[BUFFER_SIZE + 1];
	int	i = 0;
	int	n = BUFFER_SIZE + 2;

	while (n)
	{
		printf("téxt[%d]: %c\n", i, text[i]);
		i++;
		n--;
	}
	printf("str_len: %d\n", i);
	printf("1: %s\n", text);
	read(fd, text, BUFFER_SIZE);
	printf("2: %s\n", text);
	printf("---------------\n");
	return ("hello world");
}
