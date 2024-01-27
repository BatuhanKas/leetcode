/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gr2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 23:49:26 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/27 23:50:09 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>

uint64_t total(void) {
    uint64_t sqr = 1;
    uint64_t sum = 0;
    uint64_t tmp = 1;
    uint64_t len = 0;

    while (sqr <= 64) {
        len = sqr - 1;
        while (len) {
            tmp = 2 * tmp;
            len--;
        }
        sum += tmp;
        printf("sum : %ld\n", sum);
        sqr++;
        tmp = 1;
    }

    printf("sum : %ld\n", sum);
    return sum;
}

int main() {
    printf("total : %ld", total());
}