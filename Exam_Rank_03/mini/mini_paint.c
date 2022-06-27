/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:30:00 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/04/05 00:08:45 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_data
{
	int		width;
	int		height;
	char	bg;
	char	*map;
}			t_data;

typedef struct s_cir
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	c;
}			t_cir;

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
	if (d->width <= 0 || d->width > 300 || d->height <= 0 || d->height > 300)
		return (1);
	d->map = calloc(d->width * d->height, sizeof(char));
	if (d->map == NULL)
		return (2);
	memset(d->map, d->bg, d->width * d->height);
	return (0);
}

int	is_cir(t_cir *c, float y, float x)
{
	float	dist = sqrtf(powf(x - c->x, 2) + powf(y - c->y, 2));

	if (dist - c->radius > 0.00000000)
		return (0);
	if (dist - c->radius > -1.00000000)
		return (2);
	return (1);
}

int	draw_cir(t_data *d, t_cir *c)
{
	int	i, j, ret;

	i = 0;
	if ((c->type != 'c' && c->type != 'C') || c->radius <= 0)
		return (1);
	while (i < d->height)
	{
		j = 0;
		while (j < d->width)
		{
			ret = is_cir(c, (float) i, (float) j);
			if (ret == 2 || (ret  == 1 && c->type == 'C'))
				d->map[j + i * d->width] = c->c;
			j++;
		}
		i++;
	}
	return (0);
}

int	draw(FILE *f, t_data *d, t_cir *c)
{
	int	ret;

	(void)d;
	ret = fscanf(f, "%c %f %f %f %c\n", &c->type, &c->x, &c->y, &c->radius, &c->c);
	while (ret == 5)
	{
		if (draw_cir(d, c) == 1)
			return (1);
		//printf("%c %f %f %f %f %c\n", c->type, c->x, c->y, c->width, c->height, c->c);
		ret = fscanf(f, "%c %f %f %f %c\n", &c->type, &c->x, &c->y, &c->radius, &c->c);
	}
	if (ret == -1)
		print_map(d);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_cir	cir;
	FILE	*file = NULL;

	memset(&data, 0, sizeof(data));
	memset(&cir, 0, sizeof(cir));
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
	if (draw(file, &data, &cir) == 1)
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
