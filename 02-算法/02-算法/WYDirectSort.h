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
/// 直接插入排序 [稳定] O(n²)
void directInsertionSort(ForSort sorts[], int n);
/// 折半插入排序 [稳定] O(nlog2n)
void binaryInsertionSort(ForSort sorts[], int n);
/// shell排序 [不稳定] O(n1.3)平均移动和比较次数
void shellSort(ForSort sorts[], int n, int s);

/// 直接选择排序 [不稳定] O(n²)
void directSelectSort(ForSort sorts[], int n);
/// 树形选择排序 O(nlog2n)
void treeSelectSort(ForSort sorts[], int n);

/// 快速排序 [不稳定] 更加健壮 O(nlog2n)
void quickSort(ForSort sorts[], int n);

/// 二路并归排序
void mergeSort(ForSort sorts[], int n);

ForSort* getRandomSorts(int count);
ForSort* getRegularSorts(int count);

void testDirectSort(int count);
void testBinarySort(int count);
void testShellSort(int count, int s);

void testSelectSort(int count);
void testTreeSelectSort(int count);

void testQuickSort(int count);

void testMergeSort(int count);

void checkRight(ForSort sorts[], int count);


#endif /* WYDirectSort_h */
