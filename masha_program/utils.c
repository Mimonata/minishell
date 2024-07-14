/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:15:14 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/14 23:24:06 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tab(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}

int	istoken(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

int	isquote(char c)
{
	return (c == '\'' || c == '\"');
}

int	skip_spaces(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (i);
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (i);
}

int	get_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}
