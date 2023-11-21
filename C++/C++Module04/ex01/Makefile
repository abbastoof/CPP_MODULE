# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 15:33:55 by atoof             #+#    #+#              #
#    Updated: 2023/11/20 16:15:11 by atoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorphism_ex01
SRC = Animal.cpp Dog.cpp WrongAnimal.cpp Cat.cpp main.cpp WrongCat.cpp Brain.cpp
HEADER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp Brain.hpp
SRC_DIR = src/
HEADER_DIR = include/
OBJ_DIR = obj/
FLAGS = -Wall -Werror -Wextra
EXTRA_FLAGS = -std=c++98

SRCS = $(addprefix $(SRC_DIR), $(SRC))
OBJS = $(SRCS:$(SRC_DIR)%.cpp=$(OBJ_DIR)%.o)
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER))

# ANSI escape sequences for text formatting
BOLD = \033[1m
GREEN = \033[0;32m
YELLOW = \033[0;33m
CYAN = \033[0;36m
NC = \033[0m

vpath %.cpp $(SRC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@if [ -f $(NAME) ] && [ "$(OBJS)" -ot "$(NAME)" ]; then \
		echo "$(GREEN)$(BOLD)$(NAME) is already up-to-date!$(NC)"; \
	else \
		echo "$(YELLOW)$(BOLD)Compiling $(NAME)...$(NC)"; \
		g++ $(FLAGS) $(OBJS) -o $@ ; \
		echo "$(GREEN)$(BOLD)$(NAME) successfully compiled!$(NC)"; \
	fi

$(OBJ_DIR)%.o: %.cpp $(HEADERS)
	@echo "$(YELLOW)$(BOLD)Compiling $<...$(NC)"
	@mkdir -p $(@D)
	@g++ $(FLAGS) $(EXTRA_FLAGS) -I$(HEADER_DIR) -c -o $@ $<

clean:
	@echo "$(CYAN)$(BOLD)Cleaning object files...$(NC)"
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN)$(BOLD)Cleaning $(NAME)...$(NC)"
	@/bin/rm -f $(NAME)
	@echo "$(GREEN)$(BOLD)$(NAME) successfully cleaned!$(NC)"

re: fclean all
