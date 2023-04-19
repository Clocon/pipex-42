/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:27:02 by lumorale          #+#    #+#             */
/*   Updated: 2023/04/19 11:31:37 by lumorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

static void	sub_dup2(int zero, int one)
{
	dup2(zero, 0);
	dup2(one, 1);
}

static void	check_awk(t_pipex *pipex)
{
	if (ft_strncmp(pipex->args[0], "awk", 3) == 0)
	{	
		if (pipex->args[1][0] == '\'')
			pipex->args[1] = ft_strtrim(pipex->args[1], "'");
		else if (pipex->args[1][0] == '"')
			pipex->args[1] = ft_strtrim(pipex->args[1], "\"");
	}
}

void	child(t_pipex pipex, char **str, char **envp, int i)
{
	pipex.pid1 = fork();
	if (!pipex.pid1)
	{
		if (i == 0)
			sub_dup2(pipex.fd_in, pipex.tube[i][1]);
		else if (i == pipex.n_pipes - 1)
			sub_dup2(pipex.tube[i - 1][0], pipex.fd_out);
		else
			sub_dup2(pipex.tube[i - 1][0], pipex.tube[i][1]);
		close_pipes(&pipex);
		pipex.args = split_args(str[i + 2], ' ');
		pipex.cmd = get_cmd(pipex.paths, pipex.args[0]);
		if (!pipex.cmd)
		{
			free_matrix(pipex.args);
			free(pipex.cmd);
			err_msg(CMD2_ERROR);
			exit(1);
		}
		check_awk(&pipex);
		execve(pipex.cmd, pipex.args, envp);
	}
}
