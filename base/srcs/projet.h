/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 19:59:46 by momartin          #+#    #+#             */
/*   Updated: 2017/01/11 19:59:48 by momartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ###PROJET_H
# define ###PROJET_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

# define E t_env *e

typedef struct	s_env
{

}				t_env;

t_env	*init_env(void);
void	destroy_env(E);

#endif
