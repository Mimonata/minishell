/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:51:01 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/11 20:30:46 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_tools	tools;

	if (argc > 1 || argv[1])
	{
		ft_putstr_fd("This program does not accept arguments\n", 2);
	}
	// tools.env = env;
	tools.env = copy_env(env);
	 if (!tools.env)
	 	return(error_exit(tools, 1));
	shell_loop(&tools);
	clear_history();
	return (0);
}

int	shell_loop(t_tools *tools)
{
	if (!tools->env)
		return (1);
	tools->line = readline("minishell: ");
	if (!tools->line)
	{
		return (1);
	}
	// tools.line
	lex_it(tools);
	add_history(tools->line);
	printf("%s\n", tools->line);
	free(tools->line);
	return (0);
}
