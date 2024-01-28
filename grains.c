/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:48:28 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/28 16:52:28 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>

uint64_t total(void) {
    uint64_t i = 0;
    uint64_t j = 0;
    uint64_t sum = 0;
    uint64_t tmp = 1;
    uint64_t sqr = 0;
    uint64_t len = 0;

    while (i <= 8) {
        while (j <= 8) {
            len = sqr;
            while (len) {
                tmp = 2 * tmp;
                len--;
            }
            if (sqr <= 64) {
                sum += tmp;
                printf("sum : %ld\n", sum);
                sqr++;
                tmp = 1;
                j++;
            } else {
                break;
            }
        }
        if (sqr <= 64) {
            i++;
            j = 0;
        } else {
            break;
        }
    }
    printf("sum : %ld\n", sum);
    return sum;
}

uint64_t square(uint8_t index) {
    
}

int main() {
    printf("total : %ld", total());
    printf("square : %ld", square(31));
}