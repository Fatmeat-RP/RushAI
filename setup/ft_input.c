#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*getinput(void)
{
	int	i;
	int	n;
	char *str;
	char c;

	i = 0;
	n = 0;
	str = (char*)malloc(sizeof(char) * 15);
	if (!str)
		return (0);
	while (42)
	{
		c = getchar();
		if (c == 'x')
		{
			free(str);
			return (NULL);
		}
		str[i] = c;
		i++;
		if (c == '\n')
		{
			i = 0;
			return (str);
		}
		if (strlen(str) >= 10)
		{
			printf("Wrong Value, please don't input more than 10 character\n");
			return (NULL);
		}
	}
	free(str);
	return (0);
}

int	main(void)
{
	int	i = 0;

	while(42)
	{
		printf("index : %i\n", i);
		if (getinput != 0)
		{
			printf("input : %i\n", atoi(getinput()));
			i++;
			if (i %= 1 && astart)
			if (i %= 2 && bstart)
		}
	}
	return (0);
}

