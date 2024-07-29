
# ====== PROJECT SETTINGS ====== #

# executable name
NAME		=	game_name


# source files
SRCS		= engine/Debug.cpp \
					engine/Core.cpp \
					engine/Engine.cpp \
					engine/EngineSteps.cpp \
					engine/groups/GroupBasic.cpp \
					engine/objects/ObjectBasic.cpp \
					engine/scripts/ScriptBasic.cpp \

# 			add more sources here




# compilation flags
CC			=	c++
CFLAGS	=	-Wall -Wextra -Werror -g -std=c++11

# other flags 		-fsanitize=address