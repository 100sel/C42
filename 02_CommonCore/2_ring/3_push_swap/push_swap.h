#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ERR_ 1

#define SA  1
#define SB  2
#define SS  3 
#define PA  4
#define PB  5
#define RA  6
#define RB  7
#define RR  8
#define RRA 9
#define RRB 10
#define RRR 11

typedef struct  s_stack {
    int         top;
    int         *items;
}               t_stack;

typedef struct  s_set {
    int         max_size;
    t_stack     *a_stk;
    t_stack     *b_stk;
}               t_set;

t_set   *init_set(int size, char **list);
int     *init_stack(int size, char **list);

void    do_op(t_set *stacks, int op);

void    sx(t_stack  *stk);
void    ss(t_set    *stacks);
void    px(t_stack  *dest, t_stack *src);
void    rx(t_stack  *stk);
void    rr(t_set    *stacks);
void    rrx(t_stack *stk);
void    rrr(t_set   *stacks);

void    cleaner(t_set *stacks);
void    print_stks(t_set *stacks);
void    err_hdl(int err_no, char *err_msg);
