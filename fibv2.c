/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:18:45 by bkas              #+#    #+#             */
/*   Updated: 2024/02/23 22:03:27 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main () {
    int firstval = 0;
    int secval = 1;
    int tmp = 0;
    int sum = 0;
    while (1) {
        sum = secval + firstval;
        if (sum > 4000000)
            break ;
        if (sum % 2 == 0)
            tmp += sum;
        printf("sum : %d\n", sum);
        printf("tmp : %d\n", tmp);
        firstval = secval;
        secval = sum;
    }
}