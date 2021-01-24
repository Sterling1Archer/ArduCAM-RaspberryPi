#include "capture.h"

int capture(char* capture_filename){
	
//Variable declaration
   char image_file_path[255] = {"/home/pi/Pictures/payloadcapture/"};
   char * timestamp = malloc (sizeof (char) * 100);
   time_t caltime;
    
//**************************************************
//Setup camera
   pioInit();
   ArduCAM_CS_init( CAM_CS1, -1, -1, -1 );   // init the cs
   sccb_bus_init();
   spiInit(4000000, 0); //8MHZ
   Arducam_bus_detect( CAM_CS1, -1, -1, -1 );
   resetFirmware( CAM_CS1, -1, -1, -1 );  //reset the firmware
   ArduCAM_Init(sensor_model);
   OV5642_set_JPEG_size(OV5642_1024x768);
   time(&caltime); //read time
   
//**************************************************
//Capture photo

   singleCapture(CAM_CS1);

//**************************************************
//Build the filename for the photo with date and time, one with filepath and one without

  strftime(timestamp,40,"payloadcapture_%y_%m_%d_%H:%M:%S",localtime(&caltime));
  strcat(image_file_path,timestamp);
  strcpy(capture_filename,timestamp);
  
//**************************************************
//Open and write file

   FILE* ImageFile = fopen(image_file_path, "wb");
   fwrite(readbuf, sizeof(char), length, ImageFile);
   fclose(ImageFile);
   
//************************************************
//Success message

	printf("Capture Successful, Goodbye\n");
   return 0;
}
