# 42AbuDhabi-push_swap

## Plan (Mandatory part)

1) We should transform char arguments to numbers (with function ft_atoi)
2) Then we will put arguments in stack a
   Stacks will be 2 linked lists
3) We should write functions to recreate operations on stacks (8 operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
4) We should perform the sorting algorithm itself in main

## Compiling the Program with Makefile

For the `push_swap` project, I've set up a Makefile that compiles both the `libft` library and the `push_swap` program itself. This approach ensures that all dependencies are correctly compiled before the main program. Here's a breakdown of how the Makefile is structured to achieve this:

### Basic Setup

```makefile
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c utility_functions.c # Add all your .c files for push_swap here
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
```makefile

This section defines the executable name, compiler (using cc), compiler flags, source files, and object files for push_swap. It also specifies the location and target for the libft library.

### Compilation Rules

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

The all rule is the default, making the push_swap executable. It depends on the $(LIBFT) rule to compile the libft library before compiling the push_swap sources. The $(NAME) rule then links the object files with the libft library.

### Cleaning up

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

These rules manage cleaning up object files and executables for both push_swap and libft, ensuring a clean working environment.

### How to Use
To compile the program, simply run:
make

To clean up object files, use:
make clean

For a full clean (including the executable), use:
make fclean

And to recompile everything from scratch, use:
make re
