# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 21:44:08 by mbenhass          #+#    #+#              #
#    Updated: 2019/09/16 11:02:30 by mbenhass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs
OBJ_PATH = ./objs
INC_PATH = ./includes

RUN_MAIN = main.c
RUN_EXEC = main.out

CPPFLAGS = -I $(INC_PATH)

LDFLAGS = -Llibft
LDLIBS = -lft

NAME = libft.a

SRC_NAME = ft_atoi.c \
	   ft_atol.c \
		 ft_bzero.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_lltoa.c \
	   ft_itoa_base.c \
	   ft_lltoa_base.c \
	   ft_ulltoa_base.c \
	   ft_lstadd.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c  \
	   ft_putnbr.c  \
	   ft_putnbr_fd.c  \
	   ft_putstr.c  \
	   ft_putstr_fd.c  \
	   ft_strcat.c  \
	   ft_strchr.c  \
	   ft_strclr.c  \
	   ft_strcmp.c  \
	   ft_strcpy.c  \
	   ft_strdel.c  \
	   ft_strdup.c  \
	   ft_strequ.c  \
	   ft_striter.c  \
	   ft_striteri.c  \
	   ft_strjoin.c  \
	   ft_strjoinfree.c  \
	   ft_strlcat.c  \
	   ft_strlen.c  \
	   ft_strmap.c  \
	   ft_strmapi.c  \
	   ft_strncat.c  \
	   ft_strncmp.c  \
	   ft_strncpy.c  \
	   ft_strnequ.c  \
	   ft_strnew.c  \
	   ft_strnstr.c  \
	   ft_strrchr.c \
	   ft_strsplit.c  \
	   ft_strstr.c  \
	   ft_strsub.c  \
	   ft_strtrim.c  \
	   ft_tolower.c  \
	   ft_toupper.c \
	   ft_find_next_prime.c \
	   ft_power.c \
	   ft_sort_integer_list.c \
	   ft_sqrt.c \
	   ft_strcapitalize.c \
	   ft_strnjoinfree.c \
	   ft_reverse.c \
	   get_next_line.c \
	   ft_buffer.c \
	   ft_buffer2.c \
	   ft_conv.c \
	   ft_conv_float.c \
	   ft_conv_int.c \
	   ft_conv_str.c \
	   ft_conv_ptr.c \
	   ft_flags.c \
	   ft_int.c \
	   ft_printf.c \
	   ft_test.c \
	   ft_wide.c \
		 ft_min.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

GREEN = \033[0;32m
RED = \033[0;31m
WHITE = \033[0m

all : $(NAME)

$(NAME) : $(OBJ) ./includes/libft.h ./includes/ft_printf.h
	    ar rcs $(NAME) $(OBJ) && echo "\n$(GREEN)$@ successfully created$(WHITE)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@$(WHITE)"

clean :
	rm -f $(OBJ) && echo "$(RED)objects successfully deleted$(WHITE)"
	rmdir $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	rm -f $(NAME) && echo "$(RED)$(NAME) deleted$(WHITE)"
	rm -f $(RUN_EXEC)

re : fclean all

.PHONY : all clean fclean re

.SILENT : all $(NAME) clean fclean re

run : $(NAME)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(RUN_MAIN) $^ -o $(RUN_EXEC)
	./$(RUN_EXEC)

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
