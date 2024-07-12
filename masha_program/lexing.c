/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:07:28 by spitul            #+#    #+#             */
/*   Updated: 2024/07/13 01:14:35 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lexer(t_tools *tools)
{
	int	parts;
	int	lex_i;
	int	i;
	int	j;

	i = 0;
	lex_i = 0;
	parts = count_parts(tools->line);
	tools->lexed = ft_calloc((parts + 2), sizeof(char *));
	if (!tools->lexed)
		error_exit(tools, 1); // malloc
	while (lex_i < parts)
	{
		j = 0;
		while (tools->line[i])
		{
			if (istoken(tools->line[i]))
			{
				// get_length here, malloc before writing please !!!  TODO TO DO
				if (tools->line[i] == '<' || tools->line[i] == '>' && j == 0)
					get_redirect(tools, lex_i, i, j);
				else if (tools->line[i] == '|' && j == 0)
					tools->lexed[lex_i][j++] = tools->line[i++];
				break ;
			}
			tools->lexed[lex_i][j++] = tools->line[i++];
		}
		lex_i++;
	}
}

// DOES NOT WORK!!! TODO
// REWRITE INTO GET_LEN???, no writing should take place here...
// Need to find the length of the redirect > end of the file name in quotes or without!
// strdup the rest! Should probably completely rewrite this
void	get_redirect(t_tools *tools, int lex_i, int i, int j)
{
	bool	wordflag;
	int		q_end;
	int		og_index;
	int		len;

	og_index = i;
	wordflag = false;
	while (tools->line[i] && wordflag == false)
	{
		// 	if (j == 1 && tools->line[i] == tools->line[i - 1])
		// 		tools->lexed[lex_i][j++] = tools->line[i++];
		if (tools->line[i] == '\"' || tools->line[i] == '\'')
		{
			q_end = check_quotes(tools->line, i);
			tools->lexed[lex_i] = ft_calloc(q_end - og_index + 2, sizeof(char));
			if (!tools->lexed[lex_i])
				error_exit(tools, 1);
			while (tools->line[i] && j < (q_end - og_index))
				tools->lexed[lex_i][j++] = tools->line[i++];
			wordflag = true;
			break ;
		}
		// find_end(tools, lex_i, i);
		if (j == 1 && tools->line[i] == tools->line[i - 1])
			tools->lexed[lex_i][j++] = tools->line[i++];
		else if (ft_isspace(tools->line[i + 1]) && (ft_isprint(tools->line[i])
				&& (j > 0)))
			wordflag = true;
		tools->lexed[lex_i][j++] = tools->line[i++];
	}
}

int	count_parts(char *line)
{
	int	i;
	int	redirs;
	int	j;
	int	pipes;

	i = 0;
	redirs = 0;
	pipes = 0;
	while (line[i])
	{
		j = 0;
		if (line[i] == '\"' || line[i] == '\'')
			i = check_quotes(line, i) + 1;
		if (line[i] == '<' || line[i] == '<')
		{
			if (line[i + 1] == line[i])
				i++;
			redirs++;
		}
		else if (line[i++] == '|')
			pipes++;
	}
	pipes = (pipes + pipes + 1) + redirs;
	return (pipes);
}

// return pointer to the closing quote or exits program
int	check_quotes(t_tools *tools, int i)
{
	int		j;
	char	*line;

	line = tools->line;
	j = 1;
	while (line[i + j])
	{
		if (line[i] == line[i + j])
			return (i + j);
		j++;
	}
	error_exit(tools, 2);
}

// LEX BEFORE EVERYTHING ELSE?

// from get redirect?
// else if (ft_isspace(tools->line[i + 1])
// && (ft_isprint(tools->line[i])
// 		&& (j > 1 || (tools->line[i] != '<' && tools->line[i] != '>'))))
// {
// 	wordflag = true;
// 	tools->lexed[lex_i][j++] = tools->line[i++];
// }
// else
// 	tools->lexed[lex_i][j++] = tools->line[i++];

// if (tools->line[i] == '<' || tools->line[i] == '>')
// {
// 	get_redirect(tools, lex_i, i, j);
// 	break ;
// }
// else if (tools->line[i] == '|' && j == 0)
// {
// 	tools->lexed[lex_i][j++] = tools->line[i++];
// 	break ;
// }
// else
// 	tools->lexed[lex_i][j++] = tools->line[i++];
// // <>
// if (j > 0 && istoken(tools->line[i]))
// 	break ;
