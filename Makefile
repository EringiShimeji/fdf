NAME := fdf

BUILD_DIR := ./build
SRC_DIR := ./src

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIR := libft
INCLUDE := $(addprefix -I,$(INC_DIR))
CFLAGS := -Wall -Wextra -Werror $(INCLUDE) -MMD -MP
LDFLAGS :=

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
