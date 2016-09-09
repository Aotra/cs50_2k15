/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 #include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{
   
       FILE* file = fopen("card.raw", "r");
       if (file == NULL)
    {
        fclose(file);
        fprintf(stderr, "unable to open .\n");
        return 1;
    }
    uint8_t cj[4]= {0xff,0xd8,0xff,0xe0};
    uint8_t cj2[4]= {0xff,0xd8,0xff,0xe1};
    uint8_t buffer[512];
    uint8_t check[4];
    int n=0;
    char image[8];
    int open=0;
    FILE* img;
   
       while(fread(buffer,512,1,file)>0)
       {
            for(int i=0;i<4;i++)
            {
            check[i]=buffer[i];
            }
            
            if(memcmp(cj,check,sizeof(check))==0 || memcmp(cj2,check,sizeof(check))==0)
            {
                if(n!=0)
                {
                if(img)
                fclose(img);
                }
                  
                  sprintf(image,"%.3d.jpg",n);
                  img=fopen(image,"w");
                  fwrite(buffer, 512, 1, img); 
                  n++;
                  open=1;
              }
               else
               {
                    if(open == 1)
                    
                     fwrite(buffer, 512, 1, img);
               }
                
                   }
                   
                   if(img)
                   {
                    fclose(img);
                    }
            fclose(file);
    
    

    // that's all folks
    return 0;
}


