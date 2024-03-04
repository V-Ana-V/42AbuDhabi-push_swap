# 42AbuDhabi-push_swap

## Plan (Mandatory part)

1) We should transform char arguments to numbers (with function ft_atoi)
2) Then we will put arguments in stack a
   Stacks will be 2 linked lists
3) We should write functions to recreate operations on stacks (8 operations: sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr)
4) We should perform the sorting algorithm itself in main
## Building the Project with Makefile

For this project, I've crafted a Makefile that compiles both my `push_swap` program and the essential `libft` library it relies on. Below is a breakdown of how the Makefile is structured, making it straightforward to compile and clean the project using just a few commands.

### Structure of the Makefile

Here's the setup of my Makefile:

- **Binary Name**: Defined as `NAME`, which for the `libft` part is `libft.a`.
- **Compiler and Flags**: I'm utilizing `cc` as the compiler with flags `-Wall -Wextra -Werror` to show all warnings and enforce strict compilation.
- **Source and Object Files**: All my source files (`.c`) are listed under `SRCS`, and a simple pattern converts these into object files (`.o`) for compilation.
- **Header Files**: It's a good habit to keep track of your header files, though they're not directly used in the Makefile commands listed here.

### Compilation and Cleaning Commands

- **`all`**: This is the default rule. It compiles the `libft` library.
- **`$(NAME)`**: This rule compiles the `libft` library into a static library file named `libft.a`.
- **`clean`**: Cleans up all the object files from the library compilation.
- **`fclean`**: Removes everything that `clean` does, plus the `libft.a` library file.
- **`re`**: Useful for a full rebuild. It runs `fclean` followed by `all`.
- **`bonus`**: Compiles the library with additional "bonus" functionalities, incorporating extra object files into the `libft.a` library.
