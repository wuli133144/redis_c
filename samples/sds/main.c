/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: 2017年12月14日 星期四 12时13分04秒
 ************************************************************************/

#include<stdio.h>


#include "sds.h"

#include"utils.h"

int main(){
    


    #if 0
   sds str=sdsnewlen("xxxxx",5);
    if(str==NULL){
          log_info("new sds error");
    }

    log_info("%s",str);

    log_info("sds length %d",sdslen(str));

     #endif 


    #if 1
       sds str=sdsnew("wuyujie  fsadf w afsdfsdaf ");
    if(str==NULL){
        
    log_info("str==null error");
    }
    log_info("%d",sdslen(str));

    sds p=sdscat(str,"fdafsafs");

    log_info("strappend :%s",p);

    sds q= sdscatlen(str,">>>>>>>>>>>",20);
    log_info("sds cat len:%s",q);
    
    sdscpy(str,"wuyujiejie");
    log_info("strcpy dest %s",str);
    sdscatprintf(str," ---%s---","xxxx");
    

    log_info("strcpy dest %s",str);





    #endif 
   





  return 0;

}
