/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:03:52 by jopitz            #+#    #+#             */
/*   Updated: 2024/05/03 14:51:19 by jopitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

// Check obvious error and initialise res as empty string
// Data read to buffer and added to res until newline or EOF or error
// if newline, it and everything before added to res and res returned
// if EOF and something in res, res returned otherwise NULL returned
char	*get_next_line(int fd)
{
	char			*res;
	static char		buf[BUFFER_SIZE + 1];
	static size_t	line_start = 0;
	static size_t	line_len = 0;

	if (fd < 0 || BUFFER_SIZE < 1 || !init_res(&res))
		return (NULL);
	while (!line_len)
	{
		if (!line_start && !read_to_buf(fd, &res, buf))
			return (res);
		line_len = find_newline(buf, line_start) - line_start;
		if (line_len > 0)
			return (finish_line(res, buf, &line_start, &line_len));
		else if (!add_buf_to_res(&res, buf, &line_start, &line_len))
			return (NULL);
	}
	return (NULL);
}

// If 0 is returned, nothing was read and res is returned
//		either EOF reached and result is ready or 
//		reading failed and there was an error
// If 1 is returned, data read to buffer and process continue
int	read_to_buf(int fd, char **res, char *buf)
{
	size_t	ret;

	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == 0 && (**res))
		return (0);
	if (ret <= 0)
	{
		free(*res);
		*res = NULL;
		return (0);
	}
	buf[ret] = '\0';
	return (1);
}

//Function called when newline found in buffer,
// we must add last chunk to result and return it
// start set to next character after newline
// len set up to prepare for next gnl call
char	*finish_line(char *res, char *buf, size_t *start, size_t *len)
{
	res = append_line(res, buf, *start, *len);
	*start += *len;
	*len = 0;
	return (res);
}

// function called when no newline found in buffer,
// 	append buffer to result
// returns 0 if malloc fail or error, 
// returns 1 if succes
// line_start and line_len rest in preparation for next buffer read
int	add_buf_to_res(char **res, char *buf, size_t *start, size_t *len)
{
	*res = append_line(*res, buf, *start, BUFFER_SIZE - *start);
	if (!*res)
		return (0);
	*start = 0;
	*len = 0;
	return (1);
}

// Allocates memory for new res,
//  copies old and addiational chars from buff to new memory
// frees memory from old result
char	*append_line(char *old_res, char *buf, size_t start, size_t len)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(sizeof(char)
			* (ft_strlen(old_res) + len + 1));
	if (!res)
	{
		free(old_res);
		return (NULL);
	}
	i = 0;
	while (old_res[i])
	{
		res[i] = old_res[i];
		i++;
	}
	free(old_res);
	res[i + len] = '\0';
	while (len)
	{
		len--;
		res[i + len] = buf[start + len];
	}
	return (res);
}
