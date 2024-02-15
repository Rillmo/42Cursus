#include "microshell.h"

void init_info(t_info *info, int argc, char **argv, char **envp) {
	info->argc = argc;
	info->argv = argv;
	info->envp = envp;
}

int	count_pipe(t_info *info, int start) {
	int i;
	int count;
	
	i = start;
	count = 0;
	while (i < info->argc && strcmp(";", info->argv[i])) {
		if (strcmp("|", info->argv[i]) == 0)
			count++;
		i++;
	}
	return count;
}

int main(int argc, char **argv, char **envp) {
	t_info info;
	t_cmd *cmd;
	int start;
	int	end;
	int stat;
	int	count;
	int	wpid;
	int last_status = 0;

	init_info(&info, argc, argv, envp);
	end = 1;
	start = 1;
	while (end < argc) {
		count = count_pipe(&info, start);
		while (end < argc && strcmp(";", argv[end]) != 0) {
			if (strcmp("|", argv[end]) == 0) {
				connect_pipe(&info, start, end, 0);
				start = end + 1;
			}
			end++;
		}
		if (strcmp(argv[start], "cd") == 0)
			cd(&info, start, end);
		else {
			connect_pipe(&info, start, end, 1);
			for (int i=0; i<=count; i++) {
				wpid = waitpid(-1, &stat, 0);
				if (wpid == info.pid)
					last_status = stat;
			}
		}
		start = end + 1;
		end++;
	}
	exit(WEXITSTATUS(last_status));
}