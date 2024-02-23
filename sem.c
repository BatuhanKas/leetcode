/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:35:20 by bkas              #+#    #+#             */
/*   Updated: 2024/02/14 11:08:35 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define THREAD_NUM 4

pthread_mutex_t lock;
sem_t semaphore;

void    *routine(void *args) {
    int *s = (int *)args;
    sem_wait(&semaphore);
    printf("sa çet : %d\n", *s);
    sem_post(&semaphore);
    // free(args);
    return NULL;
}

int main () {
    pthread_t   thread[THREAD_NUM];
    pthread_mutex_init(&lock, 0);
    sem_init(&semaphore, 0, 1);
    int x = 0;
    for (int i = 0; i <= THREAD_NUM; i++)
    {
        int *a = malloc(sizeof(int));
        *a = i;
        pthread_create(&thread[i], 0, &routine, a);
    }
    for (int i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(thread[i], 0);
    }
    sem_destroy(&semaphore);
}