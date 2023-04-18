/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:14:40 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/17 17:31:25 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	word_counter(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			i++;
			while ((str[i] != '\'' || str[i] == '\"') && str[i] != 0)
				i++;
			j++;
		}
		if (str[i] != c)
		{
			while (str[i] != c && str[i])
				i++;
			j++;
		}
		else
			i++;
	}
	return (j);
}

static int	special_condition(char *s, char c, char c2)
{
	int	len;

	len = 0;
	if (*s == c2)
	{
		s++;
		while ((*s != c2) && *s)
		{
			s++;
			len++;
		}
		len++;
		if (*s == c2)
			len++;
	}
	else if (*s != c)
	{
		while (*s && *s != c && *s != 0)
		{
		len++;
		s++;
		}
	}
	return (len);
}

char	**split_args(char *s, char c)
{
	char	**str;
	int		len;
	int		i;
	char	c2;

	str = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!str)
		return (0);
	i = 0;
	while (*s)
	{
		if ((*s == '\'' || *s == '"') || *s != c)
		{
			if (*s == '\'' || *s == '"')
				c2 = *s;
			len = 0;
			len = special_condition(s, c, c2);
			s += len;
			str[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	str[i] = 0;
	return (str);
}
