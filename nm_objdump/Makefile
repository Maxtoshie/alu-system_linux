CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -g

# Sources and objects for hnm
SRC_HNM = hnm.c utils.c endian.c endian2.c elf1.c \
          print_sections_1.c print_sections_2.c \
          print_symbols1.c print_symbols2.c print_symbols3.c
OBJ_HNM = hnm.o utils.o endian.o endian2.o elf1.o \
          print_sections_1.o print_sections_2.o \
          print_symbols1.o print_symbols2.o print_symbols3.o
NAME_HNM = hnm

# Sources and objects for hobjdump
SRC_HOBJ = hobjdump.c utils.c endian.c endian2.c elf1.c \
           print_sections_1.c print_sections_2.c print_symbols2.c \
           hobjdump_1.c hobjdump_2.c
OBJ_HOBJ = hobjdump.o utils.o endian.o endian2.o elf1.o \
           print_sections_1.o print_sections_2.o print_symbols2.o \
           hobjdump_1.o hobjdump_2.o
NAME_HOBJ = hobjdump

.PHONY: all clean fclean re hnm hobjdump

# Default
all: hnm hobjdump

# Explicit hnm target
hnm: $(OBJ_HNM)
	$(CC) $(CFLAGS) -o $(NAME_HNM) $(OBJ_HNM)

# Explicit hobjdump target
hobjdump: $(OBJ_HOBJ)
	$(CC) $(CFLAGS) -o $(NAME_HOBJ) $(OBJ_HOBJ)

# Compile .c to .o
hnm.o: hnm.c
	$(CC) $(CFLAGS) -c hnm.c -o hnm.o

utils.o: utils.c
	$(CC) $(CFLAGS) -c utils.c -o utils.o

endian.o: endian.c
	$(CC) $(CFLAGS) -c endian.c -o endian.o

endian2.o: endian2.c
	$(CC) $(CFLAGS) -c endian2.c -o endian2.o

elf1.o: elf1.c
	$(CC) $(CFLAGS) -c elf1.c -o elf1.o

print_sections_1.o: print_sections_1.c
	$(CC) $(CFLAGS) -c print_sections_1.c -o print_sections_1.o

print_sections_2.o: print_sections_2.c
	$(CC) $(CFLAGS) -c print_sections_2.c -o print_sections_2.o

print_symbols1.o: print_symbols1.c
	$(CC) $(CFLAGS) -c print_symbols1.c -o print_symbols1.o

print_symbols2.o: print_symbols2.c
	$(CC) $(CFLAGS) -c print_symbols2.c -o print_symbols2.o

print_symbols3.o: print_symbols3.c
	$(CC) $(CFLAGS) -c print_symbols3.c -o print_symbols3.o

# Clean
clean:
	rm -f *.o *~ $(NAME_HNM) $(NAME_HOBJ)

fclean: clean

re: fclean all
