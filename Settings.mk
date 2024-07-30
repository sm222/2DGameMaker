
# ====== PROJECT SETTINGS ====== #

# executable name
NAME		=	game_name


# source files
SRCS		= engine/core.cpp \
					engine/Engine.cpp \
					engine/groups/GroupBasic.cpp \
					engine/objects/ObjectBasic.cpp \
					engine/scripts/ScriptBasic.cpp \

# 			add more sources here




# compilation flags
CC			=	c++
CFLAGS	=	-Wall -Wextra -Werror -g -std=c++11

# other flags 		-fsanitize=address