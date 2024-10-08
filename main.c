#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <gpiod.h>
#include "spi_data.h"
#include "spi.h"
//#include "data.h"




struct gpiod_line *cs;
struct gpiod_line *prgrmn;



int main() {
   
    spi_init(3000*1024,&cs,&prgrmn);
    
    usleep(1000);
    //Device ID read 	
    device_id();
    
    usleep(10);
    //ISC_ENABLE
    isc_enable();
    usleep(10);
    
    //ISC_ERASE
    isc_erase();
    usleep(10);
    
    //Status Register Check, DONE=0 and Fail=0
    sr_check(0);
    
    //Send bitstream using LSC_BITSTREAM_BURST
    fast_program();
    
    usleep(10);
    
    
    //Status Register Check, DONE=1 and Fail=0
    sr_check(1);

    usleep(10);
	
    //Exits programming mode and enters usermode
    isc_disable();

    rbpi_exit();
	
	
}
