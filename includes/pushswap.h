/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moni <moni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:13:16 by moni              #+#    #+#             */
/*   Updated: 2024/09/21 20:30:22 by moni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_price	*struct_price;
	int				stage_a;
	int				stage_b;
	int				min_index;
	int				max_index;
	int				index;
	int				min;
	int				max;
}				t_stack;

typedef struct s_info
{
	int				size;
	int				move;
}				t_info;

typedef struct s_price
{
	int				price;
	int				a_price;
	int				b_price;
}				t_price;

//	FUN
//	FUN > PUSH
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **a, t_stack **b, t_info *info);
void	pb(t_stack **a, t_stack **b, t_info *info);

//	FUN > SWAP
void	swap(t_stack **stack);
void	sa(t_stack **stack_a, t_info *info);
void	sb(t_stack **stack_b, t_info *info);
void	ss(t_stack **stack_a, t_stack **stack_b, t_info *info);

//	FUN > ROTATE
void	rotate(t_stack **stack);
void	rb(t_stack **stack_b, t_info *info);
void	ra(t_stack **stack_a, t_info *info);
void	rr(t_stack **stack_a, t_stack **stack_b, t_info *info);

//	FUN > REVERSE ROTATE
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a, t_info *info);
void	rrb(t_stack **stack_b, t_info *info);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_info *info);

// SORT
// SORT > SORT 3
void	sort_3(t_stack **a, t_stack **b, t_info *info);

// SORT > SORT 4
void	sort_4(t_stack **a, t_stack **b, t_info *info);
void	sort_5(t_stack **a, t_stack **b, t_info *info);

// SORT > SORT
void	sort_2(t_stack **a, t_info *info);
void	choose_sort(t_stack **a, t_stack **b, t_info *info);
void	sort_100_500(t_stack **a, t_stack **b, t_info *info);

// SORT > UTILS SORT
bool	is_sorted(t_stack *a);
int		find_min(t_stack *stack);
int		find_max(t_stack *stack);
int		find_max_index(t_stack *stack);
int		find_min_index(t_stack *stack);
// int		stack_size(t_stack **stack);

// SORT > SORT 100 500
void	calculate_price(t_stack *a, t_stack *b, t_info *info);
t_price	*find_best_price(t_stack *a);

// STACK
// STACK > CREATE STACK
t_stack	*new_node(char *av, t_info *info);
void	push_back(t_stack **stack_a, t_stack *new);
void	create_stack(t_stack **stack_a, t_stack **stack_b,
			t_info **info, char **av);

// STACK > PRINT STACK
void	print_stack(t_stack *stack_a, t_stack *stack_b, t_info *info);
// void	print_move_and_size(t_stack *stack_a, t_stack *stack_b, 
	// t_info *info);

// STACK > UTILS STACK
int		get_stack_size(t_stack *stack);
int		find_index(int *sorted_arr, int size, int value);
void	sort_array(int *arr, int size);
// void	replace_with_indices(t_stack **stack_a);
bool	is_sorted(t_stack *a);
void	rotate_stack(t_stack **a, t_stack **b, t_info *info, t_price *cheapest);

// MEMORY MANAGEMENT
void	free_stack(t_stack *stack);
void	initialize_struct_price(t_stack *stack);

// CHECKERS
bool	checks_are_ok(char *av);
bool	is_int(long number);
int		count_len_word(const char *s, char c, int i);
int		count_words(const char *s, char c);


// SPLIT
char	*clean_whitespace(const char *s);
char	**split(const char *s, char c);

#endif
