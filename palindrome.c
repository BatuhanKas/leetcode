/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palindrome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:02:21 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/25 20:02:21 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool isPalindrome(int x) {
	int nbr = x;
	if (x < 0)
		return false;
	long long int reverse = 0;
	while (x > 0) {
	reverse = reverse * 10 + x % 10;
	x = x / 10;
	} if (reverse == nbr)
		return true;
	return false;
}
