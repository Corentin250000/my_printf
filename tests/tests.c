/*
** EPITECH PROJECT, 2024
** tests.c
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/mini_printf.h"

#include <string.h>

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

Test(mini_printf, basic_test, .init = redirect_all_std)
{
    mini_printf("Hello world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(mini_printf, basic_test_int, .init = redirect_all_std)
{
    mini_printf("Hello world %d", 18);
    cr_assert_stdout_eq_str("Hello world 18");
}

Test(mini_printf, test_int_nul, .init = redirect_all_std)
{
    mini_printf("Hello world %d", 0);
    cr_assert_stdout_eq_str("Hello world 0");
}

Test(mini_printf, test_negative_int, .init = redirect_all_std)
{
    mini_printf("Hello world %d", -18);
    cr_assert_stdout_eq_str("Hello world -18");
}

Test(mini_printf, basic_test_int_i, .init = redirect_all_std)
{
    mini_printf("Hello world %i", 18);
    cr_assert_stdout_eq_str("Hello world 18");
}

Test(mini_printf, test_int_nul_i, .init = redirect_all_std)
{
    mini_printf("Hello world %i", 0);
    cr_assert_stdout_eq_str("Hello world 0");
}

Test(mini_printf, test_negative_int_i, .init = redirect_all_std)
{
    mini_printf("Hello world %i", -18);
    cr_assert_stdout_eq_str("Hello world -18");
}

Test(mini_printf, basic_test_str, .init = redirect_all_std)
{
    mini_printf("Hello %s", "world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(mini_printf, advanced_test_str, .init = redirect_all_std)
{
    mini_printf("%s %s", "Hello", "world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(mini_printf, basic_test_char, .init = redirect_all_std)
{
    
    mini_printf("Hello world%c", '!');
    cr_assert_stdout_eq_str("Hello world!");
}

Test(mini_printf, advanced_test_char, .init = redirect_all_std)
{
    mini_printf("%c%c%c%c%c", 'H', 'e', 'l', 'l', 'o');
    cr_assert_stdout_eq_str("Hello");
}

Test(mini_printf, basic_test_pourcent, .init = redirect_all_std)
{
    char verification[10];

    strcpy(verification, "Test%");
    mini_printf("Test%%");
    fflush(stdout);
    cr_assert_stdout_eq_str(verification);
}

Test(mini_printf, advanced_test_pourcent, .init = redirect_all_std)
{
    char verification[10];

    strcpy(verification, "Test%%");
    mini_printf("Test%%%%");
    cr_assert_stdout_eq_str(verification);
}

Test(mini_printf, extreme_test_pourcent_1, .init = redirect_all_std)
{
    mini_printf("Test%");
    cr_assert_stdout_eq_str("Test");
}

Test(mini_printf, extreme_test_pourcent_2, .init = redirect_all_std)
{
    mini_printf("Test %f", 45);
    cr_assert_stdout_neq_str("Test 45");
}

Test(mini_printf, basic_test_all, .init = redirect_all_std)
{
    mini_printf("%c%c%s%d%c%s", 'I', ' ', "have ", 18, ' ', "years old.\n");
    cr_assert_stdout_eq_str("I have 18 years old.\n");
}

Test(mini_printf, advanced_test_all, .init = redirect_all_std)
{
    mini_printf("I have %i%% %s%c", 70, "with all tests.", '\n');
    cr_assert_stdout_eq_str("I have 70% with all tests.\n");
}
