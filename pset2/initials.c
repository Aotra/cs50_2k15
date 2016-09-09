#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
          int main()
          {
                int i=0,l=0;
                string s=GetString(); 
                if(s!=NULL)
                {
                    for(i=0,l=strlen(s);i<l;i++)
                    {
                        if(!((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&& s[i]<='Z')||s[i]==' '))
                        {
                            printf("this program will not work for this input\n");
                            return 1;  
                            }
                          }
                                
                                if(islower(s[0]))
                                printf("%c",toupper(s[0]));
                                else if(isupper(s[0]))
                                printf("%c",s[0]);
                                                               
                          for(i=0,l=strlen(s);i<l;i++)
                          {
                            
                            if(s[i]==' ')
                            {
                                if(islower(s[i+1]))
                                printf("%c",toupper(s[i+1]));
                                else if(isupper(s[i+1]))
                                printf("%c",s[i+1]);                            
                                }
                          }
                          printf("\n");
                          return 0;
                     } 
                 }     
