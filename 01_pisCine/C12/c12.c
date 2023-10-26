#include "ft_list.h"

t_list   *ft_create_elem(void *data) 
{
    t_list *elem;
    elem = malloc(sizeof(t_list));
    elem->data = data;
    elem->next = NULL;
    return elem;
}

void    ft_list_push_front(t_list **begin_list, void *data)
{
    t_list *elem;
    elem = ft_create_elem(data);
    elem->next = *begin_list;
    *begin_list = elem;
}

int     ft_list_size(t_list *begin_list)
{
    t_list  *ptr;
    int     cnt;
    
    cnt = 0;
    ptr = begin_list;

    while (ptr)
    {
        cnt++;
        ptr = ptr->next;
    }
        
   return cnt; 
}

t_list  *ft_list_last(t_list *begin_list)
{
    t_list  *ptr;
    ptr = begin_list;

    while (ptr->next)
        ptr = ptr->next;
     
   return ptr->data; 
}

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list *elem;
    t_list *ptr;

    elem = ft_create_elem(data);
    ptr = *begin_list;

    while(ptr->next)
        ptr = ptr->next;
    
    ptr->next = elem;
}

t_list  *ft_list_push_strs(int size, char **strs)
{
    t_list *elem;
    t_list *next;

    next = ft_create_elem(strs[0]);

    for (int i = 1; i < size; i++)
    {
        elem = ft_create_elem(strs[i]);
        elem->next = next;
        next = elem;
    }

    return next;
}

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list *to_free;

    while (begin_list)
    {
        free_fct(to_free);
        to_free = begin_list;
        begin_list = begin_list->next;
    }
    free_fct(to_free);
}

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    t_list  *elem;
    int     cnt;

    cnt = 1;
    elem = begin_list;

    while (cnt <= nbr) 
    {
        if (!elem)
            break;

        elem = elem->next;
    }

    return elem;
}