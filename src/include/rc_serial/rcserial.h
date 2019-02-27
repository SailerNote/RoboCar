//
// Created by PulsarV on 18-5-10.
//

#ifndef ROBOCAR_RCSERIAL_H
#define ROBOCAR_RCSERIAL_H

#include <rc_log/rclog.h>
#include <fcntl.h>
#include <iostream>
#include <rc_globalVarable/rc_global_serial.h>
#include <rc_serial/imu_device/JY901.h>
#include <map>
#ifdef __linux__

#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <zconf.h>
#include <linux/serial.h>

#else

#endif
namespace RC {
    int set_serial(int fd, int nSpeed, int nBits, char nEvent, int nStop);
    typedef std::map<std::string, std::string> SERIAL_FLAGS;
    typedef std::pair<std::string, std::string> SERIAL_FLAG;

    class Serial {
    public:
#ifdef __linux__

        int openSerial(char *device);

        int send(std::string str);

        int send(long comm);

        int recive(char *buffer, int size);

        bool isOpend();

        int release();

        static int data_encode(int data);
        static int data_encode(char data);
        static int data_encode(std::string data);

    private:
        int device_point;
        char *device;
    };

#else

#endif

}
#endif //ROBOCAR_RCSERIAL_H
