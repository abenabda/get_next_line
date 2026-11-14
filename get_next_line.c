/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenabda <abenabda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 18:39:03 by abenabda          #+#    #+#             */
/*   Updated: 2026/11/14 18:19:06 by abenabda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int main(void)
{
    static char buffer[1024];
    char *text = "Hey there are you alright ??\n";
    int fd = open("test.txt", O_RDWR | O_CREAT, 0644);
    write(fd, text ,ft_strlen(text));
    read(fd, buffer, BUFFER_SIZE);
    printf("%s", buffer);
    printf("Done !!");
    close(fd);
    return (0);
}