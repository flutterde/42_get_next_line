# get_next_line

**get_next_line** is a versatile C function designed for efficient and dynamic line reading from file descriptors. This implementation is part of the 42 school curriculum and serves as a crucial component for handling file input in C programs. Master the art of reading lines, dynamically allocating memory, and enhancing your file processing capabilities with `get_next_line`.

## Usage

1. Clone the repository:

    ```bash
    git clone https://github.com/flutterde/42_get_next_line.git
    ```

2. Include the `get_next_line.c` and `get_next_line.h` files in your project.

3. Compile your project with `get_next_line.c`:

    ```bash
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=your_buffer_size your_source_files.c get_next_line.c get_next_line_utils.c -o your_executable
    ```

    Replace `your_buffer_size` with the desired buffer size (e.g., 32, 64).

4. Use `get_next_line` in your code:

    ```c
    #include "get_next_line.h"

    int main(void) {
        int fd;
        char *line;

        // Open your file descriptor (fd) here
        fd = open("PATH_TO_FILE", O_RDWR);
        line = get_next_line(fd);

       printf("%s\n", line);
       free(line);

        // Close your file descriptor (fd) here
        close(fd);

        return 0;
    }
    ```

    Make sure to handle errors appropriately and free allocated memory when done.

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests to improve the functionality or documentation.

