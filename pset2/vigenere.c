#include <string.h>
#include <cs50.h>
#include <stdio.h>

          int main(int argc,string argv[])
          {
                int le=0,i=0,p=0,j=0;
                char se;
                string k;
                
                if(argc!=2)
                {
                    printf("this program will not work for this input\n");
                    return 1;
                    }
                    int l=strlen(argv[1]);
                    for(i=0;i<l;i++)
                    if(!(((argv[1][i])>='a'&& (argv[1][i])<='z')||((argv[1][i])>='A'&& (argv[1][i])<='Z')))
                    {
                        printf("this program will not work for this input\n");
                        return 1;  
                        }
                         string s=GetString(); 
                         le=strlen(s);
                         if(s!= NULL)
                         {
                             k=argv[1];
                             for(i=0;i<le;i++)
                             {
                                    if((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&& s[i]<='Z'))
                                    {                                   
                                        if(p<(l-1))
                                          {                                           
                                                if(k[p]>='a'&& k[p]<='z')
                                                {
                                                    j=k[p]-97;                                                
                                                    p++;
                                                }
                                                else 
                                                {                                                
                                                    j=k[p]-65;
                                                    p++;                                                
                                                    }
                                                }
                                          else
                                          {
                                                if(k[p]>='a'&& k[p]<='z')
                                                j=k[p]-97;
                                                else 
                                                j=k[p]-65;
                                                p=0;
                                            }                          
                                         if(s[i]>='a' && s[i]<='z')//checkes whether the character at s[i] is in lower case alphabets
                                            {                                                      
                                                se=(((s[i]-97)+j)%26)+97;//encrypts the letter present at s[i].
                                                printf("%c",se);
                                                }                          
                                                else if(s[i]>='A' && s[i]<='Z')//checkes whether the character at s[i] is in upper case alphabets
                                                 {
                                                     se=(((s[i]-65)+j)%26)+65;//encrypts the letter present at s[i].
                                                     printf("%c",se);                                    
                                                     }
                                                     }
                                                else
                                                    printf("%c",s[i]);//if s[i] is not an alphabet it is printed without encryption.
                                                                                      
                                                     }
                                                     printf("\n");                                                                   
                                                        return 0;
                                                }
                                          }        
                                         
                                     
                                     
                                     
                                     
                                     
                         
                         
                         
                         
                         
                         
                         
                        
