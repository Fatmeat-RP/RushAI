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

