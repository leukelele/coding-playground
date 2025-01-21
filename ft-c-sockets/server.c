// Server side C program to demonstrate Socket programming
#include <netinet/in.h>   // seems to be used to provide constants and structs for 
                          // IP addresses
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>   // provides the ability for creating endpoints that will be 
                          // used for network communication
#include <unistd.h>


#define PORT 22           // the port that the server will be listening to

int main(int argc, char const* argv[])
{
    int server_fd, new_socket;            // these variables will be for storing the
                                          // return values by:
                                          // - `socket()` returns a file descriptor (fd) 
                                          //   for the new socket; on error, it will
                                          //   return -1
                                          // - `accept()` is similar, though not in
                                          //   functionality
    ssize_t valread;
    struct sockaddr_in address;           // from `netinet/in.h`, is a struct for
                                          // storing addresses
    int opt = 1;
    socklen_t addrlen = sizeof(address);  // from `sys/socket.h`, describes the length
                                          // of the socket address
    char buffer[1024] = { 0 };
    char* hello = "Hello from server";

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {  // socket() accepts args
                                                              // as follows:
                                                              // socket(domain, type,
                                                              // protocol)
                                                              //
                                                              // `AF_INET` is used to
                                                              // designate the type of
                                                              // addr (IPv4) 
                                                              // that the socket
                                                              // comm. with; `SOCK_STREAM`
                                                              // is used to indicate the type
                                                              // of comm.; `0` is the val.
                                                              // for the IP protocol 
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 22; this code is optional but helps in the
    // resuse of addr and port -> it prevents the error "address already in use"
    if (setsockopt(server_fd, SOL_SOCKET,              // `setsockopt` is used to config
                   SO_REUSEADDR | SO_REUSEPORT, &opt,  // options for a socket, allows for
                   sizeof(opt))) {                     // mod of socket behaviors at
                                                       // runtime
                                                       //
                                                       // args: (socket fd, level, options,
                                                       // ptr to val set by option, option
                                                       // length)
                                                       // `SOL_SOCKET` for socket lvl opts;
                                                       // `SO_REUSEADDR` and `SO_REUSEPORT`
                                                       // to allow for socket and port
                                                       // reuse `&opt` to indicate
                                                       // enabling/disabling
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;	// local host IP
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  &addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read(new_socket, buffer,
                   1024 - 1); // subtract 1 for the null
                              // terminator at the end
    printf("%s\n", buffer);
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // closing the connected socket
    close(new_socket);
    // closing the listening socket
    close(server_fd);
    return 0;
}
