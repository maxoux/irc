/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   irc_server.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 16:52:52 by mlaize            #+#    #+#             */
/*   Updated: 2014/06/06 16:44:06 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRC_SERVER_H
# define IRC_SERVER_H

# include <arpa/inet.h>
# include <netdb.h>
# include <sys/select.h>
# include <stdio.h>
# include "libft.h"

# define MAX_USERS 12
# define BUF_SIZE 2048

# define ID_FREE 0
# define ID_SERVER 1
# define ID_USER 2

# define ERR_PROTO	"Unable to get prototype"
# define ERR_SOCK	"Unable to create socket"
# define ERR_BIND	"Unable to Bind socket with port"

# define ERR_NICK_TOO "Nickname length must be between 1 and 9\n"
# define ERR_NICK_EXIST "Nickname already used\n"
# define ERR_CHAN_TOO "Nickname length must be between 1 and 255\n"
# define ERR_MSG_USAGE "to send a pm: /msg <nick> <message>\n"
# define ERR_MSG_UNKN "User not found\n"

# define CMD_NICK	"/nick"
# define CMD_JOIN	"/join"
# define CMD_WHO	"/who"
# define CMD_PM		"/msg"

# define MSG_USER_JOIN "%s join channel %s !"
# define MSG_USER_LEAVE "%s leave channel %s..."
# define MSG_USER_NICK "%s is now known as %s !"
# define MSG_USER_QUIT "%s as left"
# define MSG_USER_SEND ": "
# define MSG_USER_PM		"#%s -> %s: %s\n"

# define DEFAULT_CHANNEL "Global"
# define DEFAULT_COLOR COLOR_WHITE
# define SYSTEM_COLOR "\033[1;32m"

# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BROWN "\033[0;33m"
# define COLOR_BLUE "\033[0;34m"
# define COLOR_MAGENTA "\033[0;35m"
# define COLOR_CYAN "\033[0;36m"
# define COLOR_WHITE "\033[0;37m"

# define MAX(a,b) (a >= b) ? a : b;

typedef struct	s_user
{
	char		name[10];
	char		channel[255];
	char		default_name[10];
	char		color[12];
}				t_user;

typedef struct	s_who
{
	int			type;
	int			fd;
	char		buffer[BUF_SIZE];
	t_user		user;
}				t_who;

typedef struct	s_command
{
	char		*name;
	void		(*f)(t_who *, t_who *);
}				t_command;

int				init_server(void);
int				port(void);
void			set_port(int port);
void			init_group(t_who *group, int socket_server);
int				max_fd(t_who *group);
void			main_loop(t_who *group);
void			select_update(int nb_cmd, t_who *group, fd_set *listener);
void			open_connection(t_who *group);
void			send_broadcast(t_who *group, char *msg);
void			user_receive(t_who *group, t_who *user);
void			close_connection(t_who *user);
void			send_channel(t_who *group, t_who *user);
void			send_channel_system(t_who *group, char *channel, char *str);
void			user_command(t_who *group, t_who *user);

void			cmd_change_nick(t_who *group, t_who *user);
void			cmd_change_channel(t_who *group, t_who *user);
void			cmd_quit_channel(t_who *group, t_who *user);
void			cmd_who_channel(t_who *group, t_who *user);
void			cmd_send_message(t_who *group, t_who *user);

void			ft_exit(char *str);
void			ft_usage(char *name);

#endif