//
//  main.m
//  02-算法
//
//  Created by 王俨 on 2017/6/26.
//  Copyright © 2017年 com.minyan.www. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WYDirectSort.h"

void testEfficiencySort();

int main(int argc, const char * argv[]) {
    
    testTreeSort(10);
    
    
    return 0;
}

void testEfficiencySort() {
    int count = 100000;
    
    ForSort *sorts1 = getRandomSorts(count);
    ForSort *sorts2 = getRandomSorts(count);
    ForSort *sorts3 = getRandomSorts(count);
    
    CFTimeInterval time1 = CFAbsoluteTimeGetCurrent();
    directInsertionSort(sorts1, count);
    printf("direct.time = %f \n", CFAbsoluteTimeGetCurrent() - time1);
    
    CFTimeInterval time2 = CFAbsoluteTimeGetCurrent();
    binaryInsertionSort(sorts2, count);
    printf("binary.time = %f \n", CFAbsoluteTimeGetCurrent() - time2);
    
    CFTimeInterval time3 = CFAbsoluteTimeGetCurrent();
    shellSort(sorts3, count, count / 2);
    printf("ashell.time = %f \n", CFAbsoluteTimeGetCurrent() - time3);
}
