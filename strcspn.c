#include "shell.h"

/**
* _strcspn - Calculates the length of the initial segment of s
*            which does not contain any characters from reject
* @s: Pointer to the input string
* @reject: Pointer to the string of characters to reject
*
* Return: Length of the segment
*/

size_t _strcspn(const char *s, const char *reject)
{
	size_t i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; reject[j] != '\0'; j++)
		{
			if (s[i] == reject[j])
				return (i);
		}
	}

	return (i);
}
