#include <cs50.h>
#include <stdio.h>
    int main()
        {
            int r,j=0,i=0;
            printf("Enter the height :\n");
            r=GetInt(); 
            while(!(r>=0&&r<=23))
            {
                printf("Retry: ");                                
                r=GetInt();                           
                        }
                        if(r==0)
                        return 0;                                                 
                            for(i=r;i>=1;i--)
                            {
                                for(j=1;j<=(r+1);j++)
                                {
                                    if(j>=i)
                                    printf("#");
                                    else
                                    printf(" ");
                                    }
                                    printf("\n");
                                    }
                                        return 0;
                                        }
                                    
                     
                
