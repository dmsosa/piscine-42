CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -rf
NAME=program
SRC = $(shell find . -type f -name '*.c' | sed 's|^\./||')
OBJS_DIR = obj
DEPS_DIR = deps
OBJS = $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))
DEPS = $(addprefix $(DEPS_DIR)/,$(SRC:.c=.d))
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 
$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(dir $@)
	$(CC) -M $< > $@
	echo "Deps updated $@\n"
-include $(DEPS)
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@
	echo "Objs created!"
clean: 
	$(RM) $(OBJS_DIR) $(DEPS_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re
