/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:21:56 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/14 23:30:03 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void    exit_with_err(void)
{
    write(2, "Error\n", 6);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    ft_printf("this is checker!");
    return (0);
}
