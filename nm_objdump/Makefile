CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -g

# Sources for hnm
SRC_HNM = hnm.c utils.c endian.c endian2.c elf1.c \
          print_sections_1.c print_sections_2.c \
          print_symbols1.c print_symbols2.c print_symbols3.c
OBJ_HNM = $(SRC_HNM:.c=.o)
NAME_HNM = hnm

# Sources for hobjdump
SRC_HOBJ = hobjdump.c utils.c endian.c endian2.c elf1.c \
           print_sections_1.c print_sections_2.c print_symbols2.c \
           hobjdump_1.c hobjdump_2.c
OBJ_HOBJ = $(SRC_HOBJ:.c=.o)
NAME_HOBJ = hobjdump

.PHONY: all clean fclean re

all: $(NAME_HNM) $(NAME_HOBJ)

# Rule for hnm
$(NAME_HNM): $(OBJ_HNM)
	$(CC) $(CFLAGS) -o $(NAME_HNM) $(OBJ_HNM)

# Rule for hobjdump
$(NAME_HOBJ): $(OBJ_HOBJ)
	$(CC) $(CFLAGS) -o $(NAME_HOBJ) $(OBJ_HOBJ)

# Compile .c files to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and executables
clean:
	rm -f *.o *~ $(NAME_HNM) $(NAME_HOBJ)

fclean: clean

re: fclean all
