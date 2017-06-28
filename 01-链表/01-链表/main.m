//
//  main.m
//  01-链表
//
//  Created by 王俨 on 2017/6/7.
//  Copyright © 2017年 com.minyan.www. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "WYLinearList.h"

void linearList();

int main(int argc, const char * argv[]) {
    
    linearList();
    
    return 0;
}

void linearList() {
    WYLinearList *list = (WYLinearList *)malloc(sizeof(WYLinearList));
    InitList(list, 5);
    if (insertElem(list, 4, 0)) {
        printf("插入成功\n");
    } else {
        printf("插入失败\n");
    }
    
    insertElem(list, 50, 0);
    insertElem(list, 510, 0);
    insertElem(list, 530, 0);
    insertElem(list, 540, 0);
    printList(list);
    
    printf("530 in %d \n", locateElement(list, 530));
    
    printf("first = %d \n", getElement(list, 1));
}
