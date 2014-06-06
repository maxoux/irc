/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_channel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 07:23:39 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:12:32 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	send_channel(t_who *group, t_who *user)
{
	int		i;
	char	buffer[BUF_SIZE];

	i = 1;
	while (i <= MAX_USERS)
	{
		if (group[i].type == ID_USER &&
			ft_strequ(group[i].user.channel, user->user.channel))
		{
			sprintf(buffer, "%s%s%s%s", user->user.color,
				user->user.name, MSG_USER_SEND, DEFAULT_COLOR);
			send(group[i].fd, buffer, ft_strlen(buffer), 0);
			send(group[i].fd, user->buffer, ft_strlen(user->buffer), 0);
		}
		i++;
	}
}

void	send_channel_system(t_who *group, char *channel, char *str)
{
	int		i;
	char	buffer[BUF_SIZE];

	i = 1;
	ft_bzero(buffer, BUF_SIZE);
	sprintf(buffer, "%s%s%s\n", SYSTEM_COLOR, str, DEFAULT_COLOR);
	while (i <= MAX_USERS)
	{
		if (group[i].type == ID_USER &&
			ft_strequ(group[i].user.channel, channel))
			send(group[i].fd, buffer, ft_strlen(buffer), 0);
		i++;
	}
}
