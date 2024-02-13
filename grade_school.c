/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grade_school.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:20:21 by batuhan           #+#    #+#             */
/*   Updated: 2024/02/01 14:24:14 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

void    init_roster(roster_t *roster)
{
    roster->count = 0;
}

bool add_student(roster_t *roster, char *name, int grade)
{
    (void)roster;
    (void)name;
    (void)grade;
    return true;
}
/**
 * @brief Get the grade object
 * 
void    init_roster(roster_t *roster);
bool    add_student(roster_t *roster, char *name, int grade);
roster_t get_grade(roster_t *roster, int desired_grade);

init etmeyi unutma
 * 
 * @param roster 
 * @param desired_grade 
 * @return roster_t 
 */

roster_t get_grade(roster_t *roster, int desired_grade)
{
    (void)desired_grade;
    return *roster;
}

/*
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
}*/

int main () {
    adding_to_grade("ali", 1);
    adding_to_grade("veli", 2);
}
