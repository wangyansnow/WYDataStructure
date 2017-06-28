//
//  WYLinearList.c
//  01-链表
//
//  Created by 王俨 on 2017/6/7.
//  Copyright © 2017年 com.minyan.www. All rights reserved.
//

#include "WYLinearList.h"

/// 线性表的初始化
void InitList (WYLinearList *l, int size) {
    if (size <= 0) return;
    
    l->MaxSize = size;
    l->Last = 0;
    l->data = (WYElementType *)malloc(sizeof(WYElementType) * l->MaxSize);
}

/// 释放线性表的存储空间
void freeList(WYLinearList *l) {
    free(l->data);
}

/// 判断线性表是否为空
bool isEmptyList(WYLinearList *l) {
    return l->Last > 0 ? false : true;
}

/// 判断线性表是否已满
bool isFullList(WYLinearList *l) {
    return l->Last == l->MaxSize;
}

/// 线性表的长度
int listLength(WYLinearList *l) {
    return l->Last;
}

/// 取线性表的第i个表目
WYElementType getElement(WYLinearList *l, int i) {
    if (i < 0 || i >= l->Last) {
        return NULL;
    }
    
    return l->data[i];
}

/// 查找表中值为elem的节点，若查找成功则返回序列号，否则返回-1
/// 若表中有多个elem节点，则找到的是最前面的一个
int locateElement(WYLinearList *l, WYElementType elem) {
    for (int i = 0; i < l->Last; i++) {
        if (l->data[i] == elem) {
            return i;
        }
    }
    
    return -1;
}

/// 在第i个节点插入elem，插入成功返回true,失败返回false
bool insertElem(WYLinearList *l, WYElementType elem, int i) {
    if (l->Last == l->MaxSize || i< 0 || i > l->Last) {
        return false;
    }
    
    for (int j = l->Last - 1; j >= i; j--) {
        l->data[j + 1] = l->data[j];
    }
    l->data[i] = elem;
    l->Last++;
    return true;
}

/// 删除表中第i个节点，删除成功返回true,失败返回false
bool deleteElem(WYLinearList *l, int i) {
    if (i < 0 || i > (l->Last - 1) || l->Last == 0) {
        return false;
    }
    
    for (int j = i; j < (l->Last - 1); j++) {
        l->data[j] = l->data[j + 1];
    }
    l->Last--;
    return true;
}

/// 打印线性表的表目
void printList(WYLinearList *l) {
    for (int i = 0; i < l->Last; i++) {
        printf("%d = %d \n", i, l->data[i]);
    }
    printf("\n");
}

























