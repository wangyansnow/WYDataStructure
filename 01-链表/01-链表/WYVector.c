//
//  WYVector.c
//  01-链表
//
//  Created by 王俨 on 2017/6/7.
//  Copyright © 2017年 com.minyan.www. All rights reserved.
//

#include "WYVector.h"


/// 申请向量存储空间
void getArray(WYVector *vector) {
    vector->elements = (WYElementType *)malloc(sizeof(WYElementType) * vector->arraySize);
    if (vector->elements == NULL) {
        printf("申请变量空间失败\n");
    }
}

/// 初始化一空向量
void initVector(WYVector *vector, int size) {
    if (size < 0) {
        printf("size参数不合法");
        return;
    }
    
    vector->arraySize = size;
    vector->vectorLength = 0;
    getArray(vector);
}

/// 取向量的第i个表目
WYElementType getNode(WYVector *vector, int i) {
    if (i < 0 || i >= vector->vectorLength) {
        return NULL;
    }
    return vector->elements[i];
}

/// 释放向量存储空间
void freeVector(WYVector *vector) {
    free(vector->elements);
}

/// 查找node在向量中的位置，没有返回-1
int findNode(WYVector *vector, WYElementType node) {
    for (int i = 0; i < vector->vectorLength; i++) {
        if (node == vector->elements[i]) {
            return i;
        }
    }
    return -1;
}

/// 删除向量的第i个表目，成功删除返回true,失败返回false
Bool removeNode(WYVector *vector, int i) {
    if (i < 0 || i >= vector->vectorLength) {
        return FALSE;
    }
    
    for (int j = i; j < vector->vectorLength - 1; j++) {
        vector->elements[j] = vector->elements[j + 1];
    }
    vector->vectorLength--;
    return TRUE;
}

/// 在向量第i个位置插入新节点，成功返回TRUE,失败返回FALSE
Bool insertNode(WYVector *vector, WYElementType node, int i) {
    if (i < 0 || i >= vector->vectorLength || vector->vectorLength == vector->arraySize) {
        return FALSE;
    }

    // 注意：这里需要重后往前的往后移动一个节点位置！！！
    for (int j = vector->vectorLength; j > i; j--) {
        vector->elements[j] = vector->elements[j - 1];
    }
    vector->elements[i] = node;
    vector->vectorLength++;
    return TRUE;
}

/// 删除第i个节点，若删除成功返回TRUE,失败返回FALSE
Bool deleteNode(WYVector *vector, int i) {
    if (i < 0 || i >= vector->vectorLength || vector->vectorLength == 0) {
        return FALSE;
    }
    
    // 注意：这里只需要把i后面的节点都往前移动一个节点即可
    for (int j = i; j < vector->vectorLength - 1; j++) {
        vector->elements[j] = vector->elements[j + 1];
    }
    vector->vectorLength--;
    return TRUE;
}

/// 把向量v1和v2合并到vector中，重复的元素只保留一个
WYVector *unionVector(WYVector *v1, WYVector *v2) {
    WYVector *vector = malloc(sizeof(WYVector));
    initVector(vector, v1->vectorLength + v2->vectorLength);
    getArray(vector);
    
    int j = 0;
    for (int i = 0; i < v1->vectorLength; i++) {
        insertNode(vector, v1->elements[i], j);
        j++;
    }
    
    for (int i = 0; i < v2->vectorLength; i++) {
        WYElementType node = v2->elements[i];
        if (findNode(vector, node) == -1) { // 没有这个节点
            insertNode(vector, node, j);
            j++;
        }
    }
    vector->vectorLength = j;
    
    return vector;
}

/// 将v1和v2中的相同元素合并到vector中
WYVector *intersection(WYVector *v1, WYVector *v2) {
    WYVector *vector = malloc(sizeof(WYVector));
    int vectorSize = v1->vectorLength < v2->vectorLength ? v1->vectorLength : v2->vectorLength;
    initVector(vector, vectorSize);
    getArray(vector);
    
    int j = 0;
    for (int i = 0; i < vectorSize; i++) {
        WYElementType node = getNode(v1, i);
        if (findNode(v2, node) != -1) {
            insertNode(vector, node, j);
            j++;
        }
    }
    vector->vectorLength = j;
    
    return vector;
}

/**
 设n个人围成一个圆圈，按一指定方向，从第s个人开始报数，报数到m为止，报数为m的人出列，然后从下一个人开始重新报数，报数为m的人出列....直到所有的人全部出列为止。Josephus问题要对任意给定的n,s,m，求出列次序得到的人员顺序表。
 */
void josephus(WYVector *vector, int n, int s, int m) {
    int start = s;
    // 1.将人员编号存入向量vector
    for (int i = 0; i < n; i++) {
        insertNode(vector, i+1, i);
    }
    
    for (int i = n; i >= 1; i--) {
        start = (start + m - 1) % i;
        if (start == 0) {
            start = i;
        }
        WYElementType node = getNode(vector, start - 1);
        removeNode(vector, start - 1);
        insertNode(vector, node, n-1);
    }
}




