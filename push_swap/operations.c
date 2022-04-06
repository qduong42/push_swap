/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qduong <qduong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:35:15 by qduong            #+#    #+#             */
/*   Updated: 2022/04/06 13:37:59 by qduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// if ((*stacka)->next->next) denotes more than 2 numbers -> argc = 3;

void	swap(pst_list **stack, char i)
{
	pst_list	*temp;

	if ((*stack)-> next == 0 || !stack)
		return ;
	temp = (*stack)->next;
	if ((*stack)->next->next)
		(*stack)->next = (*stack)->next->next;
	else
		(*stack)->next = NULL;
	(*stack)->previous = temp;
	temp->next = (*stack);
	temp->previous = NULL;
	(*stack) = temp;
	if (i == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

//sets temp as top of stack

void	rotate(pst_list **stack, char i)
{
	pst_list	*last;
	pst_list	*temp;

	temp = (*stack);
	last = ft_lstlast(*stack);
	(*stack)->next->previous = NULL;
	(*stack) = (*stack)->next;
	last->next = temp;
	temp->previous = last;
	temp->next = NULL;
	if (i == 'a')
		write(1, "ra\n", 3);
	else if (i == 'b')
		write(1, "rb\n", 3);
	else
		return ;
}

void	r_rotate(pst_list **stack, char i)
{
	pst_list	*last;
	pst_list	*temp;

	temp = (*stack);
	last = ft_lstlast(*stack);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = (*stack);
	(*stack)->previous = last;
	(*stack) = last;
	if (i == 'a')
		write(1, "rra\n", 4);
	else if (i == 'b')
		write(1, "rrb\n", 4);
	else
		return ;
}

int	push(pst_list **stacka, pst_list **stackb, char a)
{
	int	i;

	i = ft_lstsize(*stackb);
	if (i == 0)
	{
		(*stacka) = (*stacka)->next;
		*stackb = (*stacka)->previous;
		(*stacka)->previous = NULL;
		(*stackb)->previous = NULL;
		(*stackb)->next = NULL;
	}
	else
	{
		(*stacka) = (*stacka)->next;
		(*stackb)->previous = (*stacka)->previous;
		(*stacka)->previous->next = (*stackb);
		(*stacka)->previous = NULL;
		(*stackb) = (*stackb)->previous;
	}
	if (a == 'a')
		write(1, "pa\n", 3);
	else if (a == 'b')
		write(1, "pb\n", 3);
	return (1);
}
