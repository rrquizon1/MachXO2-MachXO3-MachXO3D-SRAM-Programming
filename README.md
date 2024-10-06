This is an SSPI programming example using Raspberry pi 5.

This example uses lgpiod library so make sure to install it: sudo apt-get install gpiod libgpiod-dev.

The instructions used in this program follows the guideline of FPGA-TN-02069-1.7([MachXO3D Programming and Configuration User Guide](https://www.latticesemi.com/view_document?document_id=52591))  

MachXO3D's compressed bitstream is still within the Raspberry Pi's buffer limit, so we can send all the data in one call.

Source files:
main.c- contains the programming procedure

spi.c- contains function for SPI transaction and some programming commands for Nexus devices.

spi_data.c- contains the data to be programmed

Makefile- compiles the project.

Steps to run the project:

1. Compile by running the makefile

2. Run the executable generated ./rhodz_SPI_XO3D

Key points to ensure during the Slave SPI (SSPI) configuration flow:

1. Confirm that SSPI is activated in the feature row. SSPI 

2. Read the status registers before and after sending the bitstream to verify that the DONE bit is programmed correctly and there are no failure in configuration. 
