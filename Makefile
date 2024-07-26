default: compile
include Colours.mk
include Settings.mk

# ======== ADDITIONAL SETTINGS ======== #

RENDER_LIB	=	Render.a
RENDER_DIR	=	engine/render/

#	local configs
ifeq ($(shell uname -s), Darwin)
    L = "
else
    L = '
endif

# local
ifeq ($(shell test -d raylib; echo "$$?"), 0)
    CFLAGS += -D LOCALLIB=1
endif

# shortcuts
CC		=	gcc
RM		=	rm -f
CPY		=	cp -f
MDR		=	mkdir -p

# getting object files name from source files ( in Settings.mk )
OBJS	=	$(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -I/usr/local/include -lraylib -lGL -lm -lrt -lX11 $(RENDER_DIR)$(RENDER_LIB) C_tools/C_tools.a -o $(NAME)
#                                               -lraylib -lGL -lm -lrt -lX11

#https://github.com/sm222/C_tools

# ======== CORE COMMANDS ======== #

compile: render $(NAME)
	@printf $(L)$(CYN)\n\n		# $(NAME) compiled by $(USER) #\n\n$(RESET)\n$(L)

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

mc: compile clean

re: fclean compile

run: mc
	@./$(NAME)

rerun: fclean run

.PHONEY: all compile clean fclean mc re run rerun

# ======== EXTRA COMMANDS ======== #

.PHONEY += render mem

render:
	@printf $(L)$(GRN)making $(RENDER_LIB)$(WHT)\n$(L)
	@make -s -C $(RENDER_DIR)
	@printf $(L)$(GRN)render done$(WHT)\n$(L)

mem: compile
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=/tmp/supp.txt ./minishell

