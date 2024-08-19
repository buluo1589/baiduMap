#ifndef SERIAL_H
#define SERIAL_H

int open_port(int fd, int comport);
int set_opt(int fd, int nSpeed, int nBits, char nEvent, int nStop);

#endif
