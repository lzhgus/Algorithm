/*
  选择排序
  1. 数组内存中存有n个待排数字， 下标从1 开始 到 n结束。 
  2. 初始化 i = 1
  3. 从数组的第i个元素到第n个元素，寻找最小元素
  4. 将寻找到的最小元素与第i位进行交换
  5. i++， 知道i= n-1， 算法结束， 否则退回第三步
  时间复杂度 O(n^2)
*/

#include <iostream>
using namespace std;

void select_sort(int a[], int length)
{
  int temp;
  int post;
  for(int i = 0; i < length - 1; i++)
  {
    temp = a[i];
    post = i;
    for(int j = i + 1; j < length -1; j++)
    {
      if(a[j] < temp)
      {
        temp = a[j];  // 将数组中i+1到 n 中的最小值付给temp
        post = j;   // 记录该点
      }
    }
    a[post] = a[i];  // 交换 记录的点和原始的点
    a[i] = temp;
  }
}

int main()
{
  
  int array[] = {10, 9, 8, 7, 6, 5, 4};
  select_sort(array, 7);
  for(int i = 0; i < 7; i++)
  {
    cout << array[i] << " ";
  }
  return 0;
}
  
