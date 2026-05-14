/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txs_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogo <diogo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:36:11 by diogo             #+#    #+#             */
/*   Updated: 2026/05/14 20:30:47 by diogo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/parsing.h"

int	parse_textures(t_textures *texs)
{
	int	fd;
	int	i;

	i = 0;
	while (i < 4)
	{
		if (extension_checker(texs->t_strings[i], ".xpm"))
			return (ft_putstr_fd(ERR_TEX_EXT, 2), 1);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		fd = open(texs->t_strings[i], O_RDONLY);
		if (fd < 0)
			return (ft_putstr_fd(ERR_TEX_OPEN, 2), 1);
		close (fd);
		i++;
	}
	return (0);
}

int	extension_checker(char *av, char *ext)
{
	int	len;

	len = ft_strlen(av);
	if (len < 5 || ft_strnstr (av, ext, len) == NULL)
		return (1);
	if (ft_strncmp(&av[len - 4], ext, 4) || av[len - 5] == '/')
		return (1);
	return (0);
}

int	is_row_closed(char *row, int i)
{
	int	j;

	j = 1;
	while (row [i - j])
	{
		if (row [i - j] == '1')
			break ;
		if (row [i - j] == ' ')
			return (0);
		j++;
	}
	if (!row[i - j])
		return (0);
	j = 1;
	while (row [i + j])
	{
		if (row [i + j] == '1')
			break ;
		if (row [i + j] == ' ')
			return (0);
		j++;
	}
	if (!row[i + j])
		return (0);
	return (1);
}

int	is_nl_valid(char *file, int i)
{
	while (file[i])
	{
		if (file[i] == '\n' && file[i + 1] == '\n')
		{
			while (file[i] == '\n')
				i++;
			if (!file [i])
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi_rgb(const char *nptr)
{
	unsigned int	i;
	unsigned int	sign;
	int				result;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] <= 13 && nptr[i] >= 9) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	if (nptr[i])
		return (-1);
	return (result * sign);
}
