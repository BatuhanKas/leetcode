/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   armstrong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 18:26:00 by bkas              #+#    #+#             */
/*   Updated: 2024/01/27 18:31:15 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

bool is_armstrong_number(int candidate) {
    int len = 0;
    int candy = candidate;
    int sugar = candidate;
    int num = 0;

    while (candy) {
        candy /= 10;
        len++;
    }
    while (sugar) {
        num += (sugar % 10) * len;
        sugar /= 10;
    }
    if (num == candidate)
        return true;
    return false;
}

int main () {
    int x = 153;
    printf("%d", is_armstrong_number(153));
}