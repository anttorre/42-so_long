/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anttorre <atormora@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:34:15 by anttorre          #+#    #+#             */
/*   Updated: 2023/06/06 17:57:19 by anttorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief 
 * mientras que lst no sea NULL modificamos el contenido con la funcion
 * creamos un nuevo nodo que se sobreescribira con cada iteracion del bucle,
 * si no se genera el nodo se limpia la lista y se borra el contenido
 * del nodo modificado con la funcion del si no se añade al final de la lista y
 * cambiamos el primer nodo de la lst al siguiente para ir avanzando.
 * 
 * @param lst t_list * | puntero a la lista
 * @param f void | puntero a una funcion que modifica el content
 * @param del void | puntero a una funcion que elimina
 * @return t_list*  | la nueva lista modificada
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	void	*content;
	t_list	*new_node;

	new_lst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
