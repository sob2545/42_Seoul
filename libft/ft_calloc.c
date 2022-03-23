/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sesim <sesim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:29:03 by sesim             #+#    #+#             */
/*   Updated: 2022/03/22 17:25:33 by seongmins        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	allo_size;

	allo_size = count * size;
	ptr = (void *)malloc(sizeof(char) * allo_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, allo_size);
	return (ptr);
}
