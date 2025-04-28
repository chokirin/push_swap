/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:35:34 by xinzhang          #+#    #+#             */
/*   Updated: 2025/04/25 19:35:38 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_stack
{
	int	*data;
	int	size;
}				t_stack;

t_stack	*create_stack(int size);
void	free_stack(t_stack *stack);
void	push(t_stack *from, t_stack *to, char *msg);
void	swap(t_stack *stack, char *msg);
void	rotate_up(t_stack *stack, char *msg);
void	rotate_down(t_stack *stack, char *msg);
void	rotate_both(t_stack *a, t_stack *b, int direc);
void	verify_input(char **data_list, int size, int nd_free);
void	sort_3(t_stack *stack);
void	push_swap(t_stack *a, t_stack *b, int size);
void	rotate_each(t_stack *a, t_stack *b, int ra, int rb);
void	min_to_top(t_stack *stack);
int		is_sorted(t_stack *stack);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_median(t_stack *stack, int candidat);
int		get_index(t_stack *stack, int num);
int		min_rotation(int index, int size);
int		ft_abs(int num);
void	solutions(t_stack *a, t_stack *b, int size);
t_stack	*init_stack(char **data, int size, int sign, int nd_free);
int		best_index(t_stack *a, t_stack *b);

#endif
