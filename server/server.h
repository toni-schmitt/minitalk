/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:00:20 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/28 21:47:36 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "libft.h"
# include <signal.h>

# ifndef SIG_STOP
#  define SIG_STOP 255
# endif

typedef struct s_message
{
	unsigned char	c;
	int				mask;
	int				byte_count;
}	t_message;

#endif