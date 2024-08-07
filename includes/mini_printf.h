/*
** EPITECH PROJECT, 2024
** mini_printf.h
** File description:
** Header file
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef MINI_PRINTF_H_
    #define MINI_PRINTF_H_

int my_putchar(char c);
int my_putstr(char *str);

int my_strlen(char const *str);
char *my_strdup(char const *str);
char *int_to_char(unsigned int data);
char *remove_zeros(char *nb);

#endif /* MINI_PRINTF_H_ */
