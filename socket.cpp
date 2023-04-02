/*
	Simple udp client
*/
#include "socket.h"
#include <fstream>
void die(char *s)
{
	perror(s);
	exit(1);
}

void send(QString filename)
{
	int client_socket;
        ssize_t len;
        struct sockaddr_in remote_addr;
        char buffer[BUFSIZ];
        int file_size;
        std::fstream received_file;
        int remain_data = 0;

        /* Zeroing remote_addr struct */
        memset(&remote_addr, 0, sizeof(remote_addr));

        /* Construct remote_addr struct */
        remote_addr.sin_family = AF_INET;
        inet_pton(AF_INET, SERVER_ADDRESS, &(remote_addr.sin_addr));
        remote_addr.sin_port = htons(PORT_NUMBER);

        /* Create client socket */
        client_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (client_socket == -1)
        {
                fprintf(stderr, "Error creating socket --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
               
        }

        /* Connect to the server */
        if (connect(client_socket, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) == -1)
        {
                fprintf(stderr, "Error on connect --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
               
        }

        /* Receiving file size */
        recv(client_socket, buffer, BUFSIZ, 0);
        file_size = atoi(buffer);
        fprintf(stdout, "\nFile size : %d\n", file_size);

        received_file.open("test.txt",std::fstream::out);
    

        if (filename.isEmpty())
            return;

        QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    //fopen(FILENAME, "w");
        if (received_file.is_open())
        {
                fprintf(stderr, "Failed to open file foo --> %s\n", strerror(errno));

                exit(EXIT_FAILURE);
               
        }

        remain_data = file_size;
        puts(buffer);
        
        fprintf(stdout, "\nRemain data : %d\n", remain_data);
      //  buffer[0] = '\0';
      
        //fprintf(stdout, "\nRemain data : %e\n", recv(client_socket, buffer, BUFSIZ, 0));
        while ((remain_data > 0) && ((len = recv(client_socket, buffer, BUFSIZ, 0)) > 0))
        {
                //fwrite(buffer, sizeof(char), len, received_file);
            //received_file << buffer;
            file.write(buffer, len);
                remain_data -= len;
                fprintf(stdout, "\nRemain data : %d\n", remain_data);
                //fprintf(stdout, "Receive %d bytes and we hope :- %d bytes\n", len, remain_data);
        }
      
        printf("%d", len);
        //fclose(received_file);
    

    //QTextStream out(&file);

   // out << ui->textEdit->toPlainText() << "\n";

    file.close();
    
    received_file.close();
        close(client_socket);
    //return file;
      //  return 0;
}
