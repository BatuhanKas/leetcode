/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:06:19 by bkas              #+#    #+#             */
/*   Updated: 2024/02/13 13:38:29 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>

#define THREAD_NUM 4
sem_t sem;

void    *thread(void *arg) {
    //sem wait şu işe yarar.
    //semaphore değeri 0'dan büyükse, bir azaltır ve devam eder.
    //semaphore değeri 0 ise, bekler.
    sem_wait(&sem);
    printf("Thread\n");
    //sem post ise şu işe yarar.
    //semaphore değeri 0'dan büyükse, bir arttırır ve devam eder.
    //semaphore değeri 0 ise, bekleyen bir thread varsa onu uyandırır.
    sem_post(&sem);
    return (NULL);
}

int main (int argc, char **argv) {
    pthread_t th[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; i++) {
        pthread_create(&th[i], NULL, &thread, NULL);
    }
    // sem init parametreleri şunlardır:
    // 1. sem_t *sem: semaforun adresi
    // 2. int pshared: 0 veya 1 olabilir. 0 ise semafor sadece process içinde paylaşılır. 1 ise semafor processler arasında paylaşılır.
    // 3. unsigned int value: semaforun başlangıç değeri
    sem_init(&sem, 0, 0);
    sem_open("sem", O_CREAT, 0644, 0);
}