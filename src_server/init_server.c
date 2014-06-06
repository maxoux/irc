/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 16:43:26 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/22 03:59:41 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_server.h"

int	init_server(void)
{
	int					sock;
	struct protoent		*protocol;
	struct sockaddr_in	sin;

	protocol = getprotobyname("tcp");
	if (!protocol)
		ft_exit(ERR_PROTO);
	sock = socket(PF_INET, SOCK_STREAM, protocol->p_proto);
	if (sock == -1)
		ft_exit(ERR_SOCK);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port());
	sin.sin_addr.s_addr = INADDR_ANY;
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		ft_exit(ERR_BIND);
	listen(sock, MAX_USERS);
	return (sock);
}
