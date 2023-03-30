/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:27:02 by lumorale          #+#    #+#             */
/*   Updated: 2023/03/30 17:43:38 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, X_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **str, char **envp)
{
	if (pipex.fd_in < 0)
		exit(1);
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.fd_in, 0);
	pipex.args = split_args(str[2], ' ');
	pipex.cmd = get_cmd(pipex.paths, pipex.args[0]);
	if (!pipex.cmd)
	{
		free_matrix(pipex.args);
		free(pipex.cmd);
		err_msg_exit(CMD1_ERROR);
	}
	if (ft_strncmp(pipex.args[0], "awk", 3) == 0)
	{		
		if (pipex.args[1][0] == '\'')
			pipex.args[1] = ft_strtrim(pipex.args[1], "'");
		else if (pipex.args[1][0] == '"')
			pipex.args[1] = ft_strtrim(pipex.args[1], "\"");
	}
	execve(pipex.cmd, pipex.args, envp);
}

void	second_child(t_pipex pipex, char **str, char **envp)
{
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.fd_out, 1);
	pipex.args = split_args(str[3], ' ');
	pipex.cmd = get_cmd(pipex.paths, pipex.args[0]);
	if (!pipex.cmd)
	{
		free_matrix(pipex.args);
		free(pipex.cmd);
		err_msg(CMD2_ERROR);
		exit(127);
	}
	if (ft_strncmp(pipex.args[0], "awk", 3) == 0)
	{		
		if (pipex.args[1][0] == '\'')
			pipex.args[1] = ft_strtrim(pipex.args[1], "'");
		else if (pipex.args[1][0] == '"')
			pipex.args[1] = ft_strtrim(pipex.args[1], "\"");
	}
	execve(pipex.cmd, pipex.args, envp);
}
