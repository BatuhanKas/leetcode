/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:03:43 by bkas              #+#    #+#             */
/*   Updated: 2024/02/13 10:42:12 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    ft_a(char *str)
{
    printf("yeni str : %s\n", str);
}

void	ft_ult(char **str)
{
    str[0] = strdup("ali");
    str[1] = strdup("batu");

    // printf("*str : %s\n", *str);
    // str++;
    printf("*str : %s\n", *str);
    ft_a(str[0]);
    ft_a(str[1]);
}

int main ()
{
    char *s = 0;
    ft_ult(&s);
}
