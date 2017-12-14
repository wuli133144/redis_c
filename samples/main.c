


#include <unistd.h>
#include <stdio.h>

#include <string.h>
#include "adlist.h"
#include "utils.h"


int main(){

     list *head=listCreate();
    if(head==NULL){
          log_info("create list error!");
          return (-1);


    }else{

       log_info("create list head ok!");


        int a=12;
        listNode *node=NULL;
         listAddNodeHead(head,&a);
         listAddNodeHead(head,&a);
         listAddNodeHead(head,&a);
         listAddNodeHead(head,&a);
         listAddNodeHead(head,&a);
         listAddNodeHead(head,&a);
         listAddNodeHead(head,&a);
         
        listIter *iter=listGetIterator(head,AL_START_HEAD);

         
       
        
        while((node=listNextElement(iter)!=NULL)){
            
             //          log_info("value %d\n",node->value);
             //
             //          log_info("%d",*(int*)node->value);
             //
            printf(">>>>>>>>>>>>>>>start>>>>>>>>>>>\n");
            printf("%p",((int *)node->value));



            
        }
        
    }

    return 0;
}
