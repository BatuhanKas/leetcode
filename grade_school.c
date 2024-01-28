/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_school.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: batuhan <batuhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:20:21 by batuhan           #+#    #+#             */
/*   Updated: 2024/01/29 00:32:16 by batuhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

void    adding_to_grade(char *str, int grade) 
{
    roster_t roster;
    student_t student;
    int k = 1;

    if (k == 1) {
        roster.count = 0;
        k = 0;   
    }
    student.grade = grade;
    strcpy(student.name, str);
    roster.students[roster.count] = student;
    printf("%s ", roster.students[roster.count].name);
    printf("%d\n", roster.students[roster.count].grade);
    roster.count++;
}

int main () {
    adding_to_grade("ali", 1);
    adding_to_grade("veli", 2);
}
