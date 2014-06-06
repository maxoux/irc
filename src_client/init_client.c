/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 03:40:36 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:15:08 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "irc_client.h"

int	init_client(char *addr)
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
	sin.sin_addr.s_addr = (ft_strequ(addr, "localhost")) ?
		inet_addr("127.0.0.1") : inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		ft_exit(ERR_CONNECT);
	return (sock);
}
