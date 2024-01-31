/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daily_temperatures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:32:36 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/31 14:29:45 by batuhan          ###   ########.fr       */
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
    int i = 0;
    int count = 1;
    int *arr = (int *)malloc(sizeof(int) * temperaturesSize);

    while (temperatures[i]) {
        int j = i + 1;
        if (temperatures[i] < temperatures[j] && temperatures[j]) {
            arr[i] = count;
        } else {
            while (temperatures[i] > temperatures[j] && temperatures[j] && temperatures[i]) {
                j++;
                count++;
                if (temperatures[i] < temperatures[j] && temperatures[j]) {
                    arr[i] = count;
                }
            }
        }
        if (temperatures[j] == '\0') {
            arr[i] = 0;
        }
        i++;
        count = 1;
    }
    // *returnSize = i;
    arr[i + 1] = '\0';
    return arr;
}

int main () {
    int x[] = {30, 60, 90};
    int *a = dailyTemperatures(x, 3, NULL);
    for (int i = 0; a[i]; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
}