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

#pragma mark - 插入排序
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

#pragma mark - 选择排序
// 注意点：找到待排序记录中j所在的值为最小，将其放到已经排好序的末尾i的位置，这时的操作应该是交换i和j位置对应的值
/** 思想
 1、每次在待排序记录中选择排序码最小的记录，顺序放在已排序的记录最后，直到排序完成
 */
void directSelectSort(ForSort sorts[], int n) {
    
    for (int i = 0; i < n - 1; i++) {
        ForSort sort = sorts[i];
        
        int tempJ = -1;
        for (int j = i + 1; j < n; j++) { // 找到排序码最小的记录
            ForSort nextSort = sorts[j];
            if (nextSort.key < sort.key) {
                sort = nextSort;
                tempJ = j;
            }
        }
        
        if (tempJ > -1) {
            sorts[tempJ] = sorts[i];
        }
        sorts[i] = sort;
    }
}

/** 思想
 1、把所有的待选择排序记录分为两两一组进行比较，把得出的小的结果的下标保存起来
 2、对得到的结果继续进行第一步操作直到找到排序码最小的记录
 */
void treeSelectSort(ForSort sorts[], int n) {
    
    int count = n - 1;
    for (int i = 0; i < count; i++) {

        int number = n - i;
        int groupCount = (number - 1) / 2 + 1;
      
        // 记录所有待排序记录的下标
        int *locations = malloc(sizeof(int) * number);
        for (int k = 0; k < number; k++) {
            locations[k] = k + i;
        }
        
        while (groupCount > 1) {
            
            int *tempLocations = malloc(sizeof(int) * groupCount);
            for (int j = 0; j < groupCount; j++) {
                int index = locations[j * 2];
                int nextLocation = j * 2 + 1;
                
                if (nextLocation >= number) { // 这组只有一个，不用比较
                    tempLocations[j] = locations[index];
                    ForSort sort = sorts[index];
                    continue;
                }
                
                // 有两个，取排序码小的的下标
                int nextIndex = locations[nextLocation];
                ForSort currentSort = sorts[index];
                ForSort nextSort = sorts[nextIndex];
                
                tempLocations[j] = currentSort.key < nextSort.key ? index : nextIndex;
            }
            
            free(locations);
            locations = tempLocations;
            number = groupCount;
            groupCount = (number -1) / 2 + 1;
        }
        
        // 此时只有最后一组，里面可能有一个或两个记录
        int replaceIndex;
        if (number == 1) {
            replaceIndex = locations[0];
        } else {
            int firstIndex = locations[0];
            int lastIndex = locations[1];
            replaceIndex = sorts[firstIndex].key < sorts[lastIndex].key ? firstIndex : lastIndex;
        }
        
        if (replaceIndex != i) {
            ForSort replaceSort = sorts[replaceIndex];
            sorts[replaceIndex] = sorts[i];
            sorts[i] = replaceSort;
            
            ForSort sort = sorts[replaceIndex];
        }
        
        free(locations);
    }
    
}

#pragma mark - TestSelect
void testSelectSort(int count) {
    ForSort *sorts = getRandomSorts(count);
    
    directSelectSort(sorts, count);
    
    for (int i = 0; i < count; i++) {
        printf("sort.key = %d \n", sorts[i].key);
    }
}

void testTreeSort(int count) {
    ForSort *sorts = getRandomSorts(count);
    
    treeSelectSort(sorts, count);
    
    for (int i = 0; i < count; i++) {
        printf("sort.key = %d \n", sorts[i].key);
    }
}

#pragma mark - TestInsertion
ForSort* getRandomSorts(int count) {
    ForSort *sorts = malloc(sizeof(ForSort) * count);
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







