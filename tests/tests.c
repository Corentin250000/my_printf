/*
** EPITECH PROJECT, 2024
** tests.c
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/mini_printf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_putchar, simple_character, .init = redirect_all_std)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(my_putstr, simple_string, .init = redirect_all_std)
{
    my_putstr("hello world\n");
    cr_assert_stdout_eq_str("hello world\n");
}

Test(my_strlen, size_str_valid)
{
    char *test = "Hello";

    cr_assert(my_strlen(test) == 5);
}

Test(my_strlen, size_str_invalid)
{
    char *test = "Hello";

    cr_assert_neq(my_strlen(test) != 5, "OK");
}

Test(my_strlen, size_str_empty)
{
    cr_assert(my_strlen("") == 0);
}

Test(my_strdup, duplicate_str_valid)
{
    cr_assert_str_eq(my_strdup("test"), "test");
}

Test(my_strdup, duplicate_str_invalid)
{
    cr_assert_str_neq(my_strdup("test"), "Test");
}

Test(int_to_char, integer_to_string_valid)
{
    cr_assert_str_eq(int_to_char(45), "0000000045");
}

Test(int_to_char, integer_to_string_invalid)
{
    cr_assert_str_neq(int_to_char(45), "45");
}

Test(remove_zeros, normal_use_valid)
{
    char *test = "0000000045";

    cr_assert_str_eq(remove_zeros(test), "45");
}

Test(remove_zeros, with_zero_valid)
{
    char *test = "0";

    cr_assert_str_eq(remove_zeros(test), "");
}

Test(remove_zeros, no_zeros_begin_valid)
{
    char *test = "1000000045";

    cr_assert_str_eq(remove_zeros(test), "1000000045");
}

Test(remove_zeros, normal_use_invalid)
{
    char *test = "0000000045";

    cr_assert_str_neq(remove_zeros(test), "0000000045");
}

Test(remove_zeros, with_zero_invalid)
{
    char *test = "0";

    cr_assert_str_neq(remove_zeros(test), "0");
}

Test(remove_zeros, no_zeros_begin_invalid)
{
    char *test = "1000000045";

    cr_assert_str_neq(remove_zeros(test), "145");
}
