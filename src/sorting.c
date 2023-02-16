/*
** EPITECH PROJECT, 2023
** B-CPE-110-BDX-1-1-pushswap-jules.fradin
** File description:
** sorting
*/

#include "pushswap.h"
#include "my.h"
#include <stdlib.h>

static int first_pb(int first)
{
    if (first == 0) {
        my_printf("pb");
        return 1;
    } else {
        PB_;
    }
    return 0;
}

static int split(int len_l_a, linked_t **l_a, linked_t **l_b)
{
    static int first = 0;
    linked_t *check = *l_b;
    if (len_l_a <= 1)
        return -1;
    for (int i = 0; i < len_l_a / 2; i++) {
        if (count_elem(*l_a) != 0) {
            first_pb(first) ? first = 1 : 0;
            papb(l_b, l_a);
        }
        if (count_elem(*l_b) != 0 && count_elem(*l_b) != 1) {
            RB_;
            rarb(l_b);
        }
    }
    for (int i = 0; i < len_l_a / 2 && check != NULL; i++) {
        if (count_elem(*l_b) != 0 && count_elem(*l_b) != 1) {
            RRB_;
            rrarrb(l_b);
        }
    } return 0;
}

static void clean_merge(linked_t **l_a, linked_t **l_b, int state)
{
    if (state == 0) {
        if (count_elem(*l_b) != 0) {
            PA_;
            papb(l_a, l_b);
        }
        if (count_elem(*l_a) != 0 && count_elem(*l_a) != 1) {
            RA_;
            rarb(l_a);
        }
    }
    if (state == 1) {
        if (count_elem(*l_a) != 0 && count_elem(*l_a) != 1) {
            RA_;
            rarb(l_a);
        }
    }
}

static void merge(int len_l_a, linked_t **l_a, linked_t **l_b,
    struct i_and_j *for_merge)
{
    while (for_merge->i && for_merge->j) {
        if ((*l_b)->val <= (*l_a)->val) {
            clean_merge(l_a, l_b, 0);
            for_merge->j--;
        } else {
            clean_merge(l_a, l_b, 1);
            for_merge->i--;
        }
    }
}

linked_t *sorting(linked_t **l_a, linked_t **l_b, int len_l_a)
{
    if (split(len_l_a, l_a, l_b) == -1)
        return NULL;
    sorting(l_a, l_b, len_l_a - (len_l_a / 2));
    sorting(l_b, l_a, len_l_a / 2);
    struct i_and_j for_merge = {len_l_a - (len_l_a / 2), len_l_a / 2};
    merge(len_l_a, l_a, l_b, &for_merge);
    for (int k = 0; k < for_merge.j; k++) {
        PA_;
        papb(l_a, l_b);
        RA_;
        rarb(l_a);
    }
    for (int k = 0; k < for_merge.i; k++) {
        RA_;
        rarb(l_a);
    }
    for (int k = 0; k < len_l_a && *l_b != NULL; k++) {
        RRA_;
        rrarrb(l_a);
    } return *l_a;
}
