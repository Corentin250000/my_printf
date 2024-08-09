/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** mini printf
*/

#include "../includes/mini_printf.h"

int print_int(int nb)
{
    int temp = 0;
    int size = 0;

    if (nb == 0) {
        my_putchar('0');
        size++;
    } else if (nb < 0) {
        my_putchar('-');
        size++;
        temp = nb * -1;
        size += my_putstr(remove_zeros(int_to_char(temp)));
    } else
        size += my_putstr(remove_zeros(int_to_char(nb)));
    return size;
}

int action_pourcent(char letter_pourcent, va_list ap)
{
    int size_print = 0;

    switch (letter_pourcent) {
    case 'd':
        size_print = print_int(va_arg(ap, int));
        break;
    case 'i':
        size_print = print_int(va_arg(ap, int));
        break;
    case 's':
        size_print += my_putstr(va_arg(ap, char *));
        break;
    case 'c':
        my_putchar(va_arg(ap, int));
        size_print++;
        break;
    default:
        break;
    }
    return size_print;
}

int mini_printf(char const *format, ...)
{
    va_list ap;
    int size_print = 0;

    va_start(ap, format);
    for (int i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%' && format[i + 1] == '%') {
            my_putchar('%');
            size_print++;
        }
        if (format[i] == '%') {
            size_print += action_pourcent(format[i + 1], ap);
            i++;
        } else {
            my_putchar(format[i]);
            size_print++;
        }
    }
    va_end(ap);
    return size_print;
}
