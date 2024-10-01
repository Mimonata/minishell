/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:34:23 by spitul            #+#    #+#             */
/*   Updated: 2024/09/30 16:50:27 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//error msg need to go to stderr

// spitul@c3a8c2:~$ cat hello bestie 
// cat: hello: No such file or directory
// cat: bestie: No such file or directory
//cases when outfile is not being created 
//1. when set -e or set -o errexit is being used?? because the script terminates weil open negativ so no time for file creation
//2. using non existent dir in the path
//return bash: /non_existent_dir/output.txt: No such file or directory
//3. if on the file path there are non writeable directories

void	redir_error(int errnum, t_redircmd *rcmd)
{
	t_execcmd	*ecmd;
	int	i;
	
	ft_memset((void *)ecmd, 0, sizeof(t_execcmd));
	i = 1;
	if (errnum == ENOENT)
	{
		if (rcmd->cmd->type == 1)
		{
			ecmd = (t_execcmd *)rcmd->cmd;
			while (ecmd->arg[i])
			{
				ft_putstr_fd(ecmd->arg[0], STDERR_FILENO);
				ft_putstr_fd(": ", STDERR_FILENO);
				ft_putstr_fd(ecmd->arg[i], STDERR_FILENO);
				ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
				i ++;
			}
		}
	}
	else if (errnum == EACCES)
	{
		ft_putstr_fd("msh: ", STDERR_FILENO);
		ft_putstr_fd(rcmd->file, STDERR_FILENO);
		ft_putstr_fd(": Permission denies\n", STDERR_FILENO);
	}
}

void	output_redir(t_redircmd *rcmd)
{
	int	refd;
	int	i;
	
	refd = open(rcmd->file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (refd == -1)
		redir_error(errno, rcmd);
	dup2(refd, rcmd->fd);	
}
