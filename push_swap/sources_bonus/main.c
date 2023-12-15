/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 23:21:56 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/15 21:27:56 by junkim2          ###   ########.fr       */
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
	argc = 1;
	argv = NULL;
    printf("this is checker!");
    return (0);
}
