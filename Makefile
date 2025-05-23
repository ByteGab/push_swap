
NAME            = push_swap
LIBFT_DIR       = ./libft
LIBFT_LIB       = $(LIBFT_DIR)/libft.a

SOURCES         = push_swap.c utils.c control_list.c utils_nbrs.c ft_free.c rotate.c swap.c push.c reverse.c sort_nbrs.c utils_stacks.c sort_stack_b.c sort.c sort_stack_a.c stack_b_sort_cases.c  apply_sort.c  utils_sort_b.c utils_sort_a.c stack_a_sort_cases.c 
OBJECTS         = $(SOURCES:.c=.o)

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g
RM              = rm -rf

GREEN           = \033[1;32m
RED             = \033[1;31m
YELLOW          = \033[1;33m
BLUE            = \033[1;34m
CYAN            = \033[1;36m
RESET           = \033[0m
PURPLE          = \033[1;35m

all: banner $(NAME)

$(LIBFT_LIB):
	@echo "$(CYAN)Building libft...$(RESET)"
	@make -C $(LIBFT_DIR) >/dev/null 2>&1

$(NAME): $(LIBFT_LIB) $(OBJECTS)
	@echo "$(CYAN)Building $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_LIB) -o $(NAME) >/dev/null 2>&1
	@echo "$(GREEN)$(NAME) built successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@ >/dev/null 2>&1

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@$(RM) $(OBJECTS) >/dev/null 2>&1
	@echo "$(RED)Cleaning libft...$(RESET)"
	@make -C $(LIBFT_DIR) clean >/dev/null 2>&1

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME) >/dev/null 2>&1
	@echo "$(RED)Cleaning libft...$(RESET)"
	@make -C $(LIBFT_DIR) fclean >/dev/null 2>&1

re: fclean all

banner:
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀        ⣠⣦⠀⠀⠀"
	@echo "$(BLUE)⢀⡀⠀⠀⠀⠀⠀⠀⠀⣾⡇⠀⠀⠀⠀⣠⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡼⣽⣿⣧⠀⠀⠀"
	@echo "$(BLUE)⢿⣿⣷⣄⡀⠀⠀⠀⢠⣿⡇⠀⠀⢠⣾⣿⡏⠀⠀⠀⢀⣠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⢋⣼⣛⣿⡿⠀⠀⠀"
	@echo "$(BLUE)⠈⢿⣿⣿⣿⣟⣲⣦⣿⡿⢷⡦⣴⣿⣿⡟⢀⣀⣤⣴⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⣠⠤⠄⠒⠒⠒⠤⣄⢀⡞⣤⡿⣓⣾⠟⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠈⠛⠿⣿⣿⣿⠏⠀⠈⠀⠈⢻⣿⣯⣭⣤⣿⣿⡿⠋⠀⠀⠀⠀⣀⠠⠔⠚⠁⠀⠀⠀⠀⠀⠀⠐⠚⢿⣿⠧⣙⣾⡏⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⣿⣿⡿⠀⠀⠀⠀⢀⣾⣿⣿⣹⡿⠿⠋⢀⡠⠤⠤⠔⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡈⢻⣿⡟⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⢻⣿⡇⠀⠠⠀⢀⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣿⠁⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⢸⣿⠁⠀⠀⠀⢰⣿⣿⣿⠿⣶⠢⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⡄⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⢈⡏⠀⠀⠀⢠⣼⣿⣿⡿⠘⠛⠛⢓⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⠀⠀⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⡾⣆⣀⣠⣴⣿⣿⣿⠿⠁⠀⠩⠀⠈⢿⣦⣀⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⡿⠋⠁⠀⠀⠠⠀⠀⢀⢈⡙⡏⠉⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⡄⠀⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠻⠿⢻⠏⠀⠀⠀⠀⢀⠀⠃⡠⠘⠀⠙⢿⡆⠈⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢱⠀⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀⢰⠄⠀⠀⢸⣶⠚⠁⠀⠀⠀⠸⣧⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡆⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⢰⠃⠀⠀⢦⠀⠀⢸⣟⠄⠀⠀⠀⠀⢰⠈⢳⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠒⠦⣢⣄⠀⠀⣇⠀⠀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠘⣷⠄⢀⠈⠢⣄⢺⠿⠀⢀⡀⠀⢀⠘⣖⣾⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠁⠀⠀⠀⠘⢾⡆⠀⢨⢦⡀⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⢸⡶⢤⡐⡄⠀⠹⣷⣤⣟⣳⣤⣦⡸⡍⠈⠀⢸⠀⠀⠀⠀⠀⠀⠀⣀⣶⡇⠀⠀⠀⠀⠀⠀⠀⢳⣰⣀⠑⢻⠀⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⢰⡿⡧⣵⣈⠲⠤⣿⣿⠿⠿⠿⠿⢳⠿⠀⠘⣾⡀⠀⠀⢀⣀⢴⡞⣧⠘⡿⡄⠀⠀⠀⠀⠀⠀⠀⠹⡛⠀⠈⣇⠀"
	@echo "$(RESET)⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⣿⠋⠉⡟⠲⢼⣇⣀⣀⣤⣾⣿⠀⠀⠀⡟⠓⠋⠉⠉⠀⠀⣿⣿⡄⢠⡇⠀⠀⠀⠀⠀⠀⠀⠀⢣⡀⠀⢸⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⠀⠀⣿⠂⠐⠀⡸⠁⠀⠀⠈⠉⠁⠀⠈⣿⠀⠀⢰⡇⠀⠀⠀⠀⠀⠀⣿⠸⠁⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠈⠇⠀⠘⡄"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⠀⢠⡇⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⢠⡏⠀⠀⣼⠀⠀⠀⠀⠀⠀⣰⠋⠀⢀⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠿"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⠀⡞⠀⠀⢰⠃⠀⠀⠀⠀⠀⠀⠀⠀⣼⣇⠠⣀⣿⠀⠀⠀⠀⠀⢠⠇⠀⠀⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⢸⡇⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣷⢿⡇⠀⠀⠀⠀⢠⣾⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣆⣠"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⢺⡧⠀⢰⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣟⣦⠸⡆⠀⠀⠀⣴⡟⠁⠀⣤⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⠀⣿⠁⠀⡎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠿⠧⠀⡇⠀⠀⠀⣿⣿⣶⣾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⢀⡇⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⢰⠣⢀⣧⠀⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⠀⣼⡇⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⢁⡎⠀⢸⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⢠⣏⠁⠀⣾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠠⣿⣿⣀⣠⠼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⠀⢸⣿⢢⣶⣾⠀⠀⠀⠀⠀⠀⠀⠐⠚⠚⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "$(BLUE)⠀⠀⠀⢀⣈⣛⠚⡉⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀$(RESET)"