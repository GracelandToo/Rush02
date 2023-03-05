
#include <unistd.h>

int ft_strlen(char *str);

void ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned long ft_atoi(char *str)
{
	int i;
    unsigned long b;
    long x;
	
	i = ft_strlen(str) - 1;
    b = 0;
	x = 1;
    while(i >= 0)
    {
        if(str[i] >= '0' && str[i] <= '9')
            b += (str[i] - 48) * x;
        i --;
        x *= 10;
    }
    return (b);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
