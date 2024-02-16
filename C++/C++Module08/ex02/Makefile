# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 13:37:34 by atoof             #+#    #+#              #
#    Updated: 2024/02/16 18:50:55 by atoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MutantStack
SRCS = main.cpp  
OBJS = $(SRCS:.cpp=.o)
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = inc/
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++14
RM = rm -rf

vpath %.cpp $(SRC_DIR)

all: $(OBJ_DIR) $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJS))
	$(CC) $(CFLAGS) -I $(INC_DIR) $^ -o $@

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
