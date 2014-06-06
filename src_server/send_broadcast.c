/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_broadcast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 00:13:15 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:11:59 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	send_broadcast(t_who *group, char *msg)
{
	int		i;
	int		len;
	char	buffer[BUF_SIZE + 42];

	i = 0;
	if (!msg)
		return ;
	ft_bzero(buffer, BUF_SIZE + 42);
	sprintf(buffer, "%s%s%s\n", SYSTEM_COLOR, msg, DEFAULT_COLOR);
	len = ft_strlen(buffer);
	while (i <= MAX_USERS)
	{
		if (group[i].type == ID_USER)
			send(group[i].fd, buffer, len, 0);
		i++;
	}
}
