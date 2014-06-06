/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaize <mlaize@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/04 17:04:52 by mlaize            #+#    #+#             */
/*   Updated: 2013/12/04 18:29:26 by mlaize           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchri(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i] != c)
	{
		if (!s[i])
			return (-1);
		i++;
	}
	return (i);
}
