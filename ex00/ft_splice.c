#include <unistd.h>
#include <stdio.h>


void	ft_parse_perf(char *str, char *dict);
int ft_strlen(char *str);
void ft_putchar(char c);

void ft_hundred(char *str, char *dict)
{
	int i;

	i = 0;
	while (dict[i] != '\0')
	{
		if (dict[i] && dict[i + 1] == '0' && dict[i + 2] == '0')
		{
			while ((dict[i] < 'A' || dict[i] > 'Z') && \
				(dict[i] < 'a' || dict[i] > 'z'))
				i++;
			while (dict[i] != '\n')
				ft_putchar(dict[i++]);
			break ;
		}
		i++;
	}


}

void ft_place(int strlen)
{
	if (strlen == 10)
	{
		write(1, " billion ", 9);
	}
	else if (strlen > 6)
	{
		write(1, " million ", 9);
	}
	else if (strlen > 4)
	{
		write(1, " thousand ", 9);
	}
}

int ft_len(char *search, char *dict, int strlen)
{
	int i = 0;
	char print[3];

	if (strlen % 3 != 0)
	{
		if (strlen % 3 == 1)
		{
			print[0] = '0';
			print[1] = '0';
			print[2] = search[i++];
			strlen-=1;
		}
		if (strlen % 3 == 2)
		{
			print[0] = '0';
			print[1] = search[i++];
			print[2] = search[i++];
			strlen -= 2;
		}
		ft_parse_perf(print, dict);
		ft_place(ft_strlen(search));
	}
	return (strlen);
}



void ft_splice(char *search, char *dict, int strlen)
{
	int i = 0;
	char print[3];

	strlen = ft_len(search, dict, strlen);

	while (strlen > 0)
	{
		print[0] = search[i++];
		print[1] = search[i++];
		print[2] = search[i++];
		ft_parse_perf(print, dict);
		ft_place(strlen);
		write(1, " ", 1);
		strlen -= 3;
	}
}