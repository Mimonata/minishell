/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:13:16 by spitul            #+#    #+#             */
/*   Updated: 2024/07/14 20:08:25 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

char	*get_env_var(t_tools *tools, char *var)
{
	int		i;
	size_t	len;
	char	*pos;

	if (!var || !tools)
		exit(EXIT_FAILURE); //?
	pos = NULL;
	i = 0;
	len = ft_strlen(var);
	while (tools->env[i] && !pos)
	{
		pos = ft_strnstr(tools->env[i], var, len);
		i ++;
	}
	return(pos + len + 1);	
}

void	pwd(t_tools *tools, int fd)
{
	char	*pos;
	size_t	i;

	i = 0;
	pos = get_env_var(tools, "PWD");
	if (pos != NULL)
		ft_putstr_fd(pos, fd);
	else
		perror("pwd: error retrieving current directory:");
}
