/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_receive.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 00:22:15 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:11:18 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	user_receive(t_who *group, t_who *user)
{
	int		response;
	char	str[1024];

	(void)group;
	ft_bzero(str, 1024);
	response = recv(user->fd, str, BUF_SIZE, 0);
	ft_strcat(user->buffer, str);
	if (response && ft_strchr(user->buffer, '\n') != NULL)
	{
		if (user->buffer[0] == '/')
			user_command(group, user);
		else
			send_channel(group, user);
		ft_bzero(user->buffer, sizeof(user->buffer));
	}
	else if (response == 0)
	{
		sprintf(str, MSG_USER_QUIT, user->user.name);
		close_connection(user);
		send_broadcast(group, str);
	}
}
