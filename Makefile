# -*- MakeFile -*-

TARGET = push_swap
SRCS = main.c linked_list.c str_util.c display_util.c std_util.c stack_util.c \
		 swap_util.c push_util.c 
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c %< $@  

re: fclean all

fclean: clean
	rm -f $(TARGET)

clean:
	rm -f $(OBJS)

.PHONY: all clean fclean re