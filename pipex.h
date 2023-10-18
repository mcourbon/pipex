/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:12:07 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/04 14:15:54 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

typedef enum e_errors
{
	PIPE,
	CONDITIONS,
	FORK,
	OPEN,
	DUP,
	CLOSE,
	SPLIT,
	CMD,
	EXEC,
	CLOSE_P0,
	CLOSE_P1,
	JOIN,
	WAIT,
}	t_errors;

void	errors(t_errors error, char *cmd);
char	*cmd_build(char *str, char **env);
int		child(int outin[2], char **av, char **env);
int		parent(int outin[2], char **av, char **env);
int		exec_child(int outin[2], char **av, char **env);
int		exec_parent(int outin[2], char **av, char **env);

void	free_all(char **splitted);
int		close_pipe(int outin[2]);
int		ft_in(const char c, const char *src);

void	ft_putendl(char *str);
void	ft_putendl_fd(int fd, char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

#endif