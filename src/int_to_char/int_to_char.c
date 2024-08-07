/*
** EPITECH PROJECT, 2024
** my_atoi.c
** File description:
** my_atoi
*/

#include <stdlib.h>

#include "../../includes/int_to_char.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

char *my_strdup(char const *str)
{
    int size = my_strlen(str);
    char *result = malloc(sizeof(char) * (size + 1));
    int i = 0;

    for (; i < size; i++)
        result[i] = str[i];
    result[i] = '\0';
    return result;
}

char *int_to_char(unsigned int data)
{
    char *before_result = malloc(sizeof(char) * 10 + 1);
    char *result;
    int divise = 1000000000;
    unsigned int temp = data;
    unsigned int result_division;

    for (int i = 0; divise != 0; i++) {
        result_division = temp / divise;
        before_result[i] = 48 + result_division;
        temp -= divise * result_division;
        divise /= 10;
    }
    before_result[10] = '\0';
    result = my_strdup(before_result);
    free(before_result);
    return result;
}

char *remove_zeros(char *nb)
{
    int other_nb = 0;
    int nb_zeros = 0;
    int j = 0;
    int size = my_strlen(nb);
    char *result;

    for (int i = 0; i < size; i++) {
        if (other_nb != 0)
            break;
        if (nb[i] == '0')
            nb_zeros++;
        else
            other_nb++;
    }
    result = malloc(sizeof(char) * (size - nb_zeros + 1));
    for (; j < size - nb_zeros; j++)
        result[j] = nb[j + nb_zeros];
    result[j] = '\0';
    return result;
}
