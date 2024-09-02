/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:13:16 by spitul            #+#    #+#             */
/*   Updated: 2024/09/02 20:02:25 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
	Wanted to make a note on this for later:

	c4a6c10% pwd ok
	pwd: too many arguments

	After the have the 2d command array maybe we can stick it in there?

	void	pwd(t_tools *tools, char **cmd)?

	i have to change all my perrors to ft_putstr_fd(str, 2) - oops

*/

void	pwd(t_tools *tools, cmd_t *cmd)
{
	char *cwd;
	size_t i;

	i = 0;
	cwd = NULL;
	if (get_matrix_len(cmd->cmds) > 1)
		ft_putstr_fd("pwd: too many arguments\n", 2);
	cwd = getcwd(NULL, 0); //should we check for malloc error
	if (cwd != NULL)
	{
		ft_putstr_fd(cwd, 1);
		ft_putstr_fd("\n", 1);
		free (cwd);
	}
	else
		perror("pwd: error retrieving current directory:");
}
