/*
** EPITECH PROJECT, 2024
** print_str.c
** File description:
** print str
*/

#include "../includes/mini_printf.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_putstr(char *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        size++;
        my_putchar(str[i]);
    }
    return size;
}
