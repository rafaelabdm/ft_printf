# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabustam <rabustam@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 16:46:37 by rabustam          #+#    #+#              #
#    Updated: 2022/06/22 15:20:33 by rabustam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c\
			ft_printf_utils.c\
			ft_itoa_base.c\
			ft_itoa_unsigned.c\
			ft_ptr_conv.c\
			ft_int_conv.c

OBJS	=	ft_printf.o\
			ft_printf_utils.o\
			ft_itoa_base.o\
			ft_itoa_unsigned.o\
			ft_ptr_conv.o\
			ft_int_conv.o

HEADER	=	ft_printf.h

CFLAGS	= 	-Wall -Wextra -Werror

.c.o:	$(SRCS)
		cc $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(HEADER)
		ar rcs $@ $^

all:	$(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:		clean all

.PHONY: all clean fclean re