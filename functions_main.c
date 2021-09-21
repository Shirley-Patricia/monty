#include "monty.h"


char *read_lines(FILE *file)
{
	char *lines = NULL;
	size_t buf = 0;
	int num_char = 0;

	num_char = getline(&lines, &buf, file);
	if (lines == NULL)
	{
		printf("Error: malloc failed\n");
		free(lines);
		exit(EXIT_FAILURE);
	}
	if (num_char == -1)
		lines = NULL;
	return (lines);
}


char **token_opcode(char *line)
{
    char **token = NULL;
    char *delimit = " \t\r\n";
    int size = 0;
    int i = 0;

    if (line == NULL)
    {
        return (NULL);
    }
    token = malloc(sizeof(char *) * 2 + 2);
    if (!token)
    {
        free(token);
        return (NULL);
    }
    token[0] = strtok(line, delimit);
    for (i = 1; i < 2; i++)
    {
        token[i] = strtok(NULL, delimit);
		printf("-->%s", token[i]);
    }
    return (token);
}