/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 19:50:19 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:14:41 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	ft_usage(char *name)
{
	printf("%s: port <addr> <port>\n", name);
	ft_exit(NULL);
}

void	ft_exit(char *str)
{
	if (str)
		printf("Error: %s\n", str);
	_exit(0);
}
