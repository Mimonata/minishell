/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:48:13 by spitul            #+#    #+#             */
/*   Updated: 2024/10/04 15:29:12 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

//error msg need to go to stderr

static void	init_builtin_array(char **b)
{
	b[0] = "echo";
	b[1] = "cd";
	b[2] = "pwd";
	b[3] = "export";
	b[4] = "unset";
	b[5] = "env";
	b[6] = "exit";
}

int	check_builtin(char *s)
{
	int		a[7];
	int		len;
	char	*builtins[7];

	init_builtin_array(builtins);
	len = ft_strlen(s);
	ft_bzero((void *)a, 7 * sizeof(int)); 
	if (len == 4 && ft_strncmp(s, builtins[0], len) == 0)
		a[0] = echo();
	else if (len == 2 && ft_strncmp(s, builtins[1], len) == 0)
		a[1] = cd();
	else if (len == 3 && ft_strncmp(s, builtins[2], len) == 0)
		a[2] = pwd();
	else if (len == 6 && ft_strncmp(s, builtins[3], len) == 0)
		a[3] = export();
	else if (len == 5 && ft_strncmp(s, builtins[4], len) == 0)
		a[4] = unset();
	else if (len == 3 && ft_strncmp(s, builtins[5], len) == 0)
		a[5] = env();
	else if (len == 4 && ft_strncmp(s, builtins[6], len) == 0)
		a[6] = ft_exit();
	return (a[0] || a[1] || a[2] || a[3] || a[4] || a[5] || a[6]);
}

char	*check_cmd_in_path(char *path, t_execcmd *cmd)
{
	char	*cmdpath;
	char	*temp;

	cmdpath = NULL;
	temp = NULL;
	temp = ft_strjoin(path, "/");
	if (!temp)
		return (NULL);
	cmdpath = ft_strjoin(temp, cmd->arg[0]);
	if (!cmdpath)
		return (NULL);
	free (temp);
	if (access(cmdpath, F_OK | X_OK) == 0)
		return (cmdpath);
	else
	{ 
		if (access(cmdpath, F_OK) != 0)
			printf("msh: command not found: %s\n", cmd->arg[0]);
		else if (access(cmdpath, X_OK) != 0) //insufficient rights 
	//kommt das hier oder anderswo - ist es nur ein problem bei args?
			printf("msh: permission denied %s\n", cmd->arg[0]);
		free (cmdpath);
		return (NULL); //TODO error handling - do we have to always write in the strerror
	}
}

void	check_cmd(char **env, t_execcmd *ecmd)
{
	char	*path;
	char	*pathcmd;
	char	**split_path;
	int		i;

	i = 0;
	pathcmd = NULL;
	path = get_env_var(env, "PATH");
	if (!path)
		return ;
	split_path = ft_split(path, ":");
	if (!split_path)
		return ; // exit failure? 
	if (check_builtin(ecmd->arg[0]))
		return ;
	while (split_path[i])
	{
		pathcmd = check_cmd_in_path(split_path[i], ecmd->arg[0]);
		if (pathcmd != NULL)
		{
			exec_cmd(pathcmd, ecmd, env); //pathcmd has to be freed
			free (pathcmd);
			break ;
		}
		i ++;
	}
	free_tab(split_path);
}

void 	exec_cmd(t_cmd *cmd, char **env)
{
	t_execcmd	*ecmd;
	t_redircmd	*rcmd;
	t_pipecmd	*pcmd;
	
	ft_memset((void *)ecmd, 0, sizeof(*ecmd));
	ft_memset((void *)rcmd, 0, sizeof(*rcmd));
	ft_memset((void *)pcmd, 0, sizeof(*pcmd));
	if (cmd->type == 1)
	{
		ecmd = (t_execcmd *)cmd;
		check_cmd(env, ecmd);
	}
	else if (cmd->type == 2)
	{
		rcmd = (t_redircmd *)cmd;
		redir_cmd(rcmd);
	}
	else if (cmd->type == 3)
	{
		pcmd = (t_pipecmd *)cmd;
		pipe_cmd(pcmd);
	}
	else
		exit (-1); //where is this returned and what happens to it
}

/*void	_exec_cmd(char *pathcmd, t_execcmd *cmd, char **env)
{
	pid_t	pid;
	
	pid = fork();
	if (pid == -1)
		return (FORK_ERROR);//dunno
	if (pid == 0)
	{
		if (execve(pathcmd, cmd->arg, env) == -1)
		// better an error handling function
			printf("msh: %s: no such file or directory\n", cmd->arg[0]);
	}
	else
		waitpid(pid, NULL, 0);
}*/

