/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:48:13 by spitul            #+#    #+#             */
/*   Updated: 2024/09/05 20:32:47 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int	check_builtin(char *s)
{
	int		i;
	char	*builtins[] = {"echo", "cd", "pwd", "export", 
		"unset", "env", "exit"};

	if (ft_strncmp(s, builtins[0], ft_strlen(s)) == 0)
		echo();
	else if (ft_strncmp(s, builtins[1], ft_strlen(s)) == 0)
		cd();
	else if (ft_strncmp(s, builtins[2], ft_strlen(s)) == 0)
		pwd();
	else if (ft_strncmp(s, builtins[3], ft_strlen(s)) == 0)
		export();
	else if (ft_strncmp(s, builtins[4], ft_strlen(s)) == 0)	
		unset();
	else if (ft_strncmp(s, builtins[5], ft_strlen(s)) == 0)		
		env();
	else if (ft_strncmp(s, builtins[6], ft_strlen(s)) == 0)
		ft_exit();	
}
