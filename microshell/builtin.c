#include "microshell.h"

void	cd(t_info *info, int start, int end)
{
	int count;

	count = end - start;
	if (count != 2)
		cd_arg_error();	// error
	if (chdir(info->argv[end - 1]) == -1)
		cd_dir_error(info->argv[end - 1]);
}