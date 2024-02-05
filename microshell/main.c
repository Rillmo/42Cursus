#include "microshell.h"

void init_info(t_info *info, int argc, char **argv, char **envp) {
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
}

int main(int argc, char **argv, char **envp) {
	t_info info;
	int	i;

	init_info(&info, argc, argv, envp);
	i = 1;
	char **tmp = (char **)malloc(sizeof(char *) * 2);
	tmp[0] = strdup(argv[i]);
	tmp[1] = 0;
	execve(argv[i], tmp, envp);
	while (1) {
		if (strcmp("|", argv[i]) == 0) {
			connect_pipe(&info, i);
		}
		i++;
	}
}