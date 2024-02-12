#include "microshell.h"

int	ft_strlen(char *str) {
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

void exec_error(char *cmd) {
	write(2, "error: cannot execute " , 22);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	exit(1);
}

void cd_arg_error(void) {
	write(2, "error: cd: bad arguments\n", 25);
	exit(1);
}

void cd_dir_error(char *arg) {
	write(2, "error: cd: cannot change directory to ", 38);
	write(2, arg, ft_strlen(arg));
	write(2, "\n", 1);
	exit(1);
}

void fatal_error(void) {
	write(2, "error: fatal\n", 13);
	exit(1);
}