#include <unistd.h>

typedef struct      s_list
{
    t_list          *next;
    void            *data;    
}                   t_list;