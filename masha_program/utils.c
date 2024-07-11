/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:15:14 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/11 19:51:34 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**free_array(char **res, int nb)
{
	int	i;

	i = 0;
	while (i <= nb)
	{
		free(res[i]);
		i ++;
	}
	free(res);
	return (NULL);
}
 void	print_it(char **envp)
{
	size_t i = 0;

	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i ++;
	}
}

char	**copy_env(char **env)
{
	char **envp;
	int len_pointers;
	int	i;
	// TODO
	i = 0;
	len_pointers = 0;
	// len_pointers = ft_strlen(env) / sizeof(char *);
	while (env[len_pointers] != NULL)
	{
		len_pointers++;
	}
	envp = ft_calloc((len_pointers + 3), sizeof(char *));
	if (!envp)
		return (NULL);
	while (i < len_pointers && env[i])
	{
		envp[i] = ft_strdup(env[i]);
		if (!envp[i])
		{
			free_array(env, len_pointers);
			return (NULL);
		}
		i ++;
	}
	return (envp);
}

