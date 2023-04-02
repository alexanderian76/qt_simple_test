#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <QtWidgets>

#define PORT_NUMBER     5000
#define SERVER_ADDRESS  "192.168.1.74"
#define FILENAME        "send.txt"

void send(QString);
void die(char *);
