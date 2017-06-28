//
//  WYDirectSort.c
//  02-算法
//
//  Created by 王俨 on 2017/6/26.
//  Copyright © 2017年 com.minyan.www. All rights reserved.
//  直接插入排序

#include "WYDirectSort.h"
#include <stdlib.h>

void initForSort(ForSort *fs, int a) {
    fs->key = a;
}

void directInsertionSort(ForSort sorts[], int n) {
    
    ForSort lastSort = sorts[0];
    
    for (int i = 1; i < n; i++) {
        ForSort sort = sorts[i];
        if (sort.key >= lastSort.key) {
            lastSort = sort;
            continue;
        }
        
        sorts[i] = lastSort;
        int j = i - 1;
        
        while (j > 0) {
            ForSort currentSort = sorts[j - 1];
            if (sort.key < currentSort.key) {
                sorts[j] = currentSort;
                j--;
                continue;
            }
            break;
        }
        
        sorts[j] = sort;
    }
}

/**
 1、寻找A[i]需要插入的位置，则A[0]~A[i - 1]都已经是排好序了的
 2、所谓折半比较就是取A[(i - 1) / 2]与A[i]进行比较
 3、如果A[i] < A[(i - 1) / 2],则应该是在A[0] ~ A[(i - 1) / 2 - 1]之间插入A[i]，于是可以继续使用折半比较,
 【k = 0, r = ( i - 1 ) / 2 - 1】
 4、如果A[i] > A[(i - 1) / 2],则应该是在A[(i - 1) / 2 + 1] ~ A[i - 1]之间继续进行折半比较
 【k = (i - 1) / 2 + 1, r = i - 1】
 5、一般地在A[k]和A[r]之间采用折半比较，其中间节点应该是A[(k + r) / 2];
 6、当k > r的时候，k的值就是A[i]需要插入的位置
 */
void binaryInsertionSort(ForSort sorts[], int n) {
    
    for (int i = 1; i < n; i++) {
        int k = 0;
        int r = i - 1;
        int m;
        
        ForSort sort = sorts[i];
        while (k <= r) { // 当k > r 跳出循环
            
            m = (k + r) / 2;
            ForSort msort = sorts[m];
         
            if (sort.key < msort.key) { // A[k] ~ A[m - 1]
                k = 0;
                r = m - 1;
                
            } else { // A[m + 1] ~ A[r]
                k = m + 1;
                r = r;
            }
        }
        
        for (int j = i; j > r; j--) {
            sorts[j] = sorts[j - 1];
        }
        sorts[k] = sort;
    }
}

/** 思想：
 1、先选定一个整数s1 < n
 2、把所有记录分成s1个组，所有距离为s1的记录分在同一组内，并对每一组内的记录进行排序
 3、取s2 < s1, 重复1和2
 4、当si = 1的时候，所有记录在同一组内排好序，则就是最后的顺序
 */
void shellSort(ForSort sorts[], int n, int s) {
    if (s >= n) {
        printf("传入参数有误\n");
        return;
    }
    
    while (s > 0) {
        for (int i = 0; i < s; i++) {
            int sCount = (n - i - 1) / s + 1; // 每组有多少个记录
            
            ForSort lastSort = sorts[i];
            for (int j = 1; j < sCount; j++) { // 对每组进行直接插入排序
                int index = i + j * s;
                ForSort sort = sorts[index];
                if (sort.key >= lastSort.key) {
                    lastSort = sort;
                    continue;
                }
                
                // 往前找到sort需要插入的位置
                sorts[index] = lastSort;
                int k = j - 1;
                while (k > 0) {
                    int currentIndex = i + (k - 1) * s;
                    ForSort currentSort = sorts[currentIndex];
                    if (sort.key < currentSort.key) {
                        int previousIndex = i + (k - 1) * s;
                        sorts[currentIndex] = sorts[previousIndex];
                        k--;
                        continue;
                    }
                    break;
                }
                
                int lastIndex = i + k * s;
                sorts[lastIndex] = sort;
            }
        }
        s = s / 2;
    }
}

ForSort * getRandomSorts(int count) {
    ForSort *sorts = malloc(sizeof(ForSort) * 100);
    for (int i = 0; i < count; i++) {
        ForSort *sort = malloc(sizeof(ForSort));
        initForSort(sort, arc4random_uniform(200));
        sorts[i] = *sort;
    }

    return sorts;
}

void testDirectSort(int count) {
    ForSort *sorts = getRandomSorts(count);
    
    directInsertionSort(sorts, count);
    
    for (int i = 0; i< count; i++){
        ForSort sort = sorts[i];
        printf("sort.key = %d \n", sort.key);
    }
}

void testBinarySort(int count) {
    ForSort *sorts = getRandomSorts(count);
    
    directInsertionSort(sorts, count);
    
    for (int i = 0; i< count; i++){
        ForSort sort = sorts[i];
        printf("sort.key = %d \n", sort.key);
    }
}

void testShellSort(int count, int s) {
    ForSort *sorts = getRandomSorts(count);
    
    shellSort(sorts, count, s);
    
    for (int i = 0; i < count; i++) {
        ForSort sort = sorts[i];
        printf("sort.key = %d\n", sort.key);
    }
}








