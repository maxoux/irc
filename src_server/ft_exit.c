/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 19:50:19 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:01:40 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

int		max_fd(t_who *group)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (i <= MAX_USERS)
	{
		if (group[i].type != ID_FREE)
			max = MAX(max, group[i].fd);
		i++;
	}
	return (max);
}

void	ft_usage(char *name)
{
	printf("%s: port <port>\n", name);
	ft_exit(NULL);
}

void	ft_exit(char *str)
{
	if (str)
		printf("Error: %s\n", str);
	_exit(0);
}
