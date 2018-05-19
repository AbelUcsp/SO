#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "pthread.h"

char buff[20];	int fd;
pthread_mutex_t semaforo;

void enviarS()
{

	pthread_mutex_lock(&semaforo);
	write(fd, buff, sizeof(buff));	
	pthread_mutex_unlock(&semaforo);
}



int main(int arg, char*argg[])
{
	
	pthread_mutex_init(&semaforo, NULL); //semaforo glob
	char *myfifo = "/tmp/myfifo";
	mkfifo(myfifo, 0666); 
	fd = open(myfifo, O_WRONLY);
	
	sprintf(buff,"%s","mensaje");


	printf("Enviando 8 threads\n");
	

	pthread_t otrhilo1;
	pthread_t otrhilo2;
	pthread_t otrhilo3;
	pthread_t otrhilo4;
	pthread_t otrhilo5;
	pthread_t otrhilo6;
	pthread_t otrhilo7;
	pthread_t otrhilo8;
	pthread_create(&otrhilo1, NULL, (void*)enviarS ,NULL);
	pthread_create(&otrhilo2, NULL, (void*)enviarS ,NULL);
	pthread_create(&otrhilo3, NULL, (void*)enviarS ,NULL);
	pthread_create(&otrhilo4, NULL, (void*)enviarS ,NULL);
	pthread_create(&otrhilo5, NULL, (void*)enviarS ,NULL);
	pthread_create(&otrhilo6, NULL, (void*)enviarS ,NULL);
	pthread_create(&otrhilo7, NULL, (void*)enviarS ,NULL);
	pthread_create(&otrhilo8, NULL, (void*)enviarS ,NULL);
	pthread_join(otrhilo1, NULL);
	pthread_join(otrhilo2, NULL);
	pthread_join(otrhilo3, NULL);
	pthread_join(otrhilo4, NULL);
	pthread_join(otrhilo5, NULL);
	pthread_join(otrhilo6, NULL);
	pthread_join(otrhilo7, NULL);
	pthread_join(otrhilo8, NULL);



	return 0;
}

