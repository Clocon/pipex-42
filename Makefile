# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 12:12:37 by lumorale          #+#    #+#              #
#    Updated: 2023/04/17 17:44:59 by lumorale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
NAME_BONUS		=	pipex_bonus
LIBFT			=	libft/libft.a
PRINTF			=	./ft_printf/libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
AR				=	ar -rcs

SRCS			=	src/pipex.c \
					src/error.c \
					src/childs.c \
					src/free.c \
					src/split_args.c \

SRCS_BONUS		=	src_bonus/pipex_bonus.c \
					src_bonus/error_bonus.c \
					src_bonus/childs_bonus.c \
					src_bonus/free_bonus.c \
					src_bonus/split_args_bonus.c \


#		COLORS		#
CYELLOW			=\033[1;33m
CGREEN			=\033[0;32m
CRED			=\033[0;91m
CRESET			=\033[0m

OBJS			=	$(SRCS:.c=.o)

OBJS_B			=	$(SRCS_BONUS:.c=.o)

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

all:			$(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
				@make -C ./libft

$(PRINTF):
				@make -C ./ft_printf

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(OBJS)  -o $(NAME)
				@echo "\n$(CYELLOW)$(NAME) -> $(CGREEN) compiled$(CRESET)"

$(NAME_BONUS):	$(OBJS_B)
				@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(OBJS_B)  -o $(NAME_BONUS)
				@echo "\n$(CYELLOW)$(NAME_BONUS) -> $(CGREEN) compiled$(CRESET)"

bonus:			$(LIBFT) $(PRINTF) $(NAME_BONUS) 

clean:
				@$(RM) $(OBJS)
				@$(RM) $(OBJS_B)
				@make -C ./libft clean
				@make -C ./ft_printf clean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} objects files were deleted.${CRESET}"

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(NAME_B)
				@make -C ./libft fclean
				@make -C ./ft_printf fclean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} was deleted.${CRESET}"

re:				fclean all

.PHONY:			all clean fclean re bonus