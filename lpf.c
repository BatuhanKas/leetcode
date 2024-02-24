/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:49:24 by bkas              #+#    #+#             */
/*   Updated: 2024/02/24 17:21:44 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 600851475143 en büyük asal carpanini bulacağım sayi

/**
 * 
 * @file lpf.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-24
 * 
 * @copyright Copyright (c) 2024
 * 
 * 
 * Bir sayı 1'e ve kendisine bölünebiliyorsa asal sayıdır.
 * 
 */

#include <stdio.h>

long int is_prime(long int x) {
    long int i = 2;
    while (i < x) {
        while (x % i == 0)
            x = x / i;
        if (x != 1)
            i++;
    }
    return i;
}

int main () {
    long a = 0;
    a = is_prime(600851475143);
    printf("a val : %ld\n", a);
}
