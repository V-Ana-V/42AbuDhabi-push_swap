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
```

This section defines the executable name, compiler (using cc), compiler flags, source files, and object files for push_swap. It also specifies the location and target for the libft library.

### Compilation Rules

```makefile
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
```
Let's break down all the code:
```makefile
all: $(NAME)
```
all is a standard target in Makefiles that is intended to build the main or default artifacts of the project. When we run make without specifying a target, make will look for the all target by default.
`$(NAME)` is a variable that represents the name of the final executable program that this Makefile is intended to build. By placing $(NAME) as a dependency of all, we're telling make that in order to complete the all target, it must first complete the $(NAME) target.
```makefile
$(NAME): $(LIBFT) $(OBJS)
```
This line defines how to build the $(NAME) target. It states that `$(NAME)` depends on `$(LIBFT)` and `$(OBJS)`.
`$(LIBFT)` is a variable representing the library that your program depends on. The presence of this dependency ensures that the library is built before trying to link it when compiling the main program.
`$(OBJS)` represents the object files that are generated from your source files. These are the intermediate .o files created during the compilation of your program's source code.
The command
```makefile
$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
```
tells make how to actually create the `$(NAME)` executable.
`$(CC)` is the compiler being used, typically gcc or clang.
`$(CFLAGS)` represents compiler flags that should be applied, such as -Wall for all warnings, -Wextra for extra warnings, etc.
-o `$(NAME)` specifies the output file name for the compiled executable.
`$(OBJS)` is the list of object files to be linked together.
```makefile
$(LIBFT)
```
This rule specifies how to build the `$(LIBFT)` target, which represents the libft library.
```makefile
$(MAKE) -C $(LIBFT_DIR)
```
invokes make on the directory specified by `$(LIBFT_DIR)`, which contains the libft Makefile and source code. The -C option tells make to change to that directory before starting the build. This line ensures that the libft library is compiled before it is needed for linking with the main program.
Together, these parts of the Makefile ensure that your libft library is compiled first, then your program's object files are compiled, and finally, everything is linked together to create the final executable named `$(NAME)`.

### Cleaning up
```makefile
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
```

These rules manage cleaning up object files and executables for both push_swap and libft, ensuring a clean working environment.

### How to Use
To compile the program, simply run:
```bash
make
```

To clean up object files, use:
```bash
make clean
```

For a full clean (including the executable), use:
```bash
make fclean
```

And to recompile everything from scratch, use:
```bash
make re
```
