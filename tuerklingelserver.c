#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 4210
#define MAXBUFLEN 100
#define SPAMPROTECTION 2 //seconds between accepted rings

void error (char *msg)
{
  fprintf (stderr, "%s\n", msg);
  exit (1);
}

int main (void)
{
  int s;
  char buf[MAXBUFLEN];
  struct sockaddr_in name;
  if ((s = socket (PF_INET, SOCK_DGRAM, 0)) < 0)
    error ("cannot create socket");
  memset (&name, 0, sizeof (name));
  name.sin_family = AF_INET;
  name.sin_port = htons (PORT);
  name.sin_addr.s_addr = htonl (INADDR_ANY);
  int on = 1;
  setsockopt (s, SOL_SOCKET, SO_REUSEADDR, (void *) &on, sizeof (on));
  if (bind (s, (struct sockaddr *) &name, sizeof (name)) < 0)
    {
      close (s);
      error ("cannot bind socket");
    }
  struct sockaddr_in clientname;
  socklen_t size = sizeof (clientname);

  time_t last_ring=time(NULL);
  while(1)
  {
    if(recvfrom(s,buf,MAXBUFLEN-1,0,(struct sockaddr *)&clientname,&size) && last_ring+SPAMPROTECTION<=time(NULL))
      {
      time(&last_ring);
      printf("Es hat an der Tür geklingelt !!! %s  \n",asctime(localtime(&last_ring)));
      system("python3 /usr/local/bin/telegram.py");
      }
  }


  return 0;
}
