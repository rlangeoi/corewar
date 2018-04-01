/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:08:13 by                   #+#    #+#             */
/*   Updated: 2018/04/01 18:53:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	print_usage(void)
{
	ft_printf("Usage : ./corewar [-a] [-v (verbose_level)]\n");
	exit(EXIT_FAILURE);
}

void	exit_error(char *error, char *file)
{
	if (file == NULL && error != NULL)
		ft_printf("%s\n", error);
	else if (file != NULL && error != NULL)
		ft_printf("%s%s\n", error, file);
	else if (file == NULL && error == NULL)
		ft_printf("Unknown error, exiting");
	exit(EXIT_FAILURE);
}
