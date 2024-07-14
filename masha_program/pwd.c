/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:13:16 by spitul            #+#    #+#             */
/*   Updated: 2024/07/14 23:29:22 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*

	Wanted to make a note on this:

	c4a6c10% pwd ok
	pwd: too many arguments

	for after the have the 2d array:

	i think pwd have to check the entire command string that start with pwd.... it might be nice if each builtin received the same thing as execve,
	which is a 2d array of the command,
	then it could just check the length of the 2d and put that error?

	void	pwd(t_tools *tools, char **cmd)?

	perror returns an actual error... i have to change all my perrors - oops

	*/

void	pwd(t_tools *tools)
{
	char	*pos;
	size_t	i;

	i = 0;
	pos = get_env_var(tools, "PWD");
	if (pos != NULL)
	{
		ft_putstr_fd(pos, 1);
		ft_putstr_fd("\n", 1);
	}
	else
		// perror("pwd: error retrieving current directory:");
		ft_putstr_fd("pwd: error retrieving current directory\n", 2);

}
