/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isogram.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:24:45 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/27 22:12:27 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>

/**
 * @brief 
 * 
 * Examples of isograms:

 *   lumberjacks
 *   background
 *   downstream
 *   six-year-old
 * 
 * @param phrase 
 * @return true 
 * @return false 
 */

bool is_isogram(const char phrase[])
{
    int i = 0;
    int x = 0;
    char a = 0;
    char b = 0;

    // printf("phrase : %s\n", phrase);
    if (!phrase) {
        return false;
    }
    while (phrase[i]) {
        while (phrase[i] == 32 || phrase[i] == '-')
            i++;
        a = phrase[i];
        if (a >= 'a' && a <= 'z') {
            b = a - 32;
        } else if (a >= 'A' && a <= 'Z') {
            b = a + 32;
        }
        x = i + 1;
        while (phrase[x] != a && phrase[x] != b && phrase[x]) {
            // printf("char a : %c\n", a);
            // printf("char ph : %c\n", phrase[x]);
            x++;
        }
        if (phrase[x] == a || phrase[x] == b) {
            return false;
        }
        i++;
    }
    return true;
}

int main () {
    char x[] = "Alphabet";
    printf("is iso : %d\n", is_isogram(x));
}
