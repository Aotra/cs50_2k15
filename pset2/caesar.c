#include <string.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
          int main(int argc,string argv[])
            {
            int i=0;
            char se=' ';
                if(argc != 2)//in case user enters more than 2 command arguments(the 2 command arguments includes the program's name) 
                {
                    printf("you should have just entered a number, now try again\n"); 
                    return 1;
                    }
                    int k =atoi(argv[1]);//converts inputted string in command argument  to integer if possible.
                    string s=GetString();//accepts the string to be encrypted.
                    if(s!= NULL)
                    {                   
                        for(i=0;i<strlen(s);i++)
                        {
                            if(islower(s[i]))//checkes whether the character at s[i] is in lower case alphabets
                            {                                                      
                                   se=(((s[i]-97)+k)%26)+97;//encrypts the letter present at s[i].
                                   printf("%c",se);
                                    }                           
                                
                              
                             else if(isupper(s[i]))//checkes whether the character at s[i] is in upper case alphabets
                             {
                                    se=(((s[i]-65)+k)%26)+65;//encrypts the letter present at s[i].
                                    printf("%c",se);                                    
                                 }
                              else
                                  printf("%c",s[i]);//if s[i] is not an alphabet it is printed without encryption.
                                  } 
                                  printf("\n");                                                                   
                                  return 0;
                          }
                     }        
