/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:12:04 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/14 20:09:28 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include "builtins.h"
# include "lexer.h"
# include "structs.h"
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/************************/
/******** main.c ********/
/************************/

int		shell_loop(t_tools *tools);

/************************/
/******* utils.c ********/
/************************/
char	**copy_env(t_tools *tools, char **env);
char	*get_env_var(t_tools *tools, char *var);
void	print_tab(char **envp);
int		istoken(char c);
int		isquote(char c);
int		skip_spaces(char *s);

/************************/
/******* error.c ********/
/************************/
int		error_exit(t_tools *tools, int error);
void	clean_tools(t_tools *tools);
char	**free_array(char **res, int nb);

/************************/
/******* built_ins.c ********/
/************************/

void	pwd(t_tools *tools, int fd);

#endif