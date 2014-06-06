/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_connection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 00:45:01 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:00:44 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	close_connection(t_who *user)
{
	printf("closing connection...\n");
	ft_strcpy(user->user.default_name, user->user.name);
	sprintf(user->user.channel, DEFAULT_CHANNEL);
	ft_bzero(user->buffer, BUF_SIZE);
	close(user->fd);
	user->fd = 0;
	user->type = ID_FREE;
	ft_strcpy(user->user.name, user->user.default_name);
}
