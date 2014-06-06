/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_users.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 07:48:19 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:13:57 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void		cmd_change_nick(t_who *group, t_who *user)
{
	char	**split;
	int		i;
	char	buffer[BUF_SIZE];

	split = ft_strsplit(user->buffer, ' ');
	if (!split[1] || ft_strlen(split[1]) > 9)
	{
		send(user->fd, ERR_NICK_TOO, sizeof(ERR_NICK_TOO), 0);
		return ;
	}
	i = 0;
	while (i <= MAX_USERS)
	{
		if (ft_strequ(group[i].user.name, split[1]))
		{
			send(user->fd, ERR_NICK_EXIST, sizeof(ERR_NICK_EXIST), 0);
			return ;
		}
		i++;
	}
	sprintf(buffer, MSG_USER_NICK, user->user.name, split[1]);
	send_channel_system(group, user->user.channel, buffer);
	ft_strcpy(user->user.name, split[1]);
	free(split);
}

void		cmd_change_channel(t_who *group, t_who *user)
{
	char	buffer[BUF_SIZE];
	char	**split;

	split = ft_strsplit(user->buffer, ' ');
	if (!split[1] || ft_strlen(split[1]) > 255)
	{
		send(user->fd, ERR_CHAN_TOO, sizeof(ERR_CHAN_TOO), 0);
		return ;
	}
	sprintf(buffer, MSG_USER_LEAVE, user->user.name, user->user.channel);
	send_channel_system(group, user->user.channel, buffer);
	ft_strcpy(user->user.channel, split[1]);
	sprintf(buffer, MSG_USER_JOIN, user->user.name, user->user.channel);
	send_channel_system(group, user->user.channel, buffer);
}

void		cmd_quit_channel(t_who *group, t_who *user)
{
	char buffer[BUF_SIZE];

	sprintf(buffer, MSG_USER_LEAVE, user->user.name, user->user.channel);
	send_channel_system(group, user->user.channel, buffer);
	ft_strcpy(user->user.channel, DEFAULT_CHANNEL);
	sprintf(buffer, MSG_USER_JOIN, user->user.name, user->user.channel);
	send_channel_system(group, user->user.channel, buffer);
}

void		cmd_who_channel(t_who *group, t_who *user)
{
	int	i;

	send(user->fd, "On channel: \n", ft_strlen("On channel: \n"), 0);
	i = 0;
	while (i <= MAX_USERS)
	{
		if (group[i].type == ID_USER &&
			ft_strequ(group[i].user.channel, user->user.channel))
		{
			send(user->fd, group[i].user.name,
				ft_strlen(group[i].user.name), 0);
			send(user->fd, " ", ft_strlen(" "), 0);
		}
		i++;
	}
	send(user->fd, "\n", ft_strlen("n"), 0);
}

void		cmd_send_message(t_who *group, t_who *user)
{
	int		i;
	char	**split;
	char	buffer[BUF_SIZE];

	split = ft_strsplit(user->buffer, ' ');
	i = 0;
	if (!split[1] || !split[2])
		return ((void)send(user->fd, ERR_MSG_USAGE,
		ft_strlen(ERR_MSG_USAGE), 0));
	while (i <= MAX_USERS)
	{
		if (group[i].type == ID_USER && ft_strequ(group[i].user.name, split[1]))
		{
			sprintf(buffer, "%s#%s -> %s: %s%s\n", user->user.color,
				user->user.name, group[i].user.name,
				(user->buffer + ft_strlen(split[0]) +
				ft_strlen(split[1]) + 2), DEFAULT_COLOR);
			send(user->fd, buffer, ft_strlen(buffer), 0);
			send(group[i].fd, buffer, ft_strlen(buffer), 0);
			return ;
		}
		i++;
	}
	send(user->fd, ERR_MSG_UNKN, ft_strlen(ERR_MSG_UNKN), 0);
}
