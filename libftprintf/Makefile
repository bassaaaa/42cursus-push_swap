# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/27 19:00:55 by tsito             #+#    #+#              #
#    Updated: 2026/05/09 15:49:13 by tsito            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a

CFLAGS		:= -Wall -Wextra -Werror
ARFLAGS		:= rcs

SRCS		:= ft_printf.c \
			   ft_print_char.c \
			   ft_print_str.c \
			   ft_print_ptr.c \
			   ft_print_nbr.c \
			   ft_print_uint.c \
			   ft_print_hex.c
INCDIR		:= .
OUTDIR		:= .out
OBJS 		:= $(addprefix $(OUTDIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(OUTDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

clean:
	$(RM) -r $(OUTDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
