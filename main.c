/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinzhang <xinzhang@student.42Paris.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:45:59 by xinzhang          #+#    #+#             */
/*   Updated: 2025/04/24 17:12:26 by xinzhang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include "../libft/libft.h"

t_stack	*init_stack(char **data, int size, int sign, int nd_free)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = create_stack(size);
	if (sign == 1)
	{
		while (i < size)
		{
			stack->data[i] = ft_atoi(data[i]);
			i++;
		}
		if (nd_free == 2)
			free_split(data, size);
	}
	else
		stack->size = 0;
	return (stack);
}

void	solutions(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
		swap(a, "sa");
	else if (size == 3)
		sort_3(a);
	else
		push_swap(a, b, size);
}

void	free_stack(t_stack *stack)
{
	free(stack->data);
	free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**data_list;
	int		size;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		size = count_words(argv[1], ' ');
		data_list = ft_split(argv[1], ' ');
	}
	else
	{
		size = argc - 1;
		data_list = argv + 1;
	}
	verify_input(data_list, size, argc);
	a = init_stack(data_list, size, 1, argc);
	b = init_stack(data_list, size, 0, 0);
	if (is_sorted(a) == 0)
		solutions(a, b, size);
	free_stack(a);
	free_stack(b);
	return (0);
}
