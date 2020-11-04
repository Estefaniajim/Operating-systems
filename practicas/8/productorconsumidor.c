#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFF_SIZE 10

sem_t mutexBuffer;
unsigned int buffer[BUFF_SIZE];

sem_t emEspacios; // Indicar espacios dispoinbles
sem_t emDatos; // Indicar que hay algo que consumir

void * producer(void *args) {
  int i = 0;
  while(1) {
    sleep(1);
    sem_wait(&emEspacios);
    sem_wait(&mutexBuffer);
    buffer[i] = rand();
    sem_post(&mutexBuffer);
    sem_post(&emDatos);
    i = (i+1)%BUFF_SIZE;
  }
  pthread_exit(NULL);
}

void * consumer(void *args) {
  int i = 0;
  while(1) {
    sem_wait(&emDatos);
    sem_wait(&mutexBuffer);
    int dato = buffer[i];
    sem_post(&mutexBuffer);
    sem_post(&emEspacios);
    printf("El valor leído es %d\n", dato);
    sleep(2);
    i = (i+1)%BUFF_SIZE;
  }
  pthread_exit(NULL);
}

int main() {
  sem_init(&mutexBuffer, 0, 1);
  sem_init(&emEspacios, 0, BUFF_SIZE);
  sem_init(&emDatos, 0, 0);
  pthread_t tProducer;
  pthread_t tConsumer;
  pthread_create(&tProducer, NULL, producer, NULL);
  pthread_create(&tConsumer, NULL, consumer, NULL);

  pthread_exit(NULL);
} 