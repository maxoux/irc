/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 23:38:17 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:06:26 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

void	select_update(int nb_cmd, t_who *group, fd_set *listener)
{
	int	i;

	i = 0;
	while (nb_cmd)
	{
		while (i <= MAX_USERS)
		{
			if (group[i].type != ID_FREE && FD_ISSET(group[i].fd, listener))
			{
				if (group[i].type == ID_SERVER)
					open_connection(group);
				else if (group[i].type == ID_USER)
					user_receive(group, &(group[i]));
				FD_CLR(group[i].fd, listener);
			}
			i++;
		}
		nb_cmd--;
	}
}
