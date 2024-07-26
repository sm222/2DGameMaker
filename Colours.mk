# ====== COLOURS ====== #

RESET		=	\033[0;00m
CLE 		=	\e[1;1H\e[2J

# ====== NORMAL ====== #

BLK			=	\033[0;30m
RED			=	\033[0;91m
GRN			=	\033[0;92m
YEL			=	\033[0;93m
BLU			=	\033[0;94m
MAG			=	\033[0;95m
CYN			=	\033[0;96m
WHT			=	\033[0;97m

# ====== BOLD ====== #

BLK_B		=	\033[1;30m
RED_B		=	\033[1;91m
GRN_B		=	\033[1;92m
YEL_B		=	\033[1;93m
BLU_B		=	\033[1;94m
MAG_B		=	\033[1;95m
CYN_B		=	\033[1;96m
WHT_B		=	\033[1;97m

# ====== DARK ====== #

BLK_D		=	\033[2;30m
RED_D		=	\033[2;91m
GRN_D		=	\033[2;92m
YEL_D		=	\033[2;93m
BLU_D		=	\033[2;94m
MAG_D		=	\033[2;95m
CYN_D		=	\033[2;96m
WHT_D		=	\033[2;97m

# ====== UNDERLINE ====== #

BLK_U		=	\033[4;30m
RED_U		=	\033[4;91m
GRN_U		=	\033[4;92m
YEL_U		=	\033[4;93m
BLU_U		=	\033[4;94m
MAG_U		=	\033[4;95m
CYN_U		=	\033[4;96m
WHT_U		=	\033[4;97m

testcols: testcol_n testcol_b testcol_d testcol_u

testcol_n:
	@printf $(L)\n$(L)
	@printf $(L)$(BLK)BLACK$(RESET)\n$(L)
	@printf $(L)$(RED)RED$(RESET)\n$(L)
	@printf $(L)$(GRN)GREEN$(RESET)\n$(L)
	@printf $(L)$(YEL)YELLOW$(RESET)\n$(L)
	@printf $(L)$(BLU)BLUE$(RESET)\n$(L)
	@printf $(L)$(MAG)MAGENTA$(RESET)\n$(L)
	@printf $(L)$(CYN)CYAN$(RESET)\n$(L)
	@printf $(L)$(WHT)WHITE$(RESET)\n\n$(L)

testcol_b:
	@printf $(L)\n$(L)
	@printf $(L)$(BLK_B)BLACK$(RESET)\n$(L)
	@printf $(L)$(RED_B)RED$(RESET)\n$(L)
	@printf $(L)$(GRN_B)GREEN$(RESET)\n$(L)
	@printf $(L)$(YEL_B)YELLOW$(RESET)\n$(L)
	@printf $(L)$(BLU_B)BLUE$(RESET)\n$(L)
	@printf $(L)$(MAG_B)MAGENTA$(RESET)\n$(L)
	@printf $(L)$(CYN_B)CYAN$(RESET)\n$(L)
	@printf $(L)$(WHT_B)WHITE$(RESET)\n\n$(L)

testcol_d:
	@printf $(L)\n$(L)
	@printf $(L)$(BLK_D)BLACK$(RESET)\n$(L)
	@printf $(L)$(RED_D)RED$(RESET)\n$(L)
	@printf $(L)$(GRN_D)GREEN$(RESET)\n$(L)
	@printf $(L)$(YEL_D)YELLOW$(RESET)\n$(L)
	@printf $(L)$(BLU_D)BLUE$(RESET)\n$(L)
	@printf $(L)$(MAG_D)MAGENTA$(RESET)\n$(L)
	@printf $(L)$(CYN_D)CYAN$(RESET)\n$(L)
	@printf $(L)$(WHT_D)WHITE$(RESET)\n\n$(L)

testcol_u:
	@printf $(L)\n$(L)
	@printf $(L)$(BLK_U)BLACK$(RESET)\n$(L)
	@printf $(L)$(RED_U)RED$(RESET)\n$(L)
	@printf $(L)$(GRN_U)GREEN$(RESET)\n$(L)
	@printf $(L)$(YEL_U)YELLOW$(RESET)\n$(L)
	@printf $(L)$(BLU_U)BLUE$(RESET)\n$(L)
	@printf $(L)$(MAG_U)MAGENTA$(RESET)\n$(L)
	@printf $(L)$(CYN_U)CYAN$(RESET)\n$(L)
	@printf $(L)$(WHT_U)WHITE$(RESET)\n\n$(L)

.PHONEY += testcols testcol_n testcol_b testcol_d testcol_u
