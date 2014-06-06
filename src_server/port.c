/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   port.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 16:58:55 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/21 19:43:05 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

static int	sin_port(int new_port, int set)
{
	static int	port = 0;

	if (set)
		port = new_port;
	return (port);
}

int			port(void)
{
	return (sin_port(0, 0));
}

void		set_port(int port)
{
	sin_port(port, 1);
}
