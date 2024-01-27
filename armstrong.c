/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   armstrong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:26:00 by bkas              #+#    #+#             */
/*   Updated: 2024/01/27 21:14:38 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

bool is_armstrong_number(int candidate) {
    int len = 0;
    int candy = candidate;
    int sugar = candidate;
    int num = 1;
    int total = 0;

    while (candy) {
        candy /= 10;
        len++;
    }
    printf("len : %d\n", len);
    while (sugar) {
        int x = len;
        int mod = sugar % 10;
        while (x) {
            num *= mod;
            printf("num : %d\n", num);
            x--;
        }
        total += num;
        num = 1;
        printf("total : %d\n", total);
        sugar /= 10;
    }
    if (total == candidate)
        return true;
    return false;
}

int main () {
    int x = 153;
    printf("%d", is_armstrong_number(153));
}
