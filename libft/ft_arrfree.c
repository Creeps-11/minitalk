/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wskrzyni <wskrzyni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:31:05 by wskrzyni          #+#    #+#             */
/*   Updated: 2025/03/04 18:13:21 by wskrzyni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrfree(void **s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != NULL)
		{
			if (s[i])
				free(s[i]);
			i++;
		}
	}
	free(s);
}
