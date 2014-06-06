/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 07:41:20 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 18:44:08 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

static t_command	g_ope[] =
{
	{CMD_NICK, &cmd_change_nick},
	{CMD_JOIN, &cmd_change_channel},
	{CMD_WHO, &cmd_who_channel},
	{CMD_PM, &cmd_send_message},
	{NULL, NULL}
};

void	user_command(t_who *group, t_who *user)
{
	int i;

	i = 0;
	*(ft_strchr(user->buffer, '\n')) = 0;
	while (g_ope[i].name)
	{
		if (ft_strnequ(g_ope[i].name, user->buffer, ft_strlen(g_ope[i].name)))
			g_ope[i].f(group, user);
		i++;
	}
}
