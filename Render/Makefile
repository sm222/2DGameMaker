NAME		=		Render.a

CC			=		gcc
FINAL		=		-Wall -Werror -Wextra -O2
DEV			=		-Wall -Werror -Wextra -g
RM			=		rm -f

LIBFT		=	libft.a
LIBFT_DIR	=	../lib/lib_ft/

SRCS	=	Render.c\



all:
	mkdir -p bin
	$(CC) 
	$(CC) $(FINAL) *.o -o $(SRCS)


clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all