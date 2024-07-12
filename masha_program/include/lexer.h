/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myakoven <myakoven@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 20:26:33 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/13 00:47:17 by myakoven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

char	**lexer(t_tools *tools);
int		check_quotes(t_tools *tools, int i);
void	get_redirect(t_tools *tools, int lex_i, int i, int j);
int		istoken(char c);
#endif