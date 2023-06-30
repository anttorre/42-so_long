/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:08:34 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 17:50:30 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * reservamos memoria del tamaño de la estructura
 * ponemos el contenido del nodo con el content y el siguiente nodo
 * a NULL y devolvemos el puntero a la lista
 * 
 * @param content void * | puntero generico para almacenar cualquier dato
 * @return t_list* | puntero a la lista
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
