# NAMES
PHILO 				:= philo

# LIBS
LIBS_DIR 			:= libs/

# GNB LIBRARY
LIBGNB_DIR_NAME 	:= libgnb/ 
LIBGNB_NAME 		:= libgnb.so
LIBGNB_DIR 			:= $(addprefix $(LIBS_DIR), $(LIBGNB_DIR_NAME))
LIBGNB 				:= $(addprefix $(LIBCRYPT_DIR), $(LIBGNB_NAME))


# SOURCE FILES
SRC_DIR 			:= 	src/
SRC_FILES 			:= 	ft_check_args.c \
						ft_error.c \
						ft_manage_threads.c \
						habits.c \
						init_app.c \
						main.c \
						print.c \
						routines.c \
						time.c \
						utils.c \
						clean.c \
						routine_aux.c
SRC 				:= $(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJECT FILES
OBJ_DIR				:=	obj/
OBJ_FILES			:= 	$(SRC_FILES:%.c=%.o)
OBJ					:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

# COMPILER OPTIONS
CC					:= gcc
CFLAGS				:= -Wall -Werror -Wextra -pthread 
INCLUDE 			:= -I ./includes

# COLORS
RED					:=	\033[91;1m
GREEN				:=	\033[92;1m
YELLOW				:=	\033[93;1m
BLUE				:=	\033[94;1m
PINK				:=	\033[95;1m
CLEAR				:=	\033[0m


# MAKEFILE RULES
all: $(PHILO)

$(PHILO): $(OBJ_DIR) $(OBJ)
	@echo "$(PINK)Compiling $(PHILO) file.$(CLEAR)"
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(PHILO)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

clean:
	@echo "$(PINK)Removing $(YELLOW)$(PHILO)$(PINK) object files.$(CLEAR)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@echo "$(PINK)Removing $(YELLOW)$(PHILO) $(PINK)file.$(CLEAR)"
	@rm -f $(PHILO)
	@echo "$(GREEN)$(PHILO) file removed correctly\n$(CLEAR)"

re: fclean all

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE)

.PHONY:	all clean fclean re