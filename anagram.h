/***********************************************************************/
/* /!\ Super cool recursive anagrams maker watch at your own risks /!\ */
/***********************************************************************/

#ifndef ANAGRAM_H
# define ANAGRAM_H

/* Includes */

# include "../libft42/libft.h" //useful libft
# include <string.h> //strdup and strlen
# include <unistd.h> //write
# include <stdlib.h> //Malloc

/* anagram functions */

void	anagram(char *elements, char **result);
char	*strip(char *str, int index);
void	ana_reduc(char **result);
void	ana_add(char **result, char chr);

#endif
