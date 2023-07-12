#gcc so_long.c map.c check_map.c MLX42/libmlx42.a libft/libft.a -Iinclude -lglfw -L "/Users/anttorre/.brew/opt/glfw/lib/" -o so_long
#gcc so_long.c map.c check_map.c MLX42/libmlx42.a libft/libft.a -Iinclude -ldl -lglfw -pthread -lm -o so_long

#//= Colors =//#
BOLD	:= \033[1m
BLACK	:= \033[30;1m
RED		:= \033[31;1m
GREEN	:= \033[32;1m
YELLOW	:= \033[33;1m
BLUE	:= \033[34;1m
MAGENTA	:= \033[35;1m
CYAN	:= \033[36;1m
WHITE	:= \033[37;1m
RESET	:= \033[0m

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLX_PATH = ./MLX42

MLX = $(MLX_PATH)/libmlx42.a

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

#HEADER = so_long.h $(LIBFT_PATH)/libft.h

SO_LONG = so_long.a

LIB = ar rcs

#LIB_SYS = -Iinclude -ldl -lglfw -pthread -lm

LIB_SYS = -Iinclude -lglfw -L "/Users/anttorre/.brew/opt/glfw/lib/"

SRCS = src/so_long.c src/map_check.c src/map.c src/set_images.c src/player_movement.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = srcb/so_long_bonus.c srcb/map_check_bonus.c srcb/map_bonus.c srcb/set_images_bonus.c srcb/player_movement_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) :	$(OBJS) $(LIBFT) $(MLX)
			@echo "$(MAGENTA)$(BOLD)Compiling so_long...$(RESET)"
			@$(LIB) $(SO_LONG) $(OBJS)
			@$(CC) $(CFLAGS) $(SO_LONG) $(MLX) $(LIBFT) $(LIB_SYS) -o $(NAME)
			@echo "$(CYAN)$(BOLD)Done$(RESET)"

$(OBJS):	src/%.o : src/%.c 
			@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS):	srcb/%.o : srcb/%.c 
			@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
			@make -s -C $(LIBFT_PATH)
			@make bonus -s -C $(LIBFT_PATH)

$(MLX):
			@make -s -C $(MLX_PATH)

all : $(NAME)

bonus : $(OBJS_BONUS) $(LIBFT) $(MLX)
			@echo "$(YELLOW)$(BOLD)Compiling so_long_bonus...$(RESET)"
			@$(LIB) $(SO_LONG) $(OBJS_BONUS)
			@$(CC) $(CFLAGS) $(SO_LONG) $(MLX) $(LIBFT) $(LIB_SYS) -o $(NAME)
			@echo "$(CYAN)$(BOLD)Done$(RESET)"

clean:
			@echo "$(RED)$(BOLD)Cleaning objects from so_long...$(RESET)"
			@rm -f $(OBJS) $(OBJS_BONUS)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make clean -s -C $(MLX_PATH)
			@make clean -s -C $(LIBFT_PATH)

fclean:
			@echo "$(RED)$(BOLD)Cleaning all files from so_long...$(RESET)"
			@rm -f $(NAME) $(OBJS) $(OBJS_BONUS) $(SO_LONG) $(LIBFT) $(MLX)
			@echo "$(GREEN)$(BOLD)Done.$(RESET)"
			@make fclean -s -C $(MLX_PATH)
			@make fclean -s -C $(LIBFT_PATH)

re : fclean all

solong : all clean

solongb : bonus clean

.PHONY : all re fclean clean bonus solong