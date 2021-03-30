/***********************************************************************/
/* /!\ Super cool recursive anagrams maker watch at your own risks /!\ */
/***********************************************************************/

#include "anagram.h"

/* adds a new character to the result string */

void	ana_add(char **result, char chr)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(*result) + 2));
	while ((*result)[i])
	{
		str[i] = (*result)[i];
		i++;
	}
	str[i] = chr;
	str[++i] = '\0';
	free(*result);
	*result = str;
}

/* deletes the last character added on result and reallocates mem */

void	ana_reduc(char **result)
{
	int		i;
	char	*nstr;

	i = 0;
	nstr = malloc(sizeof(char) * ft_strlen(*result));
	while ((*result)[i])
	{
		nstr[i] = (*result)[i];
		i++;
	}
	nstr[i - 1] = '\0';
	free(*result);
	*result = NULL;
	*result = nstr;
	return ;
}

/*Creates a new str without the character on index*/

char	*strip(char *str, int index)
{
	int		i;
	int		j;
	char	*nstr;

	i = 0;
	j = 0;
	nstr = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		if (i == index)
		{
			i++;
			continue ;
		}
		nstr[j] = str[i];
		j++;
		i++;
	}
	nstr[j] = '\0';
	return (nstr);
}

/*
** Main function
** first parameter : words to make anagrams of
** second parameter : result variable
*/

void	anagram(char *elements, char **result)
{
	int	static	n = 0;
	if (elements[0] == '\0')
	{
		ft_putstr_fd(*result, 1);
		n++;
		if ((n % WSIZE) == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putstr_fd(" ,", 1);
		ana_reduc(result);
		free(elements);
		elements = NULL;
		return ;
	}
	int			i;

	i = 0;
	while (elements[i])
	{
		ana_add(result, elements[i]);
		anagram(strip(elements, i), result);
		i++;
	}
	ana_reduc(result);
	free(elements);
	elements = NULL;
	return ;
}

/* Main */

int main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (av[1][0] == '\0')
		return (0);
	char	*elements;
	char	**result;

	elements = ft_strdup(av[1]);
	result = malloc(sizeof(char *) * 2);
	result[0] = ft_strdup("");
	result[1] = NULL;
	anagram(elements, result);
	ft_putchar_fd('\n', 1);
	free(result[0]);
	free(result[1]);
	free(result);
	return (1);
}
