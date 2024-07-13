/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:07:28 by spitul            #+#    #+#             */
/*   Updated: 2024/07/13 19:45:39 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lexer(t_tools *tools)
{
	int	parts;
	int	lex_i;
	int	i;
	int	len;

	i = 0;
	lex_i = 0;
	parts = count_parts(tools->line);
	tools->lexed = ft_calloc((parts + 2), sizeof(char *));
	if (!tools->lexed)
		error_exit(tools, 1);
	while (lex_i < parts && tools->line[i])
	{
		if (tools->line[i] && !istoken(tools->line[i]))
			len = getlen_command(tools, i);
		else if (tools->line[i] == '<' || tools->line[i] == '>')
			len = getlen_redirect(tools, i);
		else if (tools->line[i] == '|')
			len = 1;
		tools->lexed[lex_i] = ft_substr(tools->line, i, len);
		i += len;
		lex_i++;
	}
}
int	getlen_command(t_tools *tools, int i)
{
	int	og_index;

	og_index = i;
	i++;
	while (tools->line[i])
	{
		if (!istoken(tools->line[i]) && !isquote(tools->line[i]))
			i++;
		else if (isquote(tools->line[i]))
			i = check_quotes(tools, i) + 1;
		else if (istoken(tools->line[i]))
			break ;
	}
	return (i - og_index + 1);
}

int	getlen_redirect(t_tools *tools, int i)
{
	int	og_index;

	og_index = i;
	i++;
	while (tools->line[i])
	{
		if ((i - og_index) == 1 && tools->line[i] == tools->line[i - 1])
			i++;
		else if (tools->line[i] == '\"' || tools->line[i] == '\'')
		{
			i = check_quotes(tools->line, i);
			break ;
		}
		else if (ft_isspace(tools->line[i + 1]) && (ft_isprint(tools->line[i])
				&& (i > og_index)))
			break ;
		else
			i++;
	}
	return (i - og_index + 1);
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


// DOES NOT WORK!!! TODO
// REWRITE INTO GET_LEN???, no writing should take place here...
// Need to find the length of the redirect > end of the file name in quotes or without!
// strdup the rest! Should probably completely rewrite this
/*
void	get_redirect(t_tools *tools, int lex_i, int i, int j)
{
	bool	wordflag;
	int		end_quote_index;
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
			end_quote_index = check_quotes(tools->line, i);
			tools->lexed[lex_i] = ft_calloc(end_quote_index - og_index + 2,
					sizeof(char));
			if (!tools->lexed[lex_i])
				error_exit(tools, 1);
			while (tools->line[i] && j < (end_quote_index - og_index))
				tools->lexed[lex_i][j++] = tools->line[i++];
			wordflag = true;
			break ;
		}
		// find_end(tools, lex_i, i);
		if (j == 1 && tools->line[i] == tools->line[i - 1])
			tools->lexed[lex_i][j++] = tools->line[i++];
		else if (ft_isspace(tools->line[i + 1])
			&& (ft_isprint(tools->line[i])
				&& (j > 0)))
			wordflag = true;
		tools->lexed[lex_i][j++] = tools->line[i++];
	}
}
*/