/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:13:16 by spitul            #+#    #+#             */
/*   Updated: 2024/07/14 15:41:55 by spitul           ###   ########.fr       */
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
		pos = ft_strnstr(tools->env[i], "pwd", 3);
		i ++;
	}
	if (pos != NULL)
		ft_putstr_fd(pos + 4, fd);
}
