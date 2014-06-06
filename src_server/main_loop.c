/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 23:18:36 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:05:57 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	main_loop(t_who *group)
{
	fd_set			listener;
	int				i;
	int				nb_event;
	struct timeval	timer;

	printf("Server launched !\n");
	while (42)
	{
		i = 0;
		FD_ZERO(&listener);
		while (i <= MAX_USERS)
		{
			if (group[i].type != ID_FREE)
				FD_SET(group[i].fd, &listener);
			i++;
		}
		nb_event = select(max_fd(group) + 1, &listener, NULL, NULL, &timer);
		if (nb_event == -1)
			ft_exit("error on select command");
		else if (nb_event > 0)
			select_update(nb_event, group, &listener);
	}
}
