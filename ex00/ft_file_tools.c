/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:57:05 by orios-me          #+#    #+#             */
/*   Updated: 2023/03/05 03:33:24 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c);
void ft_hundred(char *str, char *dict);


void	ft_print(int start, char c, char *dict)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c != dict[start])
		start++;
	while ((dict[start] < 'A' || dict[start] > 'Z') && \
		(dict[start] < 'a' || dict[start] > 'z'))
		start++;
	while (dict[start] != '\n')
		ft_putchar(dict[start++]);
	write(1, " ", 1);
}

int	ft_print_mid(char *str, char *dict)
{
	int	result;

	result = 1;
	if (str[1] == '0' && str[2] == '0')
		result = 3;
	else if (str[1] == '0')
		result = 1;
	else if (str[1] == '1')
	{
		ft_print(75, str[2], dict);
		result = 3;
	}
	else if (str[1] > '1' && str[2] == '0')
	{
		ft_print(140, str[1], dict);
		result = 3;
	}
	else
		ft_print(190, str[1], dict);
	return (result);
}

void	ft_parse_perf(char *str, char *dict)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (i == 0)
		{
			if (str[i] == '0')
			{	
				i++;
				continue ;
			}
			ft_print(0, str[i], dict);
			ft_hundred(str, dict);
		}
		if (i == 1)
		{
			i = ft_print_mid(str, dict);
		}
		if (i == 2)
		{
			ft_print(0, str[i], dict);
		}
		i++;
	}
}

int	ft_file_read(char *dictionary, char *txt)
{
	int	file_no;
	int	i;

	i = 0;
	file_no = open(txt, O_RDONLY);
	if (file_no < 0)
	{
		return (0);
	}
	if (read(file_no, dictionary, 998) < 0)
	{
		return (0);
	}
	return (1);
}
