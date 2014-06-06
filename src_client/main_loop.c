/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 04:20:56 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:31:38 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

void	recv_send(fd_set *listener, int socket)
{
	char	buffer[BUF_SIZE];

	ft_bzero(buffer, BUF_SIZE);
	if (FD_ISSET(socket, listener))
	{
		recv(socket, buffer, BUF_SIZE, 0);
		printf("%s", buffer);
	}
	ft_bzero(buffer, BUF_SIZE);
	if (FD_ISSET(0, listener))
	{
		read(0, buffer, BUF_SIZE - 1);
		if (ft_strequ(buffer, "/leave\n"))
			ft_exit(NULL);
		send(socket, buffer, ft_strlen(buffer), 0);
	}
}

void	main_loop(int socket)
{
	fd_set	listener;
	int		response;

	while (42)
	{
		FD_ZERO(&listener);
		FD_SET(0, &listener);
		FD_SET(socket, &listener);
		response = select(socket + 1, &listener, NULL, NULL, NULL);
		if (response == -1)
			ft_exit(ERR_SELECT);
		else if (response)
			recv_send(&listener, socket);
	}
}
