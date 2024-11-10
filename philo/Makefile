NAME				=	philo	

BLUE	=	\033[34m
GREEN	=	\033[32m
RESET	=	\033[0m
RED		=	\x1b[31m

CC					=	cc -g
FLAGS				=   -Wextra -Wall -Werror 

SRC_DIR				= 	src
SRC 				= 	$(wildcard $(SRC_DIR)/*.c)

OBJ_DIR				=	obj
OBJ					= 	$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all:				$(NAME)

$(NAME)		:	$(OBJ)
				@echo  "$(GREEN)<<Linking objects>>$(RESET)"
				$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:	src/%.c
			@mkdir -p $(OBJ_DIR)
			@echo "$(BLUE)<<Compiling $<>>$(RESET)"
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@echo	"$(BLUE)<<REMOVING *.o FILES>>$(RESET)"
			@rm -rf $(OBJ_DIR)/*


fclean: 			clean
			@echo	"$(RED)<<REMOVING EXECUTABLE>>$(RESET)"
			@rm -rf $(NAME)
			@rm -rf $(OBJ_DIR)

re:			fclean all

.PHONY:		all clean fclean re
