/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:19:07 by zsyyida           #+#    #+#             */
/*   Updated: 2023/03/04 16:19:11 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/include/libft.h"
// for printf
#include <stdio.h>
// for malloc
#include <stdlib.h>
// for prompt
#include <readline/readline.h>
// for history
#include <readline/history.h>
// for read , write
#include <unistd.h>
// for open, close
#include <fcntl.h>
// for error
#include <errno.h>
// for wait amd waitpid
#include <sys/wait.h>

// Parsed command representation
#define EXEC  1
#define REDIR 2
#define PIPE  3
#define LIST  4
#define BACK  5
#define HERE_DOC 6
#define ENV 7

typedef struct s_cmd
{
	int		type;
	char	*full_string;
	char	*path;
	char	*cmd;
	char	*file_in;
	char	*file_out;
	int		fd_in;
	int		fd_out;
	char	*here_doc_delimiter;
	int		here_doc_flag;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

int	main(int ac, char **argv, char **envp);
t_cmd	*ft_lstnew_ms(void *cmd, int type);

#endif