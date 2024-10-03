/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:34:23 by spitul            #+#    #+#             */
/*   Updated: 2024/10/03 18:39:30 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//error msg need to go to stderr

// spitul@c3a6c6:~$ cat <text2.txt 
// how about
// some text
// spitul@c3a6c6:~$ cat <text2.txt <bibi 
// bash: bibi: No such file or directory

//cases when outfile is not being created 
//1. when set -e or set -o errexit is being used?? because the script terminates weil open negativ so no time for file creation
//2. using non existent dir in the path
//return bash: /non_existent_dir/output.txt: No such file or directory
//3. if on the file path there are non writeable directories

void	redir_error(int errnum, t_redircmd *rcmd)
{
	if (errnum == ENOENT)
	{
		ft_putstr_fd("msh: ", STDERR_FILENO);
		ft_putstr_fd(rcmd->file, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(strerror(errnum), STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
	}
	else if (errnum == EACCES)
	{
		ft_putstr_fd("msh: ", STDERR_FILENO);
		ft_putstr_fd(rcmd->file, STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO); //dunno if change to strerror
	}
	else if (errnum == EMFILE || errnum == ENFILE)
		ft_putstr_fd("msh: Too many open files\n", STDERR_FILENO);
	else if (errnum == ENOSPC)
	{
		if (rcmd->fd == 0)
		{
			ft_putstr_fd("msh: ", STDERR_FILENO);
			ft_putstr_fd(rcmd->file, STDERR_FILENO);
			ft_putstr_fd(": No space left on device\n", STDERR_FILENO);
		}
		if (rcmd->fd == 1)
			ft_putstr_fd("msh: cannot create file: No space left on device\n", STDERR_FILENO);
	}
}

void	redir_cmd(t_redircmd *rcmd)
{
	close(rcmd->fd);
	rcmd->fd = open(rcmd->file, rcmd->mode, 0644);
	if (rcmd->fd == -1)
	{
		redir_error(errno, rcmd);
		exit(-1); //geht das?
	}
	exec_cmd(rcmd->cmd);
}
