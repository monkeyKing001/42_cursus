/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myself_mini_paint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokwak <dokwak@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:45:22 by dokwak            #+#    #+#             */
/*   Updated: 2022/11/02 03:39:30 by dokwak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ERR1 "Error : argument\n"
#define ERR2 "Error : Operation file corrupted\n"
int	ft_strlen(char *str)
{
	int	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

int	ft_perror(char *msg)
{
	write(1, msg, ft_strlen(msg));
	return (1);
}

int	check_pos(float x, float y, float id_x, float id_y, float radius)
{
	float distance = sqrt(powf(id_x - x, 2.) + powf(id_y -y, 2.));
	if (distance <= radius)
	{
		if (radius - distance < 1.00000000)
			return (1);
		return (2);
	}
	return (0);
}
int	main(int argc, char **argv)
{
	//file
	FILE	*file;
	int		scan_ret;

	//paper
	char	*paper;
	char	bg;
	int		b_w, b_h, x, y, pos;

	//shape
	float	id_x, id_y, radius;
	char	fill, color;

	if (argc != 2)
		return (ft_perror(ERR2));
	file = fopen(argv[1], "r");
	if (!(file) ||
			!(scan_ret = fscanf(file, "%d %d %c\n", &b_w, &b_h, &bg) == 3) || 
			!(b_w > 0 && b_w <= 300 && b_h > 0 && b_h <= 300) ||
			!(paper = malloc(sizeof(char) * b_w * b_h))
			)
		return (ft_perror(ERR2));
	memset(paper, bg, b_w * b_h);
	while ((scan_ret = fscanf(file, "%c %f %f %f %c\n", &fill, &id_x, &id_y, &radius, &color)) == 5)
	{
		if (radius > 0 || )
		y = -1;
		while (++y < b_h)
		{
			x = -1;
			while (++x < b_w)
			{
				pos = check_pos((float)x, (float)y, id_x, id_y, radius);
				if (pos == 1 || (pos == 2 && fill =='C'))
					paper[y * b_w + x] = color;
			}
		}
	}

	return (0);
}
