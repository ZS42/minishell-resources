/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:12:09 by zsyyida           #+#    #+#             */
/*   Updated: 2023/03/04 16:20:05 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*ft_lstnew_ms(void *cmd, int type)
{
	t_cmd	*new;

	new = ft_calloc(1, sizeof(t_list));
	if (new == NULL)
		return (0);
	new -> type = type;
	new -> full_string = NULL;
	new -> path = NULL;
	new -> cmd = cmd;
	new -> file_in = NULL;
	new -> file_out = NULL;
	new -> fd_in = 0;
	new -> fd_out = 1;
	new -> here_doc_delimiter = NULL;
	new -> here_doc_flag = 0;
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}
