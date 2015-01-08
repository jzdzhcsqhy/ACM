#ifndef __SORT_H__
#define __SORT_H__

//合并排序
//经典分治法排序算法
//参  数：1 待排序数组，这里用整型做示例
//       2 左侧边界位置
//       3 右侧边界位置
//返回值：
void MergeSort(int a[100], int l, int r);


//堆排序
//完全二叉树模型，大顶堆，
//参  数：1 待排序数组，这里用整型做示例
//       2 待排序元个数
//返回值：

void HeapSort( int a[100], int n );


#endif