/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
        {
            n=n-1;
            int k=0;
            int m=n/2;
            while(k<=n)
            {    
            if(value<values[m])
            n=m-1;
            
            else if(value>values[m])
            k=m+1;
            
            else if(value==values[m])
            return true; 
            m=(k+n)/2;   
            }
                return false;
        }

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
        {
            int i=0,j=0,tmp=0;
            for(i=0;i<n;i++)
            {
                for(j=i;j<n;j++)
                {
                    if(values[i]>values[j])
                    {
                        tmp=values[i];
                        values[i]=values[j];
                        values[j]=tmp;
                        }
                     }
                   }
                   return;
                }
