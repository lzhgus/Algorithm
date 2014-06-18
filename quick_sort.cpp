/*
  快速排序
  实践表明快速排序是所有排序里面最高效的排序，采用了分治的方法。先保证列表的前半部小于后半部
  然后分别对前半部和后半部分排序，这样整个列表就有序了
*/

#include <iostream>
using namespace std;

void quick_sort(int a[], int num)
{
  int i = 0; j = num - 1;
  int val = a[0]; // 指定参考值val大小
  if(num > 1) // 确保数组至少为2， 否则无需排序
  {
    while(i < j) // 循环结束条件
    {
      for(; j > i; j--) // 从后往前搜索比val小的元素，找到后调到a[i]并跳出循环
        if(a[j] < val)
        {
          a[i] = a[j];
          break;
        }
      for(; i < j; i++) // 从前往后搜索比val大的元素， 找到后调到a[j]并跳出循环
        if(a[i] > val)
        {
          a[j] = a[i];
          break;
        }
    }
    a[i] = val; // 将保留在val中的数放到a[i]中
    quick_sort(a, i); // 递归， 前i个数
    quick_sort(a+i+1, num - 1); // 递归，后面的数
  }
}

int main()
{
  int array[] = {10, 9, 8, 7, 6, 5, 4};
  quick_sort(array, 7);
  for(int i = 0; i < 7; i++)
    {
      cout << array[i] << " ";
    }
  return 0;
}  
  
  
