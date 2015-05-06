//
//  main.c
//  Suanfa_C
//
//  Created by sinosoft on 15/4/24.
//  Copyright (c) 2015年 SinoSoft. All rights reserved.
//

#include <stdio.h>
#include <sys/time.h>
//选择排序:交换次数最大是N，比较次数是（N－1）+(N-2)+... +1 = N*(N-1)/2，算法的效率取决于比较的次数
//两个鲜明特点：运行时间与输入（数组初始状态）无关；数据移动时最少的，用了N次交换
/*
 时间复杂度
 选择排序的交换操作介于 0 和 (n - 1） 次之间。选择排序的比较操作为 n (n - 1） / 2 次之间。选择排序的赋值操作介于 0 和 3 (n - 1） 次之间。
比较次数O(n^2），比较次数与关键字的初始状态无关，总的比较次数N=(n-1）+(n-2）+...+1=n*(n-1）/2。交换次数O(n），最好情况是，已经有序，交换0次；最坏情况交换n-1次，逆序交换n/2次。交换次数比冒泡排序少多了，由于交换所需CPU时间比比较所需的CPU时间多，n值较小时，选择排序比冒泡排序快。
 
 稳定性
 选择排序是给每个位置选择当前元素最小的，比如给第一个位置选择最小的，在剩余元素里面给第二个元素选择第二小的，依次类推，直到第n-1个元素，第n个元素不用选择了，因为只剩下它一个最大的元素了。那么，在一趟选择，如果一个元素比当前元素小，而该小的元素又出现在一个和当前元素相等的元素后面，那么交换后稳定性就被破坏了。比较拗口，举个例子，序列5 8 5 2 9，我们知道第一遍选择第1个元素5会和2交换，那么原序列中两个5的相对前后顺序就被破坏了，所以选择排序是一个不稳定的排序算法。
 */

void select_sort(int array[],int length) {
    int value;
    int temp;
    int index = 0;
    for (int index1 = 0; index1<length;index1++) {
        value = array[index1];
        for (int index2 = index1+1; index2<length; index2++) {
            if (array[index2] < value) {
                value = array[index2];
                index = index2;
            }
        }
        if (value == array[index1]) {
            continue;
        } else {
            temp = array[index1];
            array[index1] = array[index];
            array[index] = temp;
        }
    }
    printf("array%d",array[0]);
}
//插入排序
void insert_sort(int array[],int length) {
//    将一张牌插入到其他已经有序的牌中的适当位置，在计算机实现中，为了给插入的元素腾出空间，我们需要将其余所有的元素在插入之前都向右移动一位，这种算法叫做插入排序

    /*
     最坏的情况：9，8，7，6，5，4，3，2，1
     i=1    8,9,7,6,5,4,3,2,1 比较1次，交换1次
     i=2    8,7,9,6,5,4,3,2,1 ; 7,8,9,6,5,4,3,2,1 比较2次，交换2次
     i=3    7,8,6,9,5,4,3,2,1 ; 7,6,8,9,5,4,3,2,1 ; 6,7,8,9,5,4,3,2,1  比较3次，交换3次
     ....
     */
    
    /*
     最好的情况：1，2，3，4，5，6，7，8，9
     i=1    ［1，2，］  3，4，5，6，7，8，9 比较1次，交换0次
     i=2    1，  ［2，3，］   4，5，6，7，8，9 比较1次，交换0次
     i=3    1，2， ［3，4，］   5，6，7，8，9  比较1次，交换0次
     ....
     */
    //最坏需要N^2/2比较，N^2/2交换，最好情况需要N－1次比较，0次交换
    
    /*倒置指的是数组中两个顺序颠倒的元素。比如：E,X,A,M,P,L,E 中有11对倒置：E-A,X-A,X-M,X-P,X-L,X-E,M-L,M-E*/
    for (int i=1; i<length; i++) {
//        a[i]插入a[i－1]、a[i-2]、。。。。a[0]之间
        for(int j = i;j>0;j--) {
            if (array[j] < array[j-1]) {//升序
                int tmp = array[j];
                array[j] = array[j-1];
                array[j-1] = tmp;
            } else {
                break;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
//    int a[] = {4,3,5,6,2,1,9,7,23,11,34,24,56,78,19,15,45,678,34,98,27,25,54};//优先选择排序
//    int a[] = {1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,23,24,25,26,27,28,30,31,32,33,34,35,36,37,45,46,47,48,50,51,60};//实际优先插入排序，其实运行选择排序略优
    int a[] = {34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};//优先选择排序
    struct timeval tv0;
    struct timezone tz0;
    gettimeofday (&tv0, &tz0);
//    printf("tv0_sec; %ld\n", tv0.tv_sec);
//    printf("tv0_usec; %d\n", tv0.tv_usec);
//    printf("tz0_minuteswest; %d\n", tz0.tz_minuteswest);
//    printf("tz0_dsttime, %d\n", tz0.tz_dsttime);
//    select_sort(a,(sizeof(a)/sizeof(a[0])));
    insert_sort(a,(sizeof(a)/sizeof(a[0])));
    printf("Hello, World!\n");
    
    struct timeval tv;
    struct timezone tz;
    gettimeofday (&tv, &tz);
    printf("相差; %d\n", tv.tv_usec - tv0.tv_usec);
    
    return 0;
}

