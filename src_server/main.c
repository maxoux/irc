/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 16:52:33 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:02:10 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int		socket;
	t_who	group[MAX_USERS + 1];

	if (argc != 2)
		ft_usage(argv[0]);
	set_port(ft_atoi(argv[1]));
	socket = init_server();
	init_group(group, socket);
	main_loop(group);
	printf("OK\n");
	return (0);
}
