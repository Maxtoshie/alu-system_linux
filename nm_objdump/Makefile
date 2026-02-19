.PHONY: all clean
CC = gcc
CCFLAGS = -g -Wall -Werror -Wextra -pedantic
NM_SRC = hnm.c dnm_32.c dnm_64.c a32_1.c a32_2.c a64_1.c a64_2.c
NM_NAME = hnm


all: hnm


hnm:
	$(CC) $(CCFLAGS) $(NM_SRC) -o $(NM_NAME)


clean:
	rm hnm
