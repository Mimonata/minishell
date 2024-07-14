/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:13:16 by spitul            #+#    #+#             */
/*   Updated: 2024/07/14 15:17:35 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	pwd(t_tools *tools, int fd)
{
	char	*pos;
	size_t	i;

	i = 0;
	pos = NULL;
	while (tools->env[i] || !pos)
	{
		pos = ft_strnstr(tools->env, "pwd", 3);
		i ++;
	}
	while (pos[] != '\n')
	{
		write(fd, &pos[len], 1);
		len ++;
	}
}
