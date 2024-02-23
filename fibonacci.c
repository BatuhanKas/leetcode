/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fibonacci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:57:39 by bkas              #+#    #+#             */
/*   Updated: 2024/02/23 18:12:55 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main () {
    int firstval = 0;
    int secval = 1;
    int tmp;
    int sum = 0;
    while (1) {
        tmp = firstval;
        firstval = secval;
        secval = tmp;
        secval += firstval;
    }
}