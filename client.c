/*
  Simple udp client
  Silver Moon (m00n.silv3r@gmail.com)
*/
#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
#include <unistd.h>

#define SERVER "64.233.185.113"
#define BUFLEN 512  //Max length of buffer
#define PORT 8080   //The port on which to send data
 
void die(char *s)
{
  perror(s);
  exit(1);
}
 
int main(void)
{
  struct sockaddr_in si_other;
  int s, i, slen=sizeof(si_other);
  char buf[BUFLEN];
  char *message = "hello world";
 
  if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
      die("socket");
    }
 
  memset((char *) &si_other, 0, sizeof(si_other));
  si_other.sin_family = AF_INET;
  si_other.sin_port = htons(PORT);
     
  if (inet_aton(SERVER , &si_other.sin_addr) == 0) 
    {
      fprintf(stderr, "inet_aton() failed\n");
      exit(1);
    }
 
  while(1)
    {    
      //send the message
      if (sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, slen)==-1)
        {
	  die("sendto()");

        }else{

      }
      
    }
  
  close(s);
  return 0;
}
