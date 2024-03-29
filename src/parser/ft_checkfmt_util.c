/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfmt_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:43:26 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/29 22:55:08 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	ft_not(char *str, int mode)
{
	int	i;

	i = 0;
	if (mode == NOT_NBR_POINT_MINUS)
	{
		while (str[i])
		{
			if ((str[i] < '0' || str[i] > '9') \
			&& str[i] != '.' && str[i] != '-')
				return (-1);
			i++;
		}
		return (0);
	}
	return (0);
}

int	ft_not2(char *str, int mode)
{
	int	i;

	i = 0;
	if (mode == NOT_NBR_POINT)
	{
		while (str[i])
		{
			if ((str[i] < '0' || str[i] > '9') \
			&& str[i] != '.' && str[i] != '\n')
				return (-1);
			i++;
		}
		return (0);
	}
	if (mode == NOT_NBR_MINUS)
	{
		while (str[i])
		{
			if ((str[i] < '0' || str[i] > '9') && str[i] != '-')
				return (-1);
			i++;
		}
		return (0);
	}
	return (0);
}

int	ft_check_float(char *str)
{
	int		len_point;
	char	**sp_float;
	int		i;
	int		len;

	sp_float = ft_split(str, ',');
	i = 0;
	len = ft_cnt2d(sp_float);
	while (sp_float[i])
	{
		len_point = ft_count_char(sp_float[i], '.');
		if (len_point > 1 || ft_not(sp_float[i], NOT_NBR_POINT_MINUS) == -1)
		{
			ft_doublefree(sp_float);
			return (-1);
		}
		i++;
	}
	ft_doublefree(sp_float);
	return (0);
}

int	ft_notnbr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_count_char(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}
