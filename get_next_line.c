#include "get_next_line.h"

static char *read_to_stash(int fd, char *stash);
static char *extract_line(char *stash);
static char *new_stash(char *stash);

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    // Step 1: read from fd into stash until newline or EOF
    stash = read_to_stash(fd, stash);
    if (!stash)
        return (NULL);
     
    // Step 2: extract a line (up to and including \n)
    line = extract_line(stash);

    // Step 3: update stash to keep leftover text
    stash = new_stash(stash);

    return (line);
}

// Reads from fd into stash until newline or EOF
static char *read_to_stash(int fd, char *stash)
{
    // 1. Allocate buffer of size BUFFER_SIZE + 1
    // 2. Loop: read(fd, buffer, BUFFER_SIZE)
    // 3. Append buffer to stash using ft_strjoin
    // 4. Stop if newline found or read returns 0
    // 5. Free buffer and return updated stash
    char    *buffer;
    ssize_t bytes_read;
    
    bytes_read = 1;
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return (NULL);
    while (!ft_strchr(stash, '\n') && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free (buffer);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        stash = (stash, buffer);
    }
    free(buffer);
    return (stash);
}

// Extracts line up to and including \n from stash
static char *extract_line(char *stash)
{
    char    *new_line;
    size_t  i;

    i = 0;
    // 1. Find newline position using ft_strchr
    // 2. Allocate memory for line (ft_substr)
    // 3. Return the new line

    if (!ft_strchr(stash, '\n'))
        new_line =(char *) malloc(ft_strlen(stash) + 1);
    else
    {
        while (stash[i] != '\n')
            i++;
        new_line =ft_substr(stash, 0, i + 1);
    }  
    return (NULL);
}

// Updates stash to keep leftover after line extraction
static char *new_stash(char *stash)
{
    // 1. Find newline position
    // 2. Allocate memory for leftover (ft_substr)
    // 3. Free old stash
    // 4. Return new leftover stash
    return (NULL);
}

