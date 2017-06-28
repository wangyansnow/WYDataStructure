//
//  WYLinearList.h
//  01-链表
//
//  Created by 王俨 on 2017/6/7.
//  Copyright © 2017年 com.minyan.www. All rights reserved.
//  线性表


typedef int WYElementType;
#ifndef WYLinearList_h
#define WYLinearList_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct linearList {
    WYElementType *data;
    int MaxSize;
    int Last;
};

typedef struct linearList WYLinearList;


/// 线性表的初始化
void InitList (WYLinearList *l, int size);

/// 释放线性表的存储空间
void freeList(WYLinearList *l);

/// 判断线性表是否为空
bool isEmptyList(WYLinearList *l);

/// 判断线性表是否已满
bool isFullList(WYLinearList *l);

/// 线性表的长度
int listLength(WYLinearList *l);

/// 取线性表的第i个表目
WYElementType getElement(WYLinearList *l, int i);

/// 查找表中值为elem的节点，若查找成功则返回序列号，否则返回-1
/// 若表中有多个elem节点，则找到的是最前面的一个
int locateElement(WYLinearList *l, WYElementType elem);

/// 在第i个节点插入elem，插入成功返回true,失败返回false
bool insertElem(WYLinearList *l, WYElementType elem, int i);

/// 删除表中第i个节点，删除成功返回true,失败返回false
bool deleteElem(WYLinearList *l, int i);

/// 打印线性表的表目
void printList(WYLinearList *l);



#endif /* WYLinearList_h */

