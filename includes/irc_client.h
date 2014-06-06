/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc_client.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/22 03:43:46 by mlaize            #+#    #+#             */
/*   Updated: 2014/05/23 19:17:31 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_CLIENT_H
# define IRC_CLIENT_H

# include <netdb.h>
# include <arpa/inet.h>
# include <stdio.h>
# include "libft.h"

# define BUF_SIZE 2048

# define ERR_PROTO	"Unable to get prototype"
# define ERR_SOCK	"Unable to create socket"
# define ERR_CONNECT	"Unable to connect to server"
# define ERR_SELECT "Error on select function"

int		init_client(char *addr);
void	main_loop(int socket);

void	ft_usage(char *name);
void	ft_exit(char *str);
int		port(void);
void	set_port(int port);

#endif