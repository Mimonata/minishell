/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:51:01 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/08 20:20:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"
#include <readline/history.h>
#include <readline/readline.h>

// #include

// int	main(int argc, char **argv, char **env)
int	main(int argc, char **argv, char **env)
{
	t_tools	tools;

	// char arr[10];
	if (argc > 1 && argv[1])
	{
		ft_putstr_fd("This program does not accept arguments\n", 2);
	}
	tools.env = env;
	shell_loop(tools);
	return (0);
}

int	shell_loop(t_tools tools)
{
	char *line;
	if (!tools.env)
		return (1);
	line = readline("minishell: ");
	if (!line)
	{
		return (1);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}