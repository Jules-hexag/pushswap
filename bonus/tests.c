/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-BSQ-jules.fradin
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/logging.h>
#include <criterion/redirect.h>
#include <stdio.h>

#include "my.h"
#include "pushswap.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(unit_tests, not_enough_arguments, .init=redirect_all_std)
{
    int res = pushswap(1, (char *[]) {""});
    cr_assert_eq(84, res);
}

Test(unit_tests, little_test2, .init=redirect_all_std)
{
    char *answer = "pb pb rb pb rb rrb pa ra rra rra pb rb rrb pa \
ra rra rra ra pa ra pa ra ra\n";
    pushswap(5, (char *[]) {"", "4", "2", "6", "1"});
    cr_assert_stdout_eq_str(answer);
}

Test(unit_tests, in_order, .init=redirect_all_std)
{
    char *answer = "";
    pushswap(4, (char *[]) {"", "1", "4", "9"});
    cr_assert_stdout_eq_str(answer);
}
