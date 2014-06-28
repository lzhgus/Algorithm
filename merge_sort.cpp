/*
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

using namespace std;

void merge_sort(int a[])
{
  if(a.size()==1){
    return a;
  }
  
  int half = a.size()/2;
  int arr1[half];
  int arr2[a.size() - half];
  
  memcpy(arr1, a, arr1.size());
  memcpy(arr2, a, arr2.size());
  
  arr1 = merge_sort(arr1);
  arr2 = merge_sort(arr2);
  
  return merge_sortsub(arr1, arr2);
}

void merge_sortsub(int a[], int b[])
{
  int result[arr1.size() + arr2.size()];
  int i = 0, j = 0, k = 0;
  while(true){
    if(arr1[i] < arr2[j]){
      result[k] = arr1[i];
      if(++i > arr1.size()-1){
        break;
      }
    } else {
      result[k] = arr2[j];
      if(++j > arr2.size()-1){
       break;
      }
    }
    k++;
  }
    
  for(; i < arr1.size(); i++){
    result[++k] = arr1[i];
  }
  for(; j < arr2.size(); j++){
    rssult[++k] = arr2[j];
  }
  return result;
}


int main()
{
  int array[] = {10, 9, 8, 7, 6, 5, 4};
  merge_sort(array);
  for(int i = 0; i < 7; i++)
    {
      cout << array[i] << " ";
    }
  return 0;
}  


























