#include <unistd.h>
void ft_putchar(char c);

void ft_thousand(char *dict)
{
	int i;

	i = 0;
	while (dict[i] != '\0')
	{
		if (dict[i] == '1' && dict[i + 1] == '0' && dict[i + 2] == '0' && \
			dict[i + 3] == '0' && dict[i + 4] == ':')
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

void ft_million(char *dict)
{
	int i;

	i = 0;
	while (dict[i] != '\0')
	{
		if (dict[i] == '1' && dict[i + 1] == '0' && dict[i + 2] == '0' && \
			dict[i + 3] == '0' && dict[i + 4] == '0' && dict[i + 5] == '0' && \
			dict[i + 6] == '0' && dict[i + 7] == ':')
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

void ft_billion(char *dict)
{
	int i;

	i = 0;
	while (dict[i] != '\0')
	{
		if (dict[i] == '1' && dict[i + 1] == '0' && dict[i + 2] == '0' && \
			dict[i + 3] == '0' && dict[i + 4] == '0' && dict[i + 5] == '0' && \
			dict[i + 6] == '0' && dict[i + 7] == '0' && dict[i + 8] == '0')
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

void ft_place(int strlen, char *dict)
{
	if (strlen == 10)
	{
		ft_billion(dict);
	}
	else if (strlen > 6)
	{
		ft_million(dict);
	}
	else if (strlen >= 4)
	{
		ft_thousand(dict);
	}
	write(1, " ", 1);
}