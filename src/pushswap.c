/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-jules.fradin
** File description:
** pushswap
*/

#include <unistd.h>
#include <stdlib.h>
#include "pushswap.h"
#include "my.h"

static int check_input(int const argc, char * const * const argv)
{
    if (argc == 1) {
        write(2, "Not enough arguments to proceed wanted operation.\n", 51);
        return EPITECH_ERR;
    }
    for (int i = 1; i < argc - 1; i++) {
        if (!my_getnbr(argv[i]) && my_strncmp(argv[i], "0", 1))
            return EPITECH_ERR;
    }
    return 0;
}

static int is_sorted(linked_t *l_a)
{
    if (l_a->next == NULL) return 1;
    while (l_a->next != NULL) {
        if (l_a->val > l_a->next->val) {
            return 0;
        }
        l_a = l_a->next;
    }
    return 1;
}

int pushswap(int const argc, char * const * const argv)
{
    if (check_input(argc, argv))
        return EPITECH_ERR;
    linked_t *head = init_l_a(argc, argv);
    if (!head)
        return EPITECH_ERR;
    if (is_sorted(head)) return 0;
    linked_t *l_b;
    sorting(&head, &l_b, argc - 1);

    my_printf("\n");

    if (head != NULL) {
        linked_t *tmp;
        while (tmp != NULL) {
            tmp = head->next;
            free(head);
            head = tmp;
        }
    } return 0;
}
