#include "capture.h"

int main(void){
   
   char image_filename[100];
   
   capture(image_filename);
   
   //char command[100] = "cd /home/pi/Pictures/payloadcapture/;split -b20000 ";
   //system(strcat(command,&filename));
   printf("filename: %s\n", image_filename);
   
   return 0;
}
      
   
   
   
   
