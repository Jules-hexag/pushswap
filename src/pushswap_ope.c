/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-jules.fradin
** File description:
** pushswap_ope
*/

#include <stdlib.h>
#include "my.h"
#include "pushswap.h"

/*
    head ---  o --- o --- o --- o --- o --- o --- o --> NULL
*/

/*
    swap the first two elements of l_X (nothing will happen if there aren’t
    enough elements).
*/
int sasb(linked_t **head)
{
    if ((*head)->next == NULL)
        return 0;
    linked_t *sav = (*head)->next;
    (*head)->next = (*head)->next->next;
    sav->next = *head;
    *head = sav;
    return 0;
}

/*
    pa : take the first element from l_b and move it to the first position on
    the l_a list (nothing will happen if l_b is empty).
*/
int papb(linked_t **out, linked_t **in)
{
    if (in == NULL)
        return 0;
    new_left(out, pop_first_elem(in));
    return 0;
}

/*
    rotate l_a toward the beginning, the first element will become the last.
*/
int rarb(linked_t **l_X)
{
    if (l_X == NULL)
        return 0;
    new_right(l_X, pop_first_elem(l_X));
    return 0;
}

/*
    rotate l_a toward the end, the last element will become the first.
*/
linked_t *rrarrb(linked_t **l_X)
{
    linked_t *go_to_end = *l_X;
    linked_t *to_return = NULL;

    if ((*l_X)->next == NULL)
        return *l_X;
    else if ((*l_X)->next->next == NULL) {
        sasb(l_X);
        return *l_X;
    }

    while (go_to_end->next->next != NULL) {
        go_to_end = go_to_end->next;
    }
    to_return = go_to_end->next;
    go_to_end->next = NULL;
    to_return->next = *l_X;
    *l_X = to_return;
    return to_return;
}
