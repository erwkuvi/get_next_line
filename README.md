# Get Next Line (GNL) - 42 School Project  

The **Get Next Line (GNL)** project at **42 School** is an essential C programming exercise focused on **file reading and memory management**. The goal is to create a function, `get_next_line()`, that reads a file **line by line**, handling various edge cases while maintaining efficiency.

---

## **Project Objective**  

Implement the function:  

> char *get_next_line(int fd);

- Reads a line from a file descriptor (fd) until a newline (\n) or end of file (EOF).
- Returns the line as a char * string, including the newline character (\n) if present.
- Successive calls should return the next line until EOF.
- Must work with any file descriptor (files, stdin, pipes).
- Must be memory-efficient, keeping only necessary data in memory.
- Uses a static variable to handle multiple file descriptors at the same time.
- Implemented using a BUFFER_SIZE (defined at compile time).

---

## **Key Concepts & Challenges**

### File Handling & Read Function
Uses the read() system call to fetch data from the file descriptor.

Reads BUFFER_SIZE bytes at a time and processes them accordingly.

### Dynamic Memory Allocation
Uses malloc() to create dynamic strings.

Must properly free allocated memory to avoid leaks.

### Static Variables & Persistent Storage
A static variable stores leftover data between function calls.

Helps in reading a file incrementally rather than all at once.

### String Manipulation
Needs functions like strjoin(), strlen(), strchr(), and strdup().

Splits data into separate lines efficiently.

### Handling Multiple File Descriptors
The function must handle multiple file descriptors (fd) independently.

Uses an array of static variables, indexed by fd.
