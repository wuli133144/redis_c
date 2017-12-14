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

   sds str=sdsnewlen("xxxxx",5);
    if(str==NULL){
          log_info("new sds error");
    }

    log_info("%s",str);

    log_info("sds length %d",sdslen(str));
  return 0;

}
