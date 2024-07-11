/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:22:37 by myakoven          #+#    #+#             */
/*   Updated: 2024/07/11 19:16:11 by spitul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int error_exit(t_tools tools, int error)
{
	if (tools.env)
		;
    if (error == 1){
        perror("Problem with malloc");
    }
	return (1);
}
