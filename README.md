###

<div align="center">
  <a href="https://www.linkedin.com/in/ertu%C4%9Frul-pakdamar/" target="_blank">
    <img src="https://img.shields.io/static/v1?message=LinkedIn&logo=linkedin&label=&color=0077B5&logoColor=white&labelColor=&style=for-the-badge" height="25" alt="linkedin logo"  />
  </a>
  <a href="https://www.hackerrank.com/ertu_pakdamar" target="_blank">
    <img src="https://img.shields.io/static/v1?message=HackerRank&logo=hackerrank&label=&color=2EC866&logoColor=white&labelColor=&style=for-the-badge" height="25" alt="hackerrank logo"  />
  </a>
</div>

###

# 🚀 get_next_line

> 🚧 **Status:** In Progress

A small C function to read a line from a file descriptor, handling buffer boundaries and end‑of‑file correctly, inspired by the 42 school’s Get Next Line project.

###

<h3 align="left">🛠 Language and tools</h3>

###

<div align="left">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" height="40" alt="c logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vscode/vscode-original.svg" height="40" alt="vscode logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/linux/linux-original.svg" height="40" alt="linux logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/bash/bash-original.svg" height="40" alt="bash logo"  />
</div>

###

## ✨ About

The goal of this project is to implement `get_next_line`, a function that reads from a given file descriptor and returns a complete line each time it's called, including the newline character. This function should be robust, memory-efficient, and able to handle multiple file descriptors simultaneously.

---

## ⚙️ Features

- Reads by chunks using a defined `BUFFER_SIZE`.
- Returns a **null-terminated string** including the newline (`'\n'`) if present.
- Works with any file descriptor: files, standard input, pipes, etc.
- Manages multiple file descriptors simultaneously (bonus).
- Properly frees memory to avoid leaks.

---

## 💻 Usage

Include the header and link the object file or library:
```c
#include "get_next_line.h"

int fd = open("filename.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 📁 Project Structure

```text
├── get_next_line.c        # Core logic
├── get_next_line_utils.c  # Helpers: string operations, buffer management
├── get_next_line.h        # Declarations and macros
├── get_next_line_bonus.c        # Core logic
├── get_next_line_utils_bonus.c  # Helpers: string operations, buffer management
├── get_next_line_bonus.h        # Declarations and macros
└── README.md
```

---
