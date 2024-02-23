/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkas <bkas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:06:19 by bkas              #+#    #+#             */
/*   Updated: 2024/02/13 17:44:33 by bkas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

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
    // sem init şu işe yarar.
    // semaforu başlatır.
    sem_init(&sem, 0, 0);
    // sem open parametreleri şunlardır:
    // 1. const char *name: semaforun ismi
    // 2. int oflag: semaforun açılma şekli. O_CREAT, O_EXCL, O_RDWR, O_RDONLY, O_WRONLY
    // 3. mode_t mode: semaforun izinleri
    // 4. unsigned int value: semaforun başlangıç değeri
    // sem open şu işe yarar.
    // semaforu açar.
    sem_open("sem", O_CREAT, 0644, 0);
    for (int i = 0; i < THREAD_NUM; i++) {
        pthread_join(th[i], NULL);
    }
    // sem destroy parametreleri şunlardır:
    // 1. sem_t *sem: semaforun adresi
    // sem destroy şu işe yarar.
    // semaforu yok eder.
    sem_destroy(&sem);
    // sem close parametreleri şunlardır:
    // 1. sem_t *sem: semaforun adresi
    // sem close şu işe yarar.
    // semaforu kapatır.
    sem_close(&sem);
    return (0);
}
