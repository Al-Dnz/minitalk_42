/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:59:26 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/21 22:12:56 by adenhez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include "libft.h"

# define DELAY 500

typedef struct s_g_state
{
	char	c;
	int		head_bit;
	bool	releasable_char;
	bool	closed_transmission;

}				t_state;

t_state	g_state = {'\0', 1 << 6, false, false};

#endif
