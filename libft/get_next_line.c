/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboujna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 08:26:21 by kaboujna          #+#    #+#             */
/*   Updated: 2018/11/26 15:48:23 by kaboujna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*get_fd(const int fd, t_fd **m)
{
	t_fd	*new_f;

	new_f = *m;
	while (new_f)
	{
		if (fd == new_f->fd)
			return (new_f);
		new_f = new_f->next;
	}
	new_f = (t_fd*)malloc(sizeof(t_fd));
	if (!new_f)
		return (NULL);
	new_f->s = ft_strnew(0);
	new_f->fd = fd;
	new_f->next = *m;
	new_f->prev = NULL;
	if ((*m))
		(*m)->prev = new_f;
	new_f->ret = 0;
	return ((*m) = new_f);
}

void	set_up_line(char **line, t_fd *m)
{
	int	i;

	i = 0;
	while (m->s[i] && m->s[i] != '\n')
		i++;
	(*line) = ft_strsub(m->s, 0, i);
	m->tmp = m->s;
	if (m->s[i] == '\n')
		m->s = ft_strdup(m->s + i + 1);
	else
		m->s = ft_strnew(0);
	free(m->tmp);
}

int		ft_verif(t_fd *m, int rd, char **line, t_fd *first_fd)
{
	if (!*(m->s) && !rd)
	{
		if (m->prev)
		{
			m->prev->next = m->next;
			free((void*)m);
		}
		else
			first_fd = first_fd->next;
		m->ret = 0;
	}
	else
		set_up_line(line, m);
	return (m->ret > 0 ? 1 : 0);
}

int		get_next_line(const int fd, char **line)
{
	static t_fd		*first_fd = NULL;
	t_fd			*m;
	char			buf[BUFF_SIZE + 1];
	int				rd;

	m = NULL;
	if ((fd < 0 || !line) || (!(m = get_fd(fd, &first_fd))))
		return (-1);
	rd = 0;
	while ((!ft_strchr(m->s, '\n')) && (rd = read(fd, buf, BUFF_SIZE)))
	{
		if (rd == -1)
		{
			free(m->s);
			return (-1);
		}
		buf[rd] = '\0';
		m->ret = rd;
		if (!(m->s = ft_strjoin_free(m->s, ft_strdup(buf))))
			return (-1);
	}
	return (ft_verif(m, rd, line, first_fd));
}
