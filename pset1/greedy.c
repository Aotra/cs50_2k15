#include <math.h>
#include <cs50.h>
#include <stdio.h>
    int main()
        {
            int fa=0,g=0;
            float a;
            printf("How much change is owed :\n"); 
            a=GetFloat();
             while(!(a>=0))
            {                                                        
                printf("Retry: ");
                a=GetFloat();
                }
                a=a*100;
                fa=(int) round(a);
                g=fa/25;
                fa=fa-(25*g);
                if(fa==0)
                {
                    printf("%i\n",g);
                    return 0;
                    }
                g=g+(fa/10);
                fa=fa-((fa/10)*10);
                if(fa==0)
                {
                    printf("%i\n",g);
                    return 0;
                    }
                g=g+(fa/5);
                fa=fa-((fa/5)*5);
                if(fa==0)
                {
                    printf("%i\n",g);
                    return 0;
                    }
                g=g+fa;
                printf("%i\n",g);
                return 0;
                }
           
            
                          
