/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orios-me <orios-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:18:26 by orios-me          #+#    #+#             */
/*   Updated: 2023/03/05 01:16:26 by orios-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int				ft_file_read(char *dictionary, char *txt);
void			ft_print(int start, char *str, char *dict);
int				ft_strlen(char *str);
void			ft_parse_perf(char *str, char *dict);
unsigned long	ft_atoi(char *str);


int	ft_verify_input(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] < '0' || argv[i] > '9')
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ft_verify_uint(char *argv)
{
	if (ft_strlen(argv) > 10)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_atoi(argv) > 4294967295)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ft_verify(int argc, char *search, char *txt)
{
	char	dictionary[999];

	if (ft_verify_input(search) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_verify_uint(search) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ft_file_read(dictionary, txt) == 0)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}	
	return (1);
}
