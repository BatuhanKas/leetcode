/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hamming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 22:23:42 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/27 22:34:06 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int compute(const char *lhs, const char *rhs)
{
    int i = 0;
    int diff = 0;
    
    printf("lhs : %s\n", lhs);
    printf("rhs : %s\n", rhs);
    if (!lhs || !rhs) {
        perror("error");
        return -1;
    }
    if (strlen(lhs) != strlen(rhs)) {
        perror("wrong length !");
        return -1;
    }
    while (lhs[i] && rhs[i] && lhs && rhs)
    {
        if (lhs[i] != rhs[i]) {
            diff++;
        }
        i++;
    }
    return diff;
}

int main () {
    char lhs[] = "GAGCCTACTAACGGGAT";
    char rhs[] = "CATCGTAATGACGGCCT";
    printf("Hms : %d", compute(lhs, rhs));
}