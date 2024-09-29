/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:00:21 by myakoven          #+#    #+#             */
/*   Updated: 2024/09/24 16:54:40 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

# define EXEC	1
# define REDIR	2
# define PIPE	3

typedef struct	s_cmd
{
	int	type;	
}				t_cmd;				

typedef struct	s_execcmd
{
	int	type;
	char	**arg;
}				t_execcmd;

typedef struct s_redircmd
{
	int	type;
	t_cmd	*cmd;
	char	*file;
	int		mode;
	int		fd;	
}				t_redircmd;

typedef struct	s_pipecmd
{
	int	type;
	t_cmd	*left;
	t_cmd	*right;
}				t_pipecmd;

typedef struct s_tools
{
	char	**env;
	size_t	env_len;
	char	*line;
	char	**lexed;
}			t_tools;

// typedef struct	cmd_s
// {
// 	char	**cmds;
// }				cmd_t; 

#endif