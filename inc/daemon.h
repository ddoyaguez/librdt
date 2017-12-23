/*
---
Copyright 2017 David Doyaguez Sanchez (daviddoyaguez@gmail.com)
---
This file is part of LibRDT.

    LibRDT is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    LibRDT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with LibRDT.  If not, see <http://www.gnu.org/licenses/>.
---
*/
#ifndef DAEMON_H
#define DAEMON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

/**
* @brief
* Daemonizes the program that executes this function
*
* @return 0 when fails to daemonize
* @return 1 when everything OK
*/
int rdt_daemonize();

/**
* @brief
* Determines if the program that executes this function is daemonized (it has called rdt_daemonize)
*
* @return 0 when not daemonized
* @return 1 when daemonized
*/
int rdt_is_daemonized();

/**
* @brief
* Opens a log file to write in
* @param log_filename path to the log file
*
* @return -2 when there is an open log file
* @return -1 when log_filename is NULL
* @return 0 when the program is not daemonized
* @return 1 when everything OK
*/
int rdt_open_log_file(char* log_filename);

/**
* @brief
* Closes the log file
*
* @return -1 when there is no log file to close
* @return 0 when the program is not daemonized
* @return 1 when everything OK
*/
int rdt_close_log_file();

/**
* @brief
* Logs a string to the log file
* @param log string that is going to be logged
*
* @return -1 when log is NULL
* @return 0 when there is no log file opened
* @return 1 when everything OK
*/
int rdt_log(char* log);

#endif
