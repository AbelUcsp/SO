#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include "pthread.h"

int fd;
char buf[100];
pthread_mutex_t semaforo;

void recibirS()
{
	if(read(fd, buf, sizeof(buf))){ //si hay datos para leer
		pthread_mutex_lock(&semaforo);
		read(fd, buf, sizeof(buf));
		pthread_mutex_unlock(&semaforo);
		printf("Received: %s\n", buf);
	}
}



int main()
{
	
	pthread_mutex_init(&semaforo, NULL); //semaforo glob
	char * myfifo = "/tmp/myfifo";


	mkfifo(myfifo, 0666); 
	fd = open(myfifo,  O_RDONLY);

	while(read(fd, buf, sizeof(buf))){

	pthread_t otrhilo1;
	pthread_t otrhilo2;
	pthread_t otrhilo3;
	pthread_t otrhilo4;
	pthread_t otrhilo5;
	pthread_t otrhilo6;
	pthread_t otrhilo7;
	pthread_t otrhilo8;
	pthread_t otrhilo9;
	pthread_t otrhilo10;
	pthread_create(&otrhilo1, NULL, (void*)recibirS ,NULL);
	pthread_create(&otrhilo2, NULL, (void*)recibirS ,NULL);
	pthread_create(&otrhilo3, NULL, (void*)recibirS ,NULL);
	pthread_create(&otrhilo4, NULL, (void*)recibirS ,NULL);
	pthread_create(&otrhilo5, NULL, (void*)recibirS ,NULL);
	pthread_create(&otrhilo6, NULL, (void*)recibirS ,NULL);
	pthread_create(&otrhilo7, NULL, (void*)recibirS ,NULL);
	pthread_create(&otrhilo8, NULL, (void*)recibirS ,NULL);
	pthread_create(&otrhilo9, NULL, (void*)recibirS ,NULL);
	pthread_create(&otrhilo10, NULL, (void*)recibirS ,NULL);
	pthread_join(otrhilo1, NULL);
	pthread_join(otrhilo2, NULL);
	pthread_join(otrhilo3, NULL);
	pthread_join(otrhilo4, NULL);
	pthread_join(otrhilo5, NULL);
	pthread_join(otrhilo6, NULL);
	pthread_join(otrhilo7, NULL);
	pthread_join(otrhilo8, NULL);
	pthread_join(otrhilo9, NULL);
	pthread_join(otrhilo10, NULL);


	}

   	close(fd);
	unlink(myfifo);
	return 0;
}
