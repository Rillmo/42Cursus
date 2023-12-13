/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 23:15:00 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/13 23:46:12 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

int is_sign(char c)
{
    if (c == '-' || c == '+')
        return (1);
    return (0);
}

int count_word(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && isspace(str[i]))
            i++;
        if (is_sign(str[i]))
            i++;
        if (isdigit(str[i]))
        {
            count++;
            while (str[i] && isdigit(str[i]))
                i++;
        }
    }
    return (count);
}

void    check_input_err(int argc, char **argv)
{
    int		i;
    int		j;
    char	*str;

    i = 1;
    while (i < argc)
    {
        str = argv[i];
        j = 0;
        while (str[j])
        {
            if (!isdigit(str[i]) && !isspace(str[i] && !is_sign(str[i])))
            {
                write(2, "Error\n", 6);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    int count;
    int i;
    int *num;

    i = 1;
    count = 0;
    check_input_err(argc, argv);
    while (i < argc)
        count += count_word(argv[i++]);
}