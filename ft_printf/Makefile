NAME = libftprintf.a

SRC = char_format.c dispatch_format.c ft_printf.c \
itoa_base.c print_d.c print_percent.c print_ptr.c \
print_str.c print_u.c print_x.c print_X.c ft_strlen.c ft_itoa.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
