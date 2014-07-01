/*
  有些问题，哪个大神帮我改改！
  归并排序， 建立在归并操作上的有效排序，采用分治法。 
  1. 申请空间，使其大小为两个已排序列之和， 用来存储合并后的序列。
  2. 设定两个指针，最初位置分别为两个已排序列的起始位置。
  3. 比较两个指针所指向的元素， 选择小的元素放入合并空间， 并移动指针到下一个位置。
  4. 重复步骤3直到某一指针到达序列尾部。
  5. 将另一序列剩下的元素全部复制到合并序列尾部。
  
  如　设有数列{6，202，100，301，38，8，1}
  初始状态：6,202,100,301,38,8，1
  第一次归并后：{6,202},{100,301},{8,38},{1}，比较次数：3；
  第二次归并后：{6,100,202,301}，{1,8,38}，比较次数：4；
  第三次归并后：{1,6,8,38,100,202,301},比较次数：4；
  总的比较次数为：3+4+4=11,；
  逆序数为14；
  时间复杂度 O(nlogn)
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

void merge_sort(int *arr, int arr_size);
void merge_sortsub(int *arr1, int arr1_size, int *arr2, int arr2_size);

void merge_sort(int *arr, int arr_size)
{
        if(arr_size > 1)
        {
                int *arr1 = arr;
                int arr1_size = arr_size / 2;
                int *arr2 = arr + arr1_size;
                int arr2_size = arr_size - arr1_size;

                merge_sort(arr1, arr1_size);
                merge_sort(arr2, arr2_size);

                merge_sortsub( arr1, arr1_size, arr2, arr2_size);
        }
}

void merge_sortsub( int *arr1, int arr1_size, int *arr2, int arr2_size)
{
        int i=0, j=0, k = 0;
        int *arr = new int[arr1_size + arr2_size+1];

        while(i < arr1_size && j < arr2_size){
                arr[k++] = arr1[i] < arr2[j] ? arr1[i++] : arr2[j++];
        }

        while(i < arr1_size){
                arr[k++] = arr1[i++];
        }

        while(j < arr2_size){
                arr[k++] = arr2[j++];

        }

        for(int ii = 0; ii < (arr1_size + arr2_size); ++ii){
                arr1[ii] = arr[ii];
        }
}


int main()
{
        int a[] = {10, 9, 8, 7 , 6, 5, 4};
        merge_sort(a, 7);
        for(int i = 0; i < 8; i++){
                cout << a[i] << " ";
        }
        return 0;
}


























