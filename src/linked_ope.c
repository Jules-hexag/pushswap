/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-jules.fradin
** File description:
** linked_ope
*/

#include <stdlib.h>
#include "pushswap.h"
#include "my.h"

/*
                                    --> --> --> --> -->
    linked list : head--prev-------------------------------------next--NULL
*/
void access_node(linked_t *head)
{
    if (head == NULL) return;
    if (head->next == NULL) {
        my_printf("%d\n", head->val);
        access_node(head->next);
    } else
        my_printf("%d ", head->val);
    access_node(head->next);
}

int count_elem(linked_t *head)
{
    int i = 1;
    if (head == NULL) return 0;
    if (head->next == NULL) return 1;
    while (head->next != NULL) {
        i++;
        head = head->next;
    }
    return i;
}

int new_left(linked_t **head, int new_val)
{
    linked_t *new_node = malloc(sizeof(linked_t));
    if (!new_node) return EPITECH_ERR;
    new_node->val = new_val;
    new_node->next = *head;

    *head = new_node;
    return 0;
}

int new_right(linked_t **head, int new_val)
{
    linked_t *new_node = malloc(sizeof(linked_t));
    if (!new_node) return 1;
    new_node->val = new_val;
    new_node->next = NULL;
    linked_t *tmp = *head;
    while (*head != NULL)
        head = &(*head)->next;
    *head = new_node;
    head = &tmp;
    return 0;
}

int pop_first_elem(linked_t **list)
{
    linked_t *pop = *list;
    int result = pop->val;
    (*list) = (*list)->next;
    free(pop);
    return result;
}
