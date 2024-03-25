NAME := fdf

BUILD_DIR := ./build
SRC_DIR := ./src

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

LIBS := ft
INCLUDE := $(addprefix -I,$(LIBS))
LDFLAGS := $(addprefix -L,$(LIBS)) $(addprefix -l,$(LIBS))

CFLAGS := -Wall -Wextra -Werror -MMD -MP $(INCLUDE)

RM := rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(foreach lib,$(LIBS),make -C $(lib))
	$(CC) -o $@ $(LDFLAGS) $^

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(foreach lib,$(LIBS),make -C $(lib) clean)
	$(RM) $(BUILD_DIR)

fclean: clean
	$(foreach lib,$(LIBS),make -C $(lib) fclean)
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
