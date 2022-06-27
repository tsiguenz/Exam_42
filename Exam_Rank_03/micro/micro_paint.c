/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:30:00 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/04/04 23:35:15 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_data
{
	int		width;
	int		height;
	char	bg;
	char	*map;
}			t_data;

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	c;
}			t_rect;

void	print_map(t_data *d)
{
	int	i = 0;

	while (i < d->height)
	{
		write(1, d->map + (i * d->width), d->width); 
		write(1, "\n", 1);
		i++;
	}
}

int	get_info(t_data *d, FILE *f)
{
	if (fscanf(f, "%d %d %c\n", &d->width, &d->height, &d->bg) != 3)
		return (1);
	//printf("%d %d %c\n", d->width, d->height, d->bg);
	if (d->width <= 0 || d->width > 300 || d->height <= 0 || d->height > 300)
		return (1);
	d->map = calloc(d->width * d->height, sizeof(char));
	if (d->map == NULL)
		return (2);
	memset(d->map, d->bg, d->width * d->height);
	return (0);
}

int	is_rect(t_rect *r, float y, float x)
{
	if ((x < r->x || x > r->x + r->width) || (y < r->y || y > r->y + r->height))
		return (0);
	if (x - r->x < 1.00000000 || r->x + r->width - x < 1.00000000 ||
		y - r->y < 1.00000000 || r->y + r->height - y < 1.00000000)
		return (2);
	return (1);
}

int	draw_rect(t_data *d, t_rect *r)
{
	int	i, j, ret;

	i = 0;
	if ((r->type != 'r' && r->type != 'R') || r->width <= 0 || r->height <= 0)
		return (1);
	while (i < d->height)
	{
		j = 0;
		while (j < d->width)
		{
			ret = is_rect(r, (float) i, (float) j);
			if (ret  == 2 || (ret  == 1 && r->type == 'R'))
				d->map[j + i * d->width] = r->c;
			j++;
		}
		i++;
	}
	return (0);
}

int	draw(FILE *f, t_data *d, t_rect *r)
{
	int	ret;

	(void)d;
	ret = fscanf(f, "%c %f %f %f %f %c\n", &r->type, &r->x, &r->y, &r->width, &r->height, &r->c);
	while (ret == 6)
	{
		if (draw_rect(d, r) == 1)
			return (1);
		//printf("%c %f %f %f %f %c\n", r->type, r->x, r->y, r->width, r->height, r->c);
		ret = fscanf(f, "%c %f %f %f %f %c\n", &r->type, &r->x, &r->y, &r->width, &r->height, &r->c);
	}
	if (ret == -1)
		print_map(d);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_rect	rect;
	FILE	*file = NULL;

	memset(&data, 0, sizeof(data));
	memset(&rect, 0, sizeof(rect));
	if (ac != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	file = fopen(av[1], "r");
	if (file == NULL || get_info(&data, file) == 1)
	{
		free(data.map);
		fclose(file);
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (data.map == NULL)
		return (1);
	if (draw(file, &data, &rect) == 1)
	{
		free(data.map);
		fclose(file);
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	fclose(file);
	free(data.map);
	return (0);
}
