P = ft_printf
CC = gcc
CL = ar rcs
CFLAGS = -Wall -Wextra -Werror -Wno-return-type -Wno-unused-result -Ofast
P_INCLUDE = -include lib/includes/libft.h

LIBDIR = lib/srcs/
LIBDIR_H  = lib/includes/

LIBSRC_FT = $(LIBDIR)ft_putchar.c $(LIBDIR)ft_putstr.c \
			$(LIBDIR)ft_strchr.c $(LIBDIR)ft_putnbr.c \
			$(LIBDIR)ft_ftoa.c
LIBSRC_FT_O = ft_putchar.o ft_putstr.o ft_strchr.o ft_putnbr.o ft_ftoa.o

DEL = rm -rf

all: libft $P

libft:
	$(CC) $(CFLAGS) -L$(LIBDIR_H)libft.h -c $(LIBSRC_FT)
	$(CL) libft.a $(LIBSRC_FT_O)

$P:
	$(CC) $(P_INCLUDE) $(CFLAGS) main.c -o $P -L. -lft

clean:
	$(DEL) *.o

fclean: clean
	$(DEL) libft.a
	$(DEL) $P
re: fclean all

.PHONY: re fclean clean $P libft all
