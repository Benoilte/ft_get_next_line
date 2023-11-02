/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebrandt <benoit.brandt@proton.me>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:50 by bebrandt          #+#    #+#             */
/*   Updated: 2023/11/02 16:39:23 by bebrandt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*text;

	text = (char *)calloc(sizeof(char), BUFFER_SIZE);
	read(fd, text, BUFFER_SIZE);
	printf("%s", text);
	free(text);
	return ("hello world");
}
