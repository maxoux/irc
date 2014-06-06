# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/31 12:40:37 by mlaize            #+#    #+#              #
#    Updated: 2014/05/25 18:13:39 by mlaize           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_S = server
NAME_C = client

FLAGS = -Werror -Wextra -Wall -O3

OBJDIR_S = obj_server
OBJDIR_C = obj_client

SRCDIR_S = src_server
SRCDIR_C = src_client

HEAD = includes

HEADLIBFT = libft/includes

LIBFTDIR = libft

SRC_S =	main.c					\
		close_connection.c		\
		cmd_users.c				\
		ft_exit.c				\
		init_group.c			\
		init_server.c			\
		main_loop.c				\
		open_connection.c		\
		port.c					\
		select_update.c			\
		send_broadcast.c		\
		send_channel.c			\
		user_command.c			\
		user_receive.c

SRC_S := $(addprefix $(SRCDIR_S)/, $(SRC_S))



SRC_C =	main.c					\
		ft_exit.c				\
		init_client.c			\
		main_loop.c				\
		port.c

SRC_C := $(addprefix $(SRCDIR_C)/, $(SRC_C))

OBJ_S = $(SRC_S:$(SRCDIR_S)%.c=$(OBJDIR_S)%.o)
OBJ_C = $(SRC_C:$(SRCDIR_C)%.c=$(OBJDIR_C)%.o)

all: $(NAME_S) $(NAME_C)

$(NAME_S): $(OBJ_S)
	@echo "compilation du libft ..."
	@make -C $(LIBFTDIR) all > /dev/null
	@echo "finalisation de $(NAME_S) ..."
	@clang $(FLAGS) $(OBJ_S) -I$(HEADLIBFT) -I$(HEAD)\
		$(LIBFTDIR)/libft.a -o $(NAME_S)
	@echo "Complete !"

$(NAME_C): $(OBJ_C)
	@echo "compilation du libft ..."
	@make -C $(LIBFTDIR) all > /dev/null
	@echo "finalisation de $(NAME_C) ..."
	@clang $(FLAGS) $(OBJ_C) -I$(HEADLIBFT) -I$(HEAD)\
		$(LIBFTDIR)/libft.a -o $(NAME_C)
	@echo "Complete !"

$(OBJDIR_S)/%.o: $(SRCDIR_S)/%.c
	@mkdir -p $(OBJDIR_S)
	@clang $(FLAGS) -I$(HEAD) -I$(HEADLIBFT) -c -o $@ $^
	@echo "compilation de $@ ..."

$(OBJDIR_C)/%.o: $(SRCDIR_C)/%.c
	@mkdir -p $(OBJDIR_C)
	@clang $(FLAGS) -I$(HEAD) -I$(HEADLIBFT) -c -o $@ $^
	@echo "compilation de $@ ..."

clean:
	@-rm -rf $(OBJDIR_S) $(OBJDIR_C)
	@echo "suppresion des objets ..."

fclean: clean
	@-rm -rf $(NAME_S) $(NAME_C)
	@echo "suppression de $(NAME_S)/$(NAME_C) ..."

re:
	@echo "reactualisation de $(NAME_S)/$(NAME_C) : Full Mode ..."
	@make -C $(LIBFTDIR) fclean
	@make fclean
	@make all

relite:
	@echo "reactualisation de $(NAME_S)/$(NAME_C) : Lite Mode ..."
	@make fclean
	@make all

.PHONY: all clean fclean re relite 
