/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscar <oscar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:35:09 by orios-me          #+#    #+#             */
/*   Updated: 2023/03/05 02:17:18 by oscar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int				ft_file_read(char *dictionary, char *txt);
void			ft_parse_perf(char *str, char *dict);
int				ft_verify(int argc, char *search, char *txt);
void ft_splice(char *search, char *dict, int strlen);
int	ft_strlen(char *str);


int	main(int argc, char *argv[])
{
	char	dictionary[999];
	int		status;

	status = 1;
	if (argc < 2 || argc > 3)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		status = ft_verify(argc, argv[1], "numbers.dict");
	else
		status = ft_verify(argc, argv[1], argv[2]);
	if (status == 0)
		return (0);
	if (argc == 2)
		ft_file_read(dictionary, "numbers.dict");
	else
		ft_file_read(dictionary, argv[2]);
	//ft_parse_perf(argv[1], dictionary);
	ft_splice(argv[1], dictionary, ft_strlen(argv[1]));
	return (1);
}

