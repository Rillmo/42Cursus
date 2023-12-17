/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:38:15 by macbookpro        #+#    #+#             */
/*   Updated: 2023/12/17 23:41:53 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void	*p_function(void *data)
{
	pid_t		pid;
	pthread_t	tid;
	char		*thread_name;
	int			i;

	pid = getpid();
	tid = pthread_self();
	thread_name = (char *)data;
	i = 0;
	while (i < 3)
	{
		printf("thread name : %s tid : %d pid %d\n", thread_name, tid, pid);
		i++;
		sleep(1);
	}
}

int	main(void)
{
	
}