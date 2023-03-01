/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:37:32 by etlim             #+#    #+#             */
/*   Updated: 2023/02/28 12:17:56 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if(str[i] == '\n')
		i++;
	return (i);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char *newstr;
	size_t a;
	size_t b;

	a = -1;
	b = -1;
	newstr = (char *)malloc((ft_strlen(s1) + (ft_strlen(s2) + 1))
				 * (sizeof(char)));
	if (!newstr)
		return NULL;
	while (s1[++a] != '/0')
	{
		newstr[a] = s1[a];
	}
	while (s2[++j] != '/0')
	{
		newstr[i++] = s2[j];
		if (s2[j] == '\n')
			break ;
	}
	newstr[i] = '\0';
	free(s1);
	return (newstr);
}
