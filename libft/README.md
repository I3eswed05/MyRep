# 🧠 Libft

**Libft** is a custom C library that reimplements essential functions from the standard C library, along with additional utilities.  
It’s the foundational project in the [42 Network](https://42.fr/en/homepage/) curriculum, designed to build mastery in:

- Pointers and memory allocation  
- String manipulation  
- Linked list operations  
- Modular design and subject compliance  

---

## 📁 Project Structure

```
libft/
├── includes/       # Header files (e.g., libft.h)
├── srcs/
│   ├── memory/     # Memory management (ft_calloc, ft_memset, ft_memcpy…)
│   ├── string/     # String manipulation (ft_strlen, ft_strchr, ft_strdup…)
│   ├── utils/      # General utilities (ft_itoa, ft_putchar_fd…)
│   ├── bonus/      # Linked list functions (ft_lstnew, ft_lstadd_back…)
│   └── advanced/   # More complex functions (ft_split)
├── Makefile        # Build rules
└── README.md       # Project documentation
```

---

## 🔍 Highlighted Functions

### `ft_split`
- Splits a string into substrings based on a delimiter  
- Handles multiple dynamic allocations  
- Includes robust error management and memory freeing  
- One of the most challenging functions in Libft

### `ft_calloc`
- Allocates and zero-initializes memory  
- Demonstrates safe memory handling and overflow protection

### `ft_itoa`
- Converts an integer to a string  
- Requires careful handling of negatives and edge cases

### 🧩 Linked List Functions (Bonus)
- Functions like `ft_lstnew`, `ft_lstmap`, etc.  
- Reinforces pointer logic and data structure manipulation

---

## 🛠️ Compilation

To build the static library:

```bash
make        # Builds libft.a
make clean  # Removes object files
make fclean # Removes object files and libft.a
make re     # Rebuilds everything
```

This will generate `libft.a`, which can be linked to other C projects.

---

## 🚀 Usage Example

```c
#include "libft.h"
#include <stdio.h>

int main(void)
{
    char **words = ft_split("42 Network Amman", ' ');
    for (int i = 0; words[i]; i++)
        printf("%s\n", words[i]);

    // Output:
    // 42
    // Network
    // Amman

    return 0;
}
```

Compile with:

cc main.c libft.a -Iincludes


## ✅ Subject Compliance

This library is built to pass all mandatory and bonus tests, including Tripouille and alelievr testers.  
It adheres strictly to 42 subject requirements, with:

- Modular folder structure  
- Norminette-compliant code  
- Robust edge case handling  
- Validated return values and memory safety  

