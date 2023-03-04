/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:23:46 by zsyyida           #+#    #+#             */
/*   Updated: 2023/03/04 18:54:18 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int ac, char**av, char **env)
{
	char	*s;

	(void)ac;
	(void)av;
	(void)env;
	s = readline("ruhan_zahra_shell % ");
	while (s != NULL)
	{
		s = readline("ruhan_zahra_shell % ");
		add_history (s);
		printf("%s\n", s);
		if (ft_strncmp(s, "exit", 5) == 0)
		{
			free(s);
			exit(0);
		// if (ft_strncmp(s, "env", 4) == 0)
		// 	ft_env(s, env);
		// if (ft_strncmp(s, "<<", 3) == 0)
		// 	ft_here_doc(s);
	}
}
