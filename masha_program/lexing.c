/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:07:28 by spitul            #+#    #+#             */
/*   Updated: 2024/07/11 19:27:59 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	skip_spaces(char *s)
{
	if (!s || !*s)
		return ;
	while (*s ==  32 || (*s >= 9 && *s <= 13))
		s ++;	
}

static void	quotes_check(char *s)
{
	if (!s || !*s)
		return ;
	
}


char	**lex_it(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		
	}
}
