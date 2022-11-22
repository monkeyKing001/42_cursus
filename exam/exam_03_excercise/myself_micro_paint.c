#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ERR1 "Error : argument\n"
#define ERR2 "Error : Operation file corrupted\n"

int ft_strlen(char *str)
{
	int	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	ft_perror(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int	check_pos(float x, float y, float id_x, float id_y, float id_w, float id_h)
{
	if (x < id_x || x > id_x + id_w || y < id_y || y > id_h + id_y)
		return (0);
	else if(x - id_x < 1.00000000 || (id_x + id_w) - x < 1.00000000 ||
			y - id_y < 1.00000000 || (id_y + id_h) - y < 1.00000000)
		return (1);
	return (2);
}
int	main(int argc, char **argv)
{
	//read
	FILE *file;
	int	scan_ret;

	//paper
	int	x, y, b_w, b_h, pos;
	char	bg;
	char	*paper;
	//rec
	float id_x, id_y, id_h, id_w;
	char	color, fill;
	if (argc != 2)
		return (ft_perror(ERR1));
	file = fopen(argv[1], "r");
	if (!file ||
			(fscanf(file, "%d %d %c\n", &b_w, &b_h, &bg) != 3) ||
			(!(b_w > 0 && b_w <= 300 && b_h > 0 && b_h <= 300)) ||
			(!(paper = (char *)malloc(sizeof(char) * b_w * b_h))))
			return (ft_perror(ERR2));
	memset(paper, bg, b_w * b_h);
	while ((scan_ret = fscanf(file, "%c %f %f %f %f %c\n", &fill, &id_x, &id_y, &id_w, &id_h, &color)) == 6)
	{
		if (!(id_w > 0 && id_h > 0) || !(fill == 'R' || fill == 'r'))
			break ;
		y = -1;
		while (++y < b_h)
		{
			x = -1;
			while (++x < b_w)
			{
				pos = check_pos((float)x, (float)y, (float)(id_x), (float)(id_y), (float)(id_w), (float)(id_h));
				if (pos == 1 || (pos == 2 && fill == 'R'))
					paper[(y  * b_w) + x] = color;
			}
		}
	}
	if (scan_ret != -1)
	{
		free(paper);
		fclose(file);
		return (ft_perror(ERR2));
	}
	y = -1;
	while (++y < b_h)
	{
		write(1, paper + (y * b_w), b_w);
		write(1, "\n", 1);
	}
	free(paper);
	fclose(file);
	return (0);
}
