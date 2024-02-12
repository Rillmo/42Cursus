#ifndef MICROSHELL_H
#define MICROSHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

typedef struct s_info
{
	int argc;
	char **argv;
	char **envp;
	int	fds[2];
	int pid;
}	t_info;

typedef struct s_cmd
{
	char *cmd_name;
	char **arg;
}	t_cmd;

void	connect_pipe(t_info *info, int start, int end, int last);
t_cmd	*make_cmd(t_info *info, int start, int end);
void	cd(t_info *info, int start, int end);
void 	exec_error(char *cmd);
void	cd_arg_error(void);
void	cd_dir_error(char *arg);
void 	fatal_error(void);

#endif