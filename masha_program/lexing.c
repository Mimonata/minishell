/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:07:28 by spitul            #+#    #+#             */
/*   Updated: 2024/07/11 20:33:20 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:07:28 by spitul            #+#    #+#             */
/*   Updated: 2024/07/11 20:24:59 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static void	skip_spaces(char *s)
// {
// 	if (!s || !*s)
// 		return ;
// 	while (*s == 32 || (*s >= 9 && *s <= 13))
// 		s++;
// }

// static void	quotes_check(char *s)
// {
// 	if (!s || !*s)
// 		return ;
// }

char	**lex_it(t_tools *tools)
{
	int		i;
	int		reds;
	int		pipes;
	bool	closed;
	int		j;

	closed = true;
	i = 0;
	reds = 0;
	while (tools->line[i])
	{
		j = 0;
		if (tools->line[i] == "\"")
			i = check_d_quotes(tools->line, i);
		else if (tools->line[i] == "\'")
			i = check_s_quotes(tools->line, i);
		if (i < -1)
			error_exit(tools, 2);
		if (tools->line[i] == "<" || tools->line[i] == "<")
		{
			if (tools->line[i + 1] == "<" && tools->line[i] == "<")
				i++;
			else if (tools->line[i + 1] == ">" && tools->line[i] == ">")
				i++;
			reds++;
		}
		else if (tools->line[i] == "|")
			pipes++;
		if (tools->line[i])
			i++;
	}
}

int	check_d_quotes(char *line, int i)
{
	int		j;
	bool	closed;

	j = 0;
	closed = false;
	closed = false;
	while (line[i + j] && line[i + j] != "\"")
		j++;
	if (line[i] == "\"")
		closed = true;
	if (closed == true)
		i = i + j;
	else if (closed == false)
		return (-1);
	// line[i] = " ";
}

// LEX BEFORE EVERYTHING ELSE?
