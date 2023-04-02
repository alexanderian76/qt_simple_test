#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT_NUMBER     5000
#define SERVER_ADDRESS  "192.168.1.75"
#define FILENAME        "send.txt"

void send();
void die(char *);