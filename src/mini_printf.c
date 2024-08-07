/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** mini printf
*/

#include "../includes/mini_printf.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return 0;
}
