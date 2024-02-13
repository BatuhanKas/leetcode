/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily_temperatures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:32:36 by batuhan           #+#    #+#             */
/*   Updated: 2024/02/01 14:00:26 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * Example 1:

    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

    Example 2:
    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]

    Example 3:    
    Input: temperatures = [30,60,90]
    Output: [1,1,0]

 */

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *arr = (int *)malloc(sizeof(int) * temperaturesSize);
    int count = 1;
    int j;

    for (int i = 0; i < temperaturesSize; i++) {
        for (j = i + 1; j < temperaturesSize && temperatures[i] >= temperatures[j]; j++)
            count++;
        if (j == temperaturesSize)
            arr[i] = 0;
        else
            arr[i] = count;
        count = 1;
    }
    *returnSize = temperaturesSize;
    return arr;
}

int main () {
    int x[] = {73,74,75,71,69,72,76,73};
    int *a = dailyTemperatures(x, 8, NULL);
    for (int i = 0; a[i]; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}