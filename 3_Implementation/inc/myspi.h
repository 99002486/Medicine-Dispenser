#ifndef __MYSPI_H
#define __MYSPI_H
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>


#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
static void pabort(const char *s);

static void parse_opts(int argc, char *argv[]);

static void print_usage(const char *prog);

static void transfer(int fd,int med_num);

int SPI_transmit(int med_num);
#endif
