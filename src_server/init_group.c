/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 23:05:22 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:01:44 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	init_group(t_who *group, int socket_server)
{
	int	i;

	group[0].type = ID_SERVER;
	group[0].fd = socket_server;
	ft_strcpy(group[0].user.color, SYSTEM_COLOR);
	i = 1;
	while (i <= MAX_USERS)
	{
		group[i].type = ID_FREE;
		group[i].fd = -1;
		sprintf(group[i].user.name, "anon_%d", i);
		sprintf(group[i].user.default_name, "anon_%d", i);
		sprintf(group[i].user.channel, DEFAULT_CHANNEL);
		ft_strcpy(group[i].user.color, DEFAULT_COLOR);
		i++;
	}
}
