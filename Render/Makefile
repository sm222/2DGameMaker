NAME	=	Render.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	rm -f

LIBFT		=	C_tools.a
LIBFT_DIR	=	../C_tools/

SRCS	=	Render.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	@cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS) 

all: $(LDIR)$(LIBFT) $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all