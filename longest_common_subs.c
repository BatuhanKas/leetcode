/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_common_subs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:48:16 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/31 13:13:17 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int longestCommonSubsequence(char *text1, char *text2)
{
    int i = 0;
    int j = 0;
    int len = 0;

    while (text2[j] && text2 && text1 && text1[i]) {
        if (text2[j] == text1[i]) {
            len++;
            j++;
            i = 0;
        }
        i++;
    }
    if (!text2 || !text1)
        return 0;
    return len;
}

int main () {
    char x[] = "abcde";
    char y[] = "ace";
    int a = longestCommonSubsequence(x, y);
    printf("len : %d\n", a);
}
