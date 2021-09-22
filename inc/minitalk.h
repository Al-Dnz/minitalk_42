/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenhez <adenhez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:59:26 by adenhez           #+#    #+#             */
/*   Updated: 2021/09/22 14:44:52 by adenhez          ###   ########.fr       */
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

# define DELAY 700
# define BIT_DIMENSION 15

typedef struct s_state
{
	int		c;
	int		head_bit;
	bool	releasable_char;
}				t_state;

t_state	g_state = {'\0', 1 << BIT_DIMENSION, false};

#endif
