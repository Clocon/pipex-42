# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 12:12:37 by lumorale          #+#    #+#              #
#    Updated: 2023/03/10 14:00:01 by lumorale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
LIBFT			=	libft/libft.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
AR				=	ar -rcs

SRCS			=	pipex.c \
					error.c \
					childs.c \
					free.c \
					split_args.c \


#		COLORS		#
CYELLOW			=\033[1;33m
CGREEN			=\033[0;32m
CRED			=\033[0;91m
CRESET			=\033[0m

OBJS			=	$(SRCS:.c=.o)

all:			$(NAME) $(LIBFT)

$(LIBFT):
				@make -C ./libft

$(NAME):		$(LIBFT) $(OBJS)
				@$(CC) $(CFLAGS) $(LIBFT) $(OBJS)  -o $(NAME)
				@echo "\n$(CYELLOW)$(NAME) -> $(CGREEN) compiled$(CRESET)"

clean:
				@$(RM) $(OBJS)  
				@make -C ./libft clean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} objects files were deleted.${CRESET}"

fclean:			clean
				@$(RM) $(NAME)
				@make -C ./libft fclean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} was deleted.${CRESET}"

re:				fclean all

.PHONY:			all clean fclean re