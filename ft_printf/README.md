# 🖨️ ft_printf

**ft_printf** is a custom implementation of the standard `printf` function in C.  
It replicates formatted output functionality while reinforcing mastery in:

- Variadic functions (`va_list`, `va_start`, `va_arg`, `va_end`)  
- Format string parsing and dispatching  
- Modular formatter design  
- Memory safety and edge case handling  

This project is part of the [42 Network](https://42.fr/en/homepage/) curriculum and is built to comply strictly with subject requirements.

---

## 📁 Project Structure

```
ft_printf/
├── includes/           # Header files
│   └── ft_printf.h     # Function prototypes and macros
├── srcs/
│   ├── core/           # Core logic (dispatcher, parser)
│   │   ├── ft_printf.c
│   │   └── ft_parse_format.c
│   ├── formatters/     # Format-specific handlers
│   │   ├── ft_print_char.c
│   │   ├── ft_print_str.c
│   │   ├── ft_print_int.c
│   │   ├── ft_print_unsigned.c
│   │   ├── ft_print_hex.c
│   │   └── ft_print_ptr.c
│   └── utils/          # Helper functions
│       ├── ft_numlen.c
│       ├── ft_putnbr_base.c
│       └── ft_strlen.c
├── libft/              # Optional: libft integration
│   └── ...             # Your libft files here
├── Makefile            # Build rules (compiles to libftprintf.a)
└── README.md           # Project documentation
```

---

## 🔍 Highlighted Components

### `ft_printf.c`
- Entry point for formatted output  
- Initializes variadic arguments and delegates formatting

### `ft_parse_format.c`
- Parses format specifiers and flags  
- Dispatches to appropriate formatter functions

### Formatters (`%c`, `%s`, `%d`, `%u`, `%x`, `%p`)
- Each specifier handled in its own file  
- Modular design for easy debugging and extension  
- Handles edge cases like null strings, INT_MIN, and pointer formatting

### Utilities
- Base conversion, length calculation, and safe output helpers  
- Shared across formatters for consistency

---

## 🛠️ Compilation

To build the static library:

```bash
make        # Builds libftprintf.a
make clean  # Removes object files
make fclean # Removes object files and libftprintf.a
make re     # Rebuilds everything
```

This will generate `libftprintf.a`, which can be linked to other C projects.

---

## 🚀 Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    int count = ft_printf("Hello %s, your score is %d%%\n", "Ibrahim", 100);
    ft_printf("Printed %d characters.\n", count);

    // Output:
    // Hello Ibrahim, your score is 100%
    // Printed 39 characters.

    return 0;
}
```

Compile with:

```bash
cc main.c libftprintf.a -Iincludes
```

---

## ✅ Subject Compliance

This implementation is built to pass all mandatory and bonus tests, including Tripouille and alelievr testers.  
It adheres strictly to 42 subject requirements, with:

- Norminette-compliant code  
- Modular folder structure  
- Robust edge case handling  
- Validated return values and memory safety  
- Seamless integration with `libft`

---
