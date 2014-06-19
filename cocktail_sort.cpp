/*
  鸡尾酒排序： 
  定向冒泡排序， 数组中的数字本是无序排放
  先找到最小的数放在第一位， 再找到最大的数放在最后一位
  再找第二小的数放在第二位， 然后第二大的数放在倒数第二位
*/

#include <iostream>
using namespace std;

void cocktail_sort(int[] a, int length)
{
  for(int i = 0; i < length/2; i++){
    //将最小的排到队尾
    for(int j = i; j < length - 1 - i; j++)
    {
      if(a[j] < a[j+1]){
        int temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
    //将最大的排到队头
    for(int j = length -(i+1) -1; j>i; j--){
      if(a[j] > a[j-1]){
        int temp = a[j];
        a[j] = a[j-1];
        a[j - 1] = temp;
      }
    }
  }
}

