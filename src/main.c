/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsito <tsito@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 19:37:22 by tsito             #+#    #+#             */
/*   Updated: 2026/05/08 20:33:09 by tsito            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av) {
    char **args;

    if (ac <2)
        return 0;
    args = join_and_split(ac, av);
    while (*args != NULL) {
        printf("%s\n", *args);
        args++;
    }
    return 0;
}
