# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabrigo <mabrigo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 18:46:22 by mabrigo           #+#    #+#              #
#    Updated: 2024/04/25 12:06:54 by mabrigo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server
HEADER = minitalk.h

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft
PRINTF = printf
SRC_CLIENT = client.c \
			$(foreach dir,$(LIBFT),$(wildcard $(dir)/*.c)) \
			$(foreach dir,$(PRINTF),$(wildcard $(dir)/*.c))
SRC_SERVER = server.c \
			$(foreach dir,$(LIBFT),$(wildcard $(dir)/*.c)) \
			$(foreach dir,$(PRINTF),$(wildcard $(dir)/*.c))
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re

.SILENT: