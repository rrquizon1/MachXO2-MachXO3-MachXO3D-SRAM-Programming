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

1. Confirm that SSPI is activated in the feature row. SSPI is activated in the feature row not via activation key like in Nexus devices. 

![image](https://github.com/user-attachments/assets/94e9dd47-ff00-4d1b-bbde-50bec039fc1c)

You can check if you enabled SSPI in your project by going to global preferences:
![image](https://github.com/user-attachments/assets/64e561e6-ce76-4efb-8918-dac189a0e645)

SSPI setting is stored in the feature row setting. This can be set via .fea file for MachXO3D and .jed file for MachXO2/MachXO3.

2. Read the status registers before and after sending the bitstream to verify that the DONE bit is programmed correctly and there are no failure in configuration.

You can modify g_iDataSize and g_pucDataArray with your bitstream information. With this example, MachXO3D Breakout board default bitstream is used which has 35331 bytes of data.

![image](https://github.com/user-attachments/assets/38b750bf-5614-4b31-8067-cd19c6f53d0d)

Main.c follows procedure indicated in FPGA-TN-02069:
![image](https://github.com/user-attachments/assets/26abf444-e299-48d3-bf25-53532882c9f4)


Sample Waveform transactions:

Device ID read:
![image](https://github.com/user-attachments/assets/de00569a-0d06-49ec-8c78-4f1a7835d131)

DONE pin goes high after sending ISC_DISABLE:
![image](https://github.com/user-attachments/assets/657745e4-fb65-40fc-af2c-4b57d46486ef)



