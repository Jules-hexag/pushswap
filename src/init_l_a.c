/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-jules.fradin
** File description:
** init_l_a
*/

#include <stdlib.h>
#include "pushswap.h"
#include "my.h"

linked_t *init_l_a(int const argc, char * const * const argv)
{
    linked_t *head_1 = NULL;
    for (int i = 1; i < argc; i++)
        if (new_right(&head_1, my_getnbr(argv[i])))
            return NULL;
    return head_1;
}
