#include "rushai.h"

char	*getinput(void)
{
	int	i;
	char *str;
	char *buf;
	char c;

	i = 0;
	str = (char*)malloc(sizeof(char) * 15);
	if (!str)
		return (NULL);
	while (42)
	{
		c = getchar();
		if (c == 'x')
		{
			free(str);
			return ("nope");
		}
		str[i] = c;
		i++;
		if (c == '\n')
		{
			i = 0;
			buf = str;
			free(str);
			return (buf);
		}
		if (strlen(str) >= 10)
		{
			printf("Wrong Value, please don't input more than 10 character\n");
			free(str);
			return ("nope");
		}
	}
	free(str);
	return ("nope");
}
/*
struct s_parms	init_params(void)
{
	
}*/

int	main(void)
{
	int	i = 0;
	char *str;

	while(42)
	{
		printf("index : %i\n", i);
		str = strdup(getinput());
		if (!(strcmp(str, "nope")))
			return (0);
		printf("input : %i\n", atoi(str));
		i++;
	}
	return (0);
}

