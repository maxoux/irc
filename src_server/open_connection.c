/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_connection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 23:53:56 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:06:02 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	open_connection(t_who *group)
{
	int					cs;
	struct sockaddr_in	csin;
	socklen_t			csin_len;
	int					i;

	i = 0;
	while (i <= MAX_USERS && group[i].type != ID_FREE)
		i++;
	if (i > MAX_USERS)
	{
		close(accept(group[0].fd, NULL, NULL));
		return ((void)printf("Warning : Maximum user reached !\n"));
	}
	csin_len = sizeof(csin);
	cs = accept(group[0].fd, (struct sockaddr*)&csin, &csin_len);
	printf("New client #%d named %s from %s:%d\n", cs, group[i].user.name,
	inet_ntoa(csin.sin_addr), ntohs(csin.sin_port));
	group[i].type = ID_USER;
	group[i].fd = cs;
	ft_strcpy(group[i].user.color, DEFAULT_COLOR);
	ft_bzero(group[i].buffer, BUF_SIZE);
}
