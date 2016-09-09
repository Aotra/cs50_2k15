/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
#define DICTIONARY "/home/cs50/pset5/dictionaries/large"



typedef struct trienode

        {
            int value;
            struct trienode *children[27];
         }node;
         
         
int words;
node *root;

 
node *getNode(void)

        {
             node *nnode=NULL;
             nnode=(node *)malloc(sizeof(node));
             if(nnode)
             {
              nnode->value=0;
              for(int i=0;i<27;i++)
              nnode->children[i]=NULL;
              }
              return nnode;
          }
         

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 
bool load(const char* dictionary)

        {
            root=getNode();
            words=0;
            
            FILE* fp = fopen(dictionary, "r");
            
            if (fp == NULL)
                {
                    fclose(fp);
                    return false;
                  }
                
            while(1)
            {
                 char word[LENGTH+1]={};
                 fscanf(fp,"%s\n",word);
                 words++;
                 int inde=0;
                 node *crawl;
                 crawl=root;
                 for(int level=0;level<strlen(word);level++)
                 {
                     if((word[level])=='\'')
                     inde=26;
                     else
                     inde=((int)(word[level]))-((int)'a');
                        if(!crawl->children[inde])
                        {
                             crawl->children[inde]=getNode();
                             crawl=crawl->children[inde];
                          }
                        else
                        crawl=crawl->children[inde];
                    }
                crawl->value=1;
                
                if(feof(fp))
                break;
                             
                if (ferror(fp))
                {
                    fclose(fp);
                    return false;
                  }
              }

            fclose(fp);
            return true;
         }


/**
 * Returns true if word is in dictionary else false.
 */
 
bool check(const char* word)

        {
            int inde;
            node *crawl=root;
            
            for(int level=0;level<strlen(word);level++)
            {
                if((word[level])=='\'')
                inde=26;
                else if(isupper(word[level]))
                inde=(tolower(word[level]))-'a';
                else
                inde=(word[level])-'a';
                
                if(crawl->children[inde]==NULL)
                return false;
                
                crawl=crawl->children[inde];
              } 
                 
                if(crawl->value==1)    
                return true;
                else 
                return false;
          }


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
 
unsigned int size(void)

        {            
            return (words);
          }


void freeNode(node *cnode)

        {    
            for(int i=0;i<27;i++)
            {
                if(cnode->children[i]!=NULL)                
                freeNode(cnode->children[i]);              
              }
                              
                free(cnode);
                cnode=NULL;
          }


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
 
bool unload(void)

        {  
             if(root!=NULL)
             freeNode(root);
             return true;
           }

