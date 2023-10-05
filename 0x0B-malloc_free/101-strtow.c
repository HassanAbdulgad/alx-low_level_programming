char **strtow(char *str)
{
    char **matrix, *tmp;
    int i, k = 0, len = 0, words, c = 0, start, end;

    // Calculate the length of the input string
    while (*(str + len))
        len++;
    words = count_word(str);
    
    // Check if there are no words, return NULL
    if (words == 0)
        return (NULL);

    // Allocate memory for the matrix of strings
    matrix = (char **) malloc(sizeof(char *) * (words + 1));
    if (matrix == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (c)
            {
                end = i;
                // Allocate memory for an individual word
                tmp = (char *) malloc(sizeof(char) * (c + 1));
                if (tmp == NULL)
                    return (NULL);
                // Copy the word into the allocated memory
                while (start < end)
                    *tmp++ = str[start++];
                *tmp = '\0';
                // Store the word in the matrix
                matrix[k] = tmp - c;
                k++;
                c = 0;
            }
        }
        else if (c++ == 0)
            start = i;
    }

    // Set the last element of the matrix to NULL to indicate the end
    matrix[k] = NULL;

    return (matrix);
}
