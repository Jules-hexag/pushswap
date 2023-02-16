/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-pushswap-jules.fradin
** File description:
** pushswap
*/

#ifndef PUSHSWAP_H_
    #define PUSHSWAP_H_

    #define EPITECH_ERR 84

    //linked list
    typedef struct linked_s {
        int val;
        struct linked_s *next;
    } linked_t;

    struct i_and_j {
        int i;
        int j;
    };

    // source
    int pushswap(int const argc, char * const * const argv);
    linked_t *init_l_a(int const argc, char * const * const argv);
    linked_t *sorting(linked_t **l_a, linked_t **l_b, int len_l_a);

    // linked lists operations
    void access_node(linked_t *head);
    int new_left(linked_t **head, int new_val);
    int new_right(linked_t **head, int new_val);
    int count_elem(linked_t *head);

    // sorting
    int sasb(linked_t **head);
    int pop_first_elem(linked_t **list);
    int papb(linked_t **out, linked_t **in);
    int rarb(linked_t **l_X);
    linked_t *rrarrb(linked_t **l_X);

    // move
    #define SA_ my_printf(" sa")
    #define SB_ my_printf(" sb")
    #define SC_ my_printf(" sc")
    #define PA_ my_printf(" pa")
    #define PB_ my_printf(" pb")
    #define RA_ my_printf(" ra")
    #define RB_ my_printf(" rb")
    #define RR_ my_printf(" rr")
    #define RRA_ my_printf(" rra")
    #define RRB_ my_printf(" rrb")
    #define RRR_ my_printf(" rrr")

#endif /* !PUSHSWAP_H_ */
