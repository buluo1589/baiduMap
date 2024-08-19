#include <stdio.h>
#include <cstring>
#include <sys/types.h>
#include <sys/select.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#include <math.h>

extern "C"
{
    #include "Serial.h"
}
int GET_GPS(double *lon, double *lat)
{
    char temp = 0;
    int RX_Count = 0;
    char gpsRxBuffer[1024];

    char *field;
    char longtitude_str[10];
    char *longtitude_WE = (char*)malloc(sizeof(char));
    char latitude_str[10];
    char *latitude_NS = (char*)malloc(sizeof(char));
    int index = 0;

    int FLAG=1;

    double longtitude;
    double latitude;

    int fd;
    int nread, i;

    fd_set rfd;

    if ((fd = open_port(fd, 3)) < 0)
    {
        // perror("open_port error");
        return 0;
    }
    else
    {
        // printf("open_port success\n");
    }

    // 初始化,设置串口
    if ((i = set_opt(fd, 9600, 8, 'N', 1)) < 0)
    {
        // perror("set_opt error");
        return 0;
    }

    FD_ZERO(&rfd);
    FD_SET(fd, &rfd);

    while (FD_ISSET(fd, &rfd) && FLAG==1)
    {
        if (select(fd + 1, &rfd, NULL, NULL, NULL) < 0)
        {
            // perror("select");
        }
        else
        {
            temp = 0;
            while (((nread = read(fd, &temp, 1)) > 0))
            {
                //printf("%c", temp);
                if (temp == '$')
                {

                    RX_Count = 0;
                }
                if (RX_Count <= 5)
                {

                    gpsRxBuffer[RX_Count++] = temp;
                }
                else if (gpsRxBuffer[0] == '$' && gpsRxBuffer[4] == 'M' && gpsRxBuffer[5] == 'C')
                {
                    gpsRxBuffer[RX_Count++] = temp;
                    if (temp == '\n')
                    {
                        field = strtok(gpsRxBuffer, ",");

                        while (1)
                        {
                            if (field)
                            {
                                if (field[0] == 'V')
                                {
                                    break;
                                }

                                switch (index)
                                {
                                case 3:
                                    strncpy(latitude_str, field,sizeof(latitude_str)-1);
                                    break;
                                case 4:
                                    (*latitude_NS)=*field;
                                    break;
                                case 5:
                                    strncpy(longtitude_str, field,sizeof(longtitude_str)-1);
                                    break;
                                case 6:
                                    (*longtitude_WE)=*field;
                                    break;
                                default:
                                    break;
                                }
                                index++;
                                field = strtok(NULL, ",");
                            }
                        }

                        if ((*latitude_NS) == 'N')
                        {
                            latitude = atof(latitude_str);
                        }
                        if ((*latitude_NS) == 'S')
                        {
                            latitude = -atof(latitude_str);
                        }
                        if ((*longtitude_WE) == 'E')
                        {
                            longtitude = atof(longtitude_str);
                        }
                        if ((*longtitude_WE) == 'W')
                        {
                            longtitude = -atof(longtitude_str);
                        }
FLAG=0;
                        *lon = (int)longtitude / 100+fmod(longtitude, 100) / 60.0;
                        *lat = (int)latitude/100 +fmod(latitude,100)/60.0;


                        index = 0;

                        RX_Count = 0;
                        memset(gpsRxBuffer, 0, sizeof(gpsRxBuffer)); // Çå¿Õ
                    }
                }
            }
        }
    }

    close(fd);

    return 0;
}
