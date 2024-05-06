#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_nodes
{
    int             number;
    int             index;
    int             cost_p;
    bool            above_med;
    bool            cheapest;
    struct s_nodes  *target;
    struct s_nodes  *next;
    struct s_nodes  *prev;
}   t_nodes;

#endif