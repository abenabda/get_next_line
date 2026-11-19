*This project has been created as part of the 42 curriculum by abenabda.*

# Get Next Line

## Description

**Get Next Line (GNL)** is a project from the 42 curriculum that focuses on file handling, memory management, and static variables in C.

The goal of this project is to create a function called `get_next_line()` that reads from a file descriptor and returns one line at a time, regardless of how many times the function is called.

Unlike standard functions that read an entire file, `get_next_line()` allows me to retrieve a line with each function call while keeping track of the remaining data between calls.

Through this project, I learned how to work with file descriptors, use the `read()` system call, manage dynamically allocated memory, and understand how static variables preserve data between function calls.

## Instructions

### Compilation

The project can be compiled using the following command:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c main.c
```

`BUFFER_SIZE` determines how many bytes are read from the file descriptor during each call to `read()`.

You can change its value to test different situations:

```bash
-D BUFFER_SIZE=1
-D BUFFER_SIZE=42
-D BUFFER_SIZE=9999
```

The project must also compile without explicitly defining `BUFFER_SIZE`, using the default value defined in the source code.

### Usage

The main function takes a file descriptor as an argument and returns the next line as a dynamically allocated string.

```c
char *line;

line = get_next_line(fd);
while (line)
{
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
}
```

To compile and run the project, you can use:

```bash
./a.out
```

The function works with regular files as well as standard input.

### Project Files

| File | Description |
|---|---|
| `get_next_line.c` | Contains the main `get_next_line()` function and the reading logic. |
| `get_next_line_utils.c` | Contains the helper functions used to manipulate strings and manage memory. |
| `get_next_line.h` | Contains the function prototypes and necessary header definitions. |

## Algorithm Explanation

The main challenge of this project is keeping track of the data that has already been read but does not yet form a complete line.

To solve this problem, I use a **static variable called stash** that preserves the remaining data between function calls.

The algorithm follows these steps:

**1. Reading data**

I use the `read()` function to read a specific number of bytes from the file descriptor, determined by `BUFFER_SIZE`.

The data is temporarily stored inside a buffer.

**2. Storing data in the stash**

After reading, I append the buffer's content to the stash.

The stash keeps all the data that has been read but has not yet been returned as a complete line.

**3. Searching for a newline**

I search the stash for the newline character (`\n`).

- If a newline is found, I extract everything up to and including that newline.
- If no newline is found, I continue reading and appending data until I find one or reach the end of the file.

**4. Extracting the line**

Once I find a complete line, I allocate memory for it and copy the corresponding characters into a new string.

This string is returned to the caller.

**5. Updating the stash**

After extracting the line, I remove the returned portion from the stash.

The remaining characters are preserved for the next function call.

**6. Handling the end of the file**

When `read()` reaches the end of the file, I return any remaining characters as the last line.

If there is no remaining data, the function returns `NULL`.

### Why use a static variable?

A normal local variable is destroyed when its function finishes executing.

However, a static variable retains its value between function calls.

This allows me to preserve the stash without using global variables, which are forbidden by the subject.

It is the key mechanism that allows `get_next_line()` to remember where it stopped reading.

## Resources

During this project, I used the following resources to understand the concepts involved:

- [read() - Linux Manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [malloc() - Linux Manual](https://man7.org/linux/man-pages/man3/malloc.3.html)
- [File Descriptors - Linux Manual](https://man7.org/linux/man-pages/man2/open.2.html)
- [Static Variables in C](https://en.cppreference.com/w/c/language/static.html)

### AI Usage

I used AI as a learning assistant to help me understand some of the concepts involved in this project, particularly static variables, file descriptors, the `read()` function, and memory management.

I also used it to discuss possible approaches to the algorithm, understand different implementation choices, and improve the documentation of my project.

The objective was to strengthen my understanding of the underlying mechanisms rather than simply obtain a working solution.

## What I Learned

Through this project, I improved my understanding of:

- Static variables and their lifetime.
- File descriptors and how they work.
- The `read()` system call.
- Dynamic memory allocation and deallocation.
- String manipulation and memory copying.
- Managing data across multiple function calls.
- Handling different buffer sizes and end-of-file conditions.

