//
//  WYVector.h
//  01-链表
//
//  Created by 王俨 on 2017/6/7.
//  Copyright © 2017年 com.minyan.www. All rights reserved.
//

#ifndef WYVector_h
#define WYVector_h

#include <stdio.h>
#include <stdlib.h>
typedef int WYElementType;

enum boolean {FALSE, TRUE};
typedef enum boolean Bool;

struct vector {
    WYElementType *elements;
    int arraySize;
    int vectorLength;
};
typedef struct vector WYVector;

/// 申请向量存储空间
void getArray(WYVector *vector);

/// 初始化一空向量
void initVector(WYVector *vector, int size);

/// 取向量的第i个表目
WYElementType getNode(WYVector *vector, int i);

/// 释放向量存储空间
void freeVector(WYVector *vector);

/// 查找node在向量中的位置，没有返回-1
int findNode(WYVector *vector, WYElementType node);

/// 删除向量的第i个表目，成功删除返回true,失败返回false
Bool removeNode(WYVector *vector, int i);





#endif /* WYVector_h */
