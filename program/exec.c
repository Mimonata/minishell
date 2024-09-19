/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:48:13 by spitul            #+#    #+#             */
/*   Updated: 2024/09/16 20:00:14 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

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
		a[1] =cd();
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
static char	*get_path(char **env, char)
{
	int	i;

	i=0;
	while ()		
}

int	check_cmd(char *path, char *cmd)
{

}

void	check_run_cmd(char **env)
{
	char	*path;
	char	**split_path;
	int		i;

	i = 0;
	if (!check_builtin())
	{
		path = get_env_var(env, "PATH");
		split_path = ft_split(path, ":");
		while (*split_path[i])
		{
			if (check_cmd(split_path[i], ))
		}			
}