NAME = libftprintf.a
Compiler = gcc
CFlags = -Wall -Wextra -Werror -g3
AR = ar rcs
SRC = ft_printf \
		ft_num \
		ft_words \

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

.c.o: $(SRCS)
	$(Compiler) $(CFlags) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re