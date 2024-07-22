RED					=	\x1B[31m
GRN					=	\x1B[32m
YEL					=	\x1B[33m
BLU					=	\x1B[34m
MAG					=	\x1B[35m
CYN					=	\x1B[36m
WHT					=	\x1B[37m
RESET				=	\x1B[0m
CLE 				=	\e[1;1H\e[2J

NAME				=	game_name

RENDER_LIB	=	Render.a
RENDER_DIR	=	Render/

#		config		#

ifeq ($(shell uname -s), Darwin)
    L = "
else
    L = '
endif

# Compiler and flags
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra -g


# local
ifeq ($(shell test -d raylib; echo "$$?"), 0)
    CFLAGS += -D LOCALLIB=1
endif
#-fsanitize=address
RM		=	rm -f

# Sources are all .c files
SRCS	=	main.c\

OBJS	=	$(SRCS:.c=.o)

all: render $(NAME)
	@printf $(L)$(CYN) \n\n			compiled by $(USER)\n\n  $(RESET)\n$(L)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS)  -I/usr/local/include -lraylib -lGL -lm -lrt -lX11 $(RENDER_DIR)$(RENDER_LIB) C_tools/C_tools.a -o $(NAME)
#                                                                         -lraylib -lGL -lm -lrt -lX11

render:
	@printf $(L)$(GRN)making $(RENDER_LIB)$(WHT)\n$(L)
	@make -s -C $(RENDER_DIR)
	@printf $(L)$(GRN)render done$(WHT)\n$(L)

mem: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=/tmp/supp.txt ./minishell

#https://github.com/sm222/C_tools

# Removes objects
clean:
	@$(RM) $(OBJS)
	@make -C $(RENDER_DIR) clean
	@printf $(L)$(GRN)clean *.o$(RESET)\n$(L)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@make -C $(RENDER_DIR) fclean
	@printf $(L)$(GRN)clean all$(RESET)\n$(L)

run: all
	@./$(NAME)

mc: all clean

re: fclean all


.PHONY: all mc re fclean clean mem render