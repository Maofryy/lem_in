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

OBJ_PATH = ./.objs

INC_PATH = ./includes -I ./libft/includes
LIB_PATH = ./libft

RUN_MAIN = main.c
RUN_EXEC = main.out

CPPFLAGS = -I $(INC_PATH)

LIBFT = libft.a
LIBS = -L $(LIB_PATH) -lft
LIB = $(LIB_PATH)/$(LIBFT)

NAME = lem_in

SRC_NAME = ft_lem_in.c \
			ft_exit.c
			
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

GREEN = \033[0;32m
RED = \033[0;31m
WHITE = \033[0m

all : $(NAME)
	$(MAKE) -C $(LIB_PATH)

$(NAME) : $(OBJ)  ./includes/lem_in.h
	$(MAKE) -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LIBS) -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@$(WHITE)"

clean :
	$(MAKE) clean -C $(LIB_PATH)
	rm -rf $(OBJ_PATH) && echo "$(RED)objects successfully deleted$(WHITE)"
	rmdir $(OBJ_PATH) 2> /dev/null || true

run_clean :
	rm -f *.ret && echo "$(RED)ret files deleted$(WHITE)"

fclean : clean run_clean
	$(MAKE) fclean -C $(LIB_PATH)
	rm -f $(NAME) && echo "$(RED)$(NAME) deleted$(WHITE)"
	rm -f $(RUN_EXEC)

re : fclean all

.PHONY : clean fclean re run_clean

.SILENT : all $(NAME) clean fclean re run_clean

run : all
	sh srcs_test/tests.sh ${ARGS}

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
