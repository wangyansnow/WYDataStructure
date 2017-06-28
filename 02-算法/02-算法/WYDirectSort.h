//
//  WYDirectSort.h
//  02-算法
//
//  Created by 王俨 on 2017/6/26.
//  Copyright © 2017年 com.minyan.www. All rights reserved.
//

#ifndef WYDirectSort_h
#define WYDirectSort_h

#include <stdio.h>

typedef int ElementType;

struct forSort {
    ElementType key;
};

typedef struct forSort ForSort;

void initForSort(ForSort *fs, int a);
/// 直接插入排序
void directInsertionSort(ForSort sorts[], int n);
/// 折半插入排序
void binaryInsertionSort(ForSort sorts[], int n);
/// shell排序
void shellSort(ForSort sorts[], int n, int s);

void testDirectSort(int count);
void testBinarySort(int count);
void testShellSort(int count, int s);


#endif /* WYDirectSort_h */
