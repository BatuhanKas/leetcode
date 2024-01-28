/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   difference_of_squares.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:06:29 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/28 18:13:23 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * @brief karelerin toplamı
 * 
 * "(n.(n+1).(2n+1) / 6)" = karelerin toplamı formülü
 * 
 * @param number 
 * @return unsigned int 
 */

unsigned int sum_of_squares(unsigned int number) {
    unsigned int n = number;
    unsigned int total = 0;
    
    total = (n * (n + 1) * (2*n + 1) / 6);
    return total;
}

/**
 * @brief toplamlarının karesi
 * 
 * "n.(n+1) / 2"
 * 
 * @param number 
 * @return unsigned int 
 */
unsigned int square_of_sum(unsigned int number) {
    unsigned int n = number;
    unsigned int total = 0;

    total = ((n * (n + 1)) / 2);
    return total * total;
}

/**
 * @brief ikisinin farkı;
 * 
 * @param number 
 * @return unsigned int 
 */
unsigned int difference_of_squares(unsigned int number) {
    unsigned int n = number;
    unsigned int s2 = 0;
    unsigned int q2 = 0;
    unsigned int diff = 0;

    s2 = ((n * (n + 1)) / 2);
    s2 = s2 * s2;
    
    q2 = (n * (n + 1) * (2*n + 1) / 6);

    diff = s2 - q2;
    return diff;
}


int main () {
    int s2 = square_of_sum(10);
    int q2 = sum_of_squares(10);
    printf("toplamlarinin karesi : %d\n", s2);
    printf("karelerinin toplami : %d\n", q2);
    printf("farklari manuel : %d\n", s2 - q2);
    printf("farklari otomatik : %d\n", difference_of_squares(10));
}