


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

         
       
        
        while((node=listNextElement(iter))!=NULL){
            
             //          log_info("value %d\n",node->value);
             //
             //          log_info("%d",*(int*)node->value);
             //
            printf(">>>>>>>>>>>>>>>start>>>>>>>>>>>\n");
            printf("%p", (node->value));
            log_info("%p",(node->value));
            void *p=node->value;
            int a=  *(int *)p;
            
            log_info(">>>>>>>>>>>>>>>>>data:%d\n",(a));
           
            
        } 


         //查找value
         
        listNode *p= listIndex(head,1) ;//查找索引值
        log_info("listindex %d",*(int *)(p->value));
         
        listNode *q=listSearchKey(head,&a);
        if(q==NULL){
             log_info("cant find key");
            
        }else{
                log_info("yes find ");

        }


listRelease(head);
        if(head==NULL){
            log_info("head released :!");
        }else{
            
             log_info("head exite:wq");
        }
        
    }

    return 0;
}
