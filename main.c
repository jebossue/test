/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:59:12 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/01 16:00:15 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	(void)argc;
	char	*line;
	int	nbrline;

	nbrline = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
/*	ft_get_next_line(fd, &line);
	printf("line1: %s\n", line);
	ft_get_next_line(fd, &line);
	printf("line2: %s\n", line);
	ft_get_next_line(fd, &line);
	printf("line3: %s\n", line);*/
//	if (get_next_line(fd, &line) != -1)
//		printf("linemain: %s\n", line);
	while (get_next_line(fd, &line) == 1)
	{
		printf("linemain%d: %s\n", nbrline, line);
		free(line);
		nbrline++;
	}
	return (0);
}
