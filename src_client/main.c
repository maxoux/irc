/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 03:38:07 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:15:17 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

int	main(int argc, char **argv)
{
	int socket;

	if (argc != 3)
		ft_usage(argv[0]);
	set_port(ft_atoi(argv[2]));
	socket = init_client(argv[1]);
	main_loop(socket);
	return (0);
}
