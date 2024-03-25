NAME := fdf

BUILD_DIR := ./build
SRC_DIR := ./src

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INCLUDES := -Ilibft -Ift_printf -Imlx
LDFLAGS := -Llibft -lft -Lft_printf -lftprintf -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -lm
LIBFT := libft/libft.a
LIBFT_PRINTF := ft_printf/libftprintf.a
LIBMLX := mlx/libmlx.a

CFLAGS := -Wall -Wextra -Werror -MMD -MP

RM := -@rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(LIBFT_PRINTF) $(LIBMLX) $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDES)

$(LIBFT):
	@make -C libft

$(LIBFT_PRINTF):
	@make -C ft_printf

$(LIBMLX):
	@git submodule update --init
	@make -C mlx

clean:
	-@make -C libft clean
	-@make -C ft_printf clean
	-@make -C mlx clean
	$(RM) $(BUILD_DIR)

fclean: clean
	-@make -C libft fclean
	-@make -C ft_printf fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
