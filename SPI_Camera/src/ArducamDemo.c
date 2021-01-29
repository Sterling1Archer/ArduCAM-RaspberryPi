#include "capture.h"

int resolution = 6; 
int numberofphotos = 3;

char* ipc_qrecv(void);

int main(void){
   char image_filename[100];
   char order[50];
   strcpy(order,ipc_qrecv());
   
   
//**************************************************
//Fill array with order

   char * token = strtok(order, ".");
   char ipc[3], subsystem[3], function[3], argument[20], value[10];
   strcpy(ipc,token);
   token = strtok(NULL, ".");
   strcpy(subsystem,token);
   token = strtok(NULL, ".");
   strcpy(function,token);
   token = strtok(NULL, ".");
   strcpy(argument,token);
   token = strtok(NULL, ".");
   strcpy(value,token);
   token = strtok(NULL, ".");
   
//**************************************************
//If tree
   if(strcmp(ipc,"ipc") == 0){
   		if(strcmp(subsystem,"pay") == 0){
   			if(strcmp(function,"cmd") == 0){
               //Turn camera on and off
               if(strcmp(argument,"pwr") == 0){
                  if(strcmp(value,"1") == 0){
                     printf("Turning on");
                  }
                  if(strcmp(value,"0") == 0){
                     printf("Turning off");
                  }
               }
               //Set saturation
               if(strcmp(argument,"sat") == 0){
               
               }
               //Set number of photos
               if(strcmp(argument,"num_photos") == 0){
                  printf("%d",atoi(value));
                  numberofphotos = atoi(value);
               }
               //Commence photo taking
               if(strcmp(argument,"take_pic") == 0){
                  for(int i=0;i<numberofphotos;i++){
                        capture(image_filename);
                  }
               }
               //Set resolution
   				if(strcmp(argument,"res") == 0){
   					if(strcmp(value,"320x240") == 0){
   						resolution = OV5642_320x240;
                  }	
                  if(strcmp(value,"640x480") == 0){
   						resolution = OV5642_640x480;
                  }	
                  if(strcmp(value,"1024x768") == 0){
   						resolution = OV5642_1024x768;
                  }	
                  if(strcmp(value,"1280x960") == 0){
   						resolution = OV5642_1280x960;
                  }	
                  if(strcmp(value,"1600x1200") == 0){
   						resolution = OV5642_1600x1200;
                  }	
                  if(strcmp(value,"2048x1536") == 0){
   						resolution = OV5642_2048x1536;
                  }	
                  if(strcmp(value,"2592x1944") == 0){
						printf("Test");
   						resolution = OV5642_2592x1944;
					}	
			   }
		   }
	   }
	   
   }

   
   //char command[100] = "cd /home/pi/Pictures/payloadcapture/;split -b20000 ";
   //system(strcat(command,&filename));
   //printf("filename: %s\n", image_filename);
   
   return 0;
}
      
char* ipc_qrecv(void){
   return "ipc.pay.cmd.take_pic.3";
}

   
   
   
