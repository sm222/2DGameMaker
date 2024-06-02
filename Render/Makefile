NAME	=	Render.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g
RM		=	rm -f

LIBFT		=	C_tools.a
LIBFT_DIR	=	../C_tools/


# local
ifeq ($(shell test -d ../raylib; echo "$$?"), 0)
    CFLAGS += -D LOCALLIB=1
endif

SRCS	=	Render.c\
			init.c\
			free_data.c\
			add_obj.c\
			rm_obj.c

OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	@cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJS) 

all: lib $(LDIR)$(LIBFT) $(NAME)

$(LIBFT_DIR)$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all