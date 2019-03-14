# SortAlgorithms
There are some typical sort algorithms

# ClassicalSortingAlgorithm
This repository includes several classical sorting algorithms:
- InsertSorting
- ShellSorting
- SelectionSorting
- DualSelectionSorting
- HeapSorting
- BubbleSorting
- BubbleSortingWithPos
- BubbleSortingTwoDirection
- QuickSorting
- QuickSortingWithMinLen
- MergeSorting
- DualMergeSorting
- BucketSorting
- LsdRadixSorting

各种排序算法的介绍请参考他人的博客：  
[http://blog.csdn.net/hguisu/article/details/7776068](http://blog.csdn.net/hguisu/article/details/7776068)

# 1. 插入排序 #
## 直接插入排序 Straight Insertion Sort ##
基本思想  
将一个记录插入到已排序好的有序表中，从而得到一个新的且记录数增1的有序表。  
即：先将序列的第1个记录看成是一个有序的子序列，然后从第2个记录逐个进行插入，直至整个序列有序为止。  

要点：设立哨兵，作为临时存储和判断数组边界之用。  
如果碰见一个比插入元素大的，那么将该元素后移，直至当前元素<=插入元素  
所以，相等元素的前后顺序没有改变，从原无序序列出去的顺序就是排好序后的顺序，所以插入排序是稳定的。  

## 希尔排序 Shell`s Sort ##
尔排序又叫缩小增量排序  
基本思想  
先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，待整个序列中的记录“基本有序”时，再对全体记录进行依次直接插入排序。  

操作方法  
1. 选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
2. 按增量序列个数k，对序列进行k趟排序；
3. 每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m的子序列，分别对各子表进行直接插入排序。仅增量因子为1时，整个序列作为一个表来处理，表长度即为整个序列的长度。

# 2. 选择排序 #
## 简单选择排序 Simple Selection Sort ##
基本思想  
在要排序的一组数中，选出最小的一个数与第1个位置的数交换  
然后在剩下的数当中再找最小的与第2个位置的数交换，依次类推，直到第n-1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止。  

操作方法  
第一趟，从n个记录中找出关键码最小的记录与第一个记录交换；  
第二趟，从第二个记录开始的n-1 个记录中再选出关键码最小的记录与第二个记录交换；  
以此类推.....  
第i 趟，则从第i 个记录开始的n-i+1 个记录中选出关键码最小的记录与第i 个记录交换，  
直到整个序列按关键码有序。  

## 二元选择排序 Dual Selection Sort ##
简单选择排序，每趟循环只能确定一个元素排序后的定位。  
我们可以考虑改进为每趟循环确定两个元素（当前趟最大和最小记录）的位置,从而减少排序所需的循环次数。  
改进后对n个数据进行排序，最多只需进行[n/2]趟循环即可。  

## 堆排序 Heap Sort ##
堆排序是一种树形选择排序，是对直接选择排序的有效改进  

堆顶元素（即第一个元素）必为最小项（小顶堆）。  
若以一维数组存储一个堆，则堆对应一棵完全二叉树，且所有非叶结点的值均不大于(或不小于)其子女的值，根结点（堆顶元素）的值是最小(或最大)的。如：  
(a)大顶堆序列：(96, 83, 27, 38, 11, 09)  
(b)小顶堆序列：(12, 36, 24, 85, 47, 30, 53, 91)  

初始时把要排序的n个数的序列看作是一棵顺序存储的二叉树（一维数组存储二叉树），调整它们的存储序，使之成为一个堆  
将堆顶元素输出，得到n个元素中最小(或最大)的元素，这时堆的根节点的数最小（或者最大）。  
然后对前面(n-1)个元素重新调整使之成为堆，输出堆顶元素，得到n个元素中次小(或次大)的元素。  
依此类推，直到只有两个节点的堆，并对它们作交换，最后得到有n个节点的有序序列。称这个过程为堆排序。  

因此，实现堆排序需解决两个问题：  
1. 如何将n个待排序的数建成堆；
2. 输出堆顶元素后，怎样调整剩余n-1个元素，使其成为一个新堆。

首先讨论第二个问题：输出堆顶元素后，对剩余n-1元素重新建成堆的调整过程。  
调整小顶堆的方法：筛选---自根结点到叶子结点的调整过程  
1. 设有m个元素的堆，输出堆顶元素后，剩下m-1个元素。将堆底元素送入堆顶（最后一个元素与堆顶进行交换），堆被破坏，其原因仅是根结点不满足堆的性质。
2. 将根结点与左、右子树中较小元素的进行交换。
3. 若与左子树交换：如果左子树堆被破坏，即左子树的根结点不满足堆的性质，则重复方法（2）.
4. 若与右子树交换，如果右子树堆被破坏，即右子树的根结点不满足堆的性质。则重复方法（2）.
5. 继续对不满足堆性质的子树进行上述交换操作，直到叶子结点，堆被建成。

再讨论对n 个元素初始建堆的过程：  
建堆方法：对初始序列建堆的过程，就是一个反复进行筛选的过程。  
1. n个结点的完全二叉树，则最后一个结点是第n/2个结点的子树。
2. 筛选从第n/2个结点为根的子树开始，该子树成为堆。
3. 之后向前依次对各结点为根的子树进行筛选，使之成为堆，直到根结点。
如图建堆初始过程：无序序列：（49，38，65，97，76，13，27，49）  

# 3. 交换排序 #
## 冒泡排序 Bubble Sort ##
基本思想  
在要排序的一组数中，对当前还未排好序的范围内的全部数，自上而下对相邻的两个数依次进行比较和调整，让较大的数往下沉，较小的往上冒。  
即：每当两相邻的数比较后发现它们的排序与排序要求相反时，就将它们互换。  

冒泡排序算法的改进  
1. 设置一标志性变量pos,用于记录每趟排序中最后一次进行交换的位置。由于pos位置之后的记录均已交换到位,故在进行下一趟排序时只要扫描到pos位置即可。  
2. 利用在每趟排序中进行正向和反向两遍冒泡的方法一次可以得到两个最终值(最大者和最小者) , 从而使排序趟数几乎减少了一半  

## 快速排序 Quick Sort ##
基本思想：  
1. 选择一个基准元素,通常选择第一个元素或者最后一个元素
2. 通过一趟排序, 将待排序的记录分割成独立的两部分，其中一部分记录的元素值均比基准元素值小；另一部分记录的元素值比基准值大
3. 此时基准元素在其排好序后的正确位置
4. 分别对这两部分记录用同样的方法继续进行排序，直到整个序列有序

## 快速排序的改进 ##
只对长度大于k的子序列递归调用快速排序,让原序列基本有序，然后再对整个基本有序序列用插入排序算法排序。  
实践证明，改进后的算法时间复杂度有所降低，且当k取值为8左右时,改进算法的性能最佳  

# 4. 分配排序 #
## 归并排序 Merge Sort ##
基本思想：  
归并（Merge）排序法是将两个（或两个以上）有序表合并成一个新的有序表，即把待排序序列分为若干个子序列，每个子序列是有序的。然后再把有序子序列合并为整体有序序列。  

合并方法：  
设r[i…n]由两个有序子表r[i…m]和r[m+1…n]组成，两个子表长度分别为m-i+1和n-m  
1. j=m+1; k=i; i=i; //置两个子表的起始下标及辅助数组的起始下标
2. 若i>m 或j>n, 转4 //其中一个子表已合并完，比较选取结束
3. //选取r[i]和r[j]较小的存入辅助数组rf
  如果 r[i]<r[j], rf[k]=r[i]; i++; k++; 转2  
  否则 rf[k]=r[j]; j++; k++; 转2  
4. //将尚未处理完的子表中元素存入rf
  如果i<=m, 将r[i…m]存入rf[k…n] //前一子表非空  
  如果j<=n, 将r[j…n] 存入rf[k…n] //后一子表非空  
5. 合并结束

## 两路归并 ##
基本思想：  
1. 平分表，前后两部分, 分别进行归并排序  
2. 将两个表合并  

## 桶排序 ##
基本思想：  
将阵列分到有限数量的桶子里，每个桶子再个别排序（有可能再使用别的排序算法或是以递回方式继续使用桶排序进行排序）。  
桶排序是鸽巢排序的一种归纳结果。  
当要被排序的阵列内的数值是均匀分配的时候，桶排序使用线性时间(O(n)), 但桶排序并不是比较排序，他不受到 O(nlogn)下限的影响。  

简单来说，就是把数据分组，放在一个个的桶中，然后对每个桶里面的在进行排序。  
例如要对大小为[1..1000]范围内的n个整数A[1..n]排序  
1. 首先，可以把桶设为大小为10的范围，具体而言，设集合B[1]存储[1..10]的整数，集合B[2]存储(10..20]的整数，……集合B[i]存储((i-1)*10,i*10]的整数，i=1,2,..100。总共有100个桶  
2. 然后，对A[1..n]从头到尾扫描一遍，把每个A[i]放入对应的桶B[j]中
3. 再对这100个桶中每个桶里的数字排序，这时可用冒泡/选择/快排，一般来说,任何排序法都可以
4. 最后，依次输出每个桶里面的数字，且每个桶中的数字从小到大输出，这样就得到所有数字排好序的一个序列了
  
假设有n个数字，有m个桶，如果数字是平均分布的，则每个桶里面平均有n/m个数字。  
如果对每个桶中的数字采用快速排序，那么整个算法的复杂度是 O(n + m * n/m*log(n/m)) = O(n + nlogn-nlogm)  
  从上式看出，当m接近n的时候，桶排序复杂度接近O(n)  

当然，以上复杂度的计算是基于输入的n个数字是平均分布这个假设的。  
这个假设是很强的, 实际应用中效果并没有这么好。如果所有的数字都落在同一个桶中，那就退化成一般的排序了  

前面说的几大排序算法，大部分时间复杂度都是O(n2)，也有部分排序算法时间复杂度是O(nlogn)。而桶式排序却能实现O(n)的时间复杂度  
但桶排序的缺点是：  
1. 首先是空间复杂度比较高，需要的额外开销大
  排序有两个数组的空间开销，一个存放待排序数组，一个就是所谓的桶，比如待排序值是从0到m-1，那就需要m个桶，这个桶数组就要至少m个空间。  
2. 其次待排序的元素都要在一定的范围内

桶式排序是一种分配排序  
分配排序的特点是不需要进行关键码的比较，但前提是要知道待排序列的一些具体情况  

## 基数排序 Radix Sort ##
多次的桶式排序  

基数排序过程无须比较关键字，而是通过“分配”和“收集”过程来实现排序。  
时间复杂度可达到线性阶O(n)  

实例：  
扑克牌中52张牌，可按花色和面值分成两个字段，其大小关系为  
花色： 梅花 < 方块 < 红心 < 黑心  
面值： 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < 10 < J < Q < K < A  
即两张牌，若花色不同，不论面值怎样，花色低的那张牌小于花色高的，只有在同花色情况下，大小关系才由面值的大小确定。这就是多关键码排序。  

为得到排序结果，我们讨论两种排序方法：  
方法1：  
  先对花色排序，将其分为4个组，即梅花组、方块组、红心组、黑心组  
  再对每个组分别按面值进行排序，最后，将4个组连接起来即可  
方法2：  
  先按13个面值给出13个编号组(2号，3号，...，A号)，将牌按面值依次放入对应的编号组，分成13堆  
  再按花色给出4个编号组(梅花、方块、红心、黑心)，将2号组中牌取出分别放入对应花色组，再将3 号组中牌取出分别放入对应花色组，……，这样，4 个花色组中均按面值有序  
  然后，将4 个花色组依次连接起来即可  

两种多关键码排序方法：  
多关键码排序按照从最主位关键码到最次位关键码或从最次位到最主位关键码的顺序逐次排序，分两种方法：  
最高位优先(Most Significant Digit first)法，简称MSD法  
 1. 先按k1排序分组，将序列分成若干子序列，同一组序列的记录中，关键码k1相等
 2. 再对各组按k2排序分成子组，之后，对后面的关键码继续这样的排序分组，直到按最次位关键码kd对各子组有序
 3. 再将各组连接起来，便得到一个有序序列
扑克牌按花色、面值排序中介绍的方法一即是MSD 法  

最低位优先(Least Significant Digit first)法，简称LSD 法：
 1. 先从kd开始排序，再对kd-1进行排序，依次重复，直到按k1排序分组分成最小的有序列
 2. 最后将各个子序列连接起来，便可得到一个有序的序列
扑克牌按花色、面值排序中介绍的方法二即是LSD 法  

基于LSD方法的链式基数排序的基本思想：  
“多关键字排序”的思想实现“单关键字排序”。  
对数字型或字符型的单关键字，可以看作由多个数位或多个字符构成的多关键字，此时可以采用“分配-收集”的方法进行排序，这一过程称作基数排序法，其中每个数字或字符可能的取值个数称为基数  
比如，扑克牌的花色基数为4，面值基数为13。在整理扑克牌时，既可以先按花色整理，也可以先按面值整理。  
按花色整理时，先按红、黑、方、花的顺序分成4摞（分配），再按此顺序再叠放在一起（收集），然后按面值的顺序分成13摞（分配），再按此顺序叠放在一起（收集），如此进行二次分配和收集即可将扑克牌排列有序  

基数排序:  
是按照低位先排序，然后收集；  
再按照高位排序，然后再收集；  
依次类推，直到最高位。  
有时候有些属性是有优先级顺序的，先按低优先级排序，再按高优先级排序。  
最后的次序就是高优先级高的在前，高优先级相同的低优先级高的在前。  
基数排序基于分别排序，分别收集，所以是稳定的。  

```C
#include <QCoreApplication>
#include "qglobal.h"

#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <tr1/memory>
#include <algorithm>
#include <cassert>

using namespace std;

void PrintArray(const vector<int>& nums)
{
    for(size_t i=0; i<nums.size(); ++i){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

void SwapElement(vector<int>& nums, const size_t index1, const size_t index2)
{
    int temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
}

/***************************直接插入排序***************************/
void InsertSort(vector<int>& nums)
{
    //每轮for 新加入的元素记为哨兵
    //将比哨兵值大的元素后移 最后空出来的位置放置哨兵值

    for(size_t i=1; i<nums.size(); ++i){//start from index=1
        //set guard(哨兵)
        int guardIndex = i;
        const int guardValue = nums[i];

        //insert the guardValue into the proper position
        while(guardIndex>=1 && guardValue<nums[guardIndex-1]){
            nums[guardIndex] = nums[guardIndex-1];
            --guardIndex;
        }
        nums[guardIndex] = guardValue;
    }
}

/***************************希尔排序***************************/
void ShellInsertSort(vector<int>& nums, const int step)
{
    for(size_t i=step; i<nums.size(); i+=step){//start from index=step
        //set guard(哨兵)
        int guardIndex = i;
        const int guardValue = nums[i];

        //insert the guardValue into the proper position
        while(guardIndex>=step && guardValue<nums[guardIndex-step]){
            nums[guardIndex] = nums[guardIndex-step];
            guardIndex -= step;
        }
        nums[guardIndex] = guardValue;
    }
}

void ShellSort(vector<int>& nums)
{
    size_t step = nums.size()/2;
    while(step >= 1){//step = len/2 len/4 ... 1
        ShellInsertSort(nums, step);
        step /= 2;
    }
}

/***************************选择排序***************************/
size_t FindMinIndex(const vector<int>& nums, const size_t startIndex)
{
    size_t minIndex = startIndex;
    int minValue = nums[startIndex];
    for(size_t i=startIndex+1; i<nums.size(); ++i){
        if(minValue > nums[i]){
            minValue = nums[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void SelectionSort(vector<int>& nums)
{
    for(size_t i=0; i<nums.size(); ++i){
        //在[i, nums.size())范围内确定min 移动到i处
        size_t minIndex = FindMinIndex(nums, i);
        SwapElement(nums, minIndex, i);
    }
}

/***************************二元选择排序***************************/
void SortMaxMin(vector<int>& nums, size_t startIndex, size_t endIndex)
{
    //在[startIndex, endIndex)范围内确定min和max 分别移动到startIndex和endIndex-1
    int max = INT_MIN;
    size_t maxIndex;
    int min = nums[startIndex];
    size_t minIndex = startIndex;
    for(size_t i=startIndex; i<endIndex; ++i){
        if(max < nums[i]){
            max = nums[i];
            maxIndex = i;
        }else if(min > nums[i]){
            min = nums[i];
            minIndex = i;
        }
    }

    SwapElement(nums, startIndex, minIndex);
    SwapElement(nums, endIndex-1, maxIndex);
}

void DualSelectionSort(vector<int>& nums)
{
    for(size_t i=0; i<nums.size()/2; ++i){
        SortMaxMin(nums, i, nums.size()-i);
    }
}

/***************************堆排序***************************/
size_t GetLeftChildIndex(const size_t index)
{
    //完全二叉树 下标索引从1开始 则左子树的index=2*i
    //数组下标索引从0开始 则左子树的index=2*(i+1) -1
    return 2*(index+1)-1;
}

size_t GetRightChildIndex(const size_t index)
{
    //完全二叉树 下标索引从1开始 则左子树的index=2*i+1
    //数组下标索引从0开始 则左子树的index=2*(i+1)+1 -1
    return 2*(index+1);
}

int FindSmallerChildIndex(vector<int>& nums, const size_t heapLen, const size_t leftChildIndex, const size_t rightChildIndex)
{
    if(leftChildIndex>=heapLen && rightChildIndex>=heapLen){//两个子节点均越界 没有子节点
        return -1;
    }else if(leftChildIndex<heapLen && rightChildIndex>=heapLen){//有左子节点 没有右子节点
        return leftChildIndex;
    }else if(leftChildIndex>=heapLen && rightChildIndex<heapLen){//没有左子节点 有右子节点
        return rightChildIndex;
    }else{//两个子节点均存在 返回较小的子节点索引
        return nums[leftChildIndex]<nums[rightChildIndex]? leftChildIndex: rightChildIndex;
    }
}

void DownAdjustHeap(vector<int>& nums, const size_t heapLen, const size_t rootIndex)
{
    //将根结点与左、右子树中较小元素的进行交换
    const size_t leftChildIndex  = GetLeftChildIndex(rootIndex);
    const size_t rightChildIndex = GetRightChildIndex(rootIndex);

    int childIndex = FindSmallerChildIndex(nums, heapLen, leftChildIndex, rightChildIndex);
    if(childIndex == -1){//no valid child
        return;
    }

    if(nums[childIndex] < nums[rootIndex]){//小顶堆 左子树小需要处理
        SwapElement(nums, childIndex, rootIndex);
        return DownAdjustHeap(nums, heapLen, childIndex);
    }
}

void BuildHeap(vector<int>& nums)
{
    //n个结点的完全二叉树 则最后一个结点是第n/2个结点的子树(二叉树index从1开始)
    //对于数组 最后一个结点的父节点index=nums.size()/2 -1
    for(int i=nums.size()/2-1; i>=0; --i){//向上推进 直到根节点i=0
        DownAdjustHeap(nums, nums.size(), i);
    }
}

void HeapSort(vector<int>& nums)
{
    BuildHeap(nums);

    for(size_t i=0; i<nums.size(); ++i){//输出每次堆调整后的根元素(小顶堆 则输出的最小的数)
        //当前堆的大小(后面i个位置 存放每次输出的根元素)
        size_t heapLen = nums.size()-i;

        //输出堆顶元素 = 放入当前堆的最后位置
        SwapElement(nums, 0, heapLen-1);

        //向下调整 大小-1的堆
        DownAdjustHeap(nums, heapLen-1, 0);
    }
}

/***************************冒泡排序***************************/
void BubbleSort(vector<int>& nums)
{
    for(size_t i=0; i<nums.size(); ++i){
        for(size_t j=1; j<nums.size()-i; ++j){//index=1开始 后-前的比较; size()-i结束 后面i个存放了较大的数
            if(nums[j] < nums[j-1]){//后<前 进行交换(大的数向后下沉 小的数向前冒泡)
                SwapElement(nums, j, j-1);
            }
        }
    }
}

void BubbleSortWithPos(vector<int>& nums)
{
    for(size_t i=0; i<nums.size(); ++i){
        size_t swapPos = 0;//本轮冒泡排序 最后一次交换元素的位置(两相邻元素较后的位置)

        for(size_t j=1; j<nums.size()-i; ++j){//index=1开始 后-前的比较; size()-i结束 后面i个存放了较大的数
            if(nums[j] < nums[j-1]){//后<前 进行交换(大的数向后下沉 小的数向前冒泡)
                SwapElement(nums, j, j-1);
                swapPos = j;//记录
            }
        }

        if(swapPos != 0){//发生记录
            i = nums.size()-swapPos -1;//记录位置之后的元素均排序完成 i=已排序的元素个数-1(之后++i抵消这里的-1)
        }
    }
}

void BubbleSortTwoDirection(vector<int>& nums)
{
    size_t startIndex = 0, endIndex = nums.size();

    for(size_t i=0; i<nums.size()/2; ++i){//遍历长度/2 每次遍历下沉最大的+冒泡最小的
        for(size_t j=startIndex+1; j<endIndex; ++j){//startIndex+1首次能向前比较
            if(nums[j] < nums[j-1]){//后<前 进行交换(大的数向后下沉 小的数向前冒泡)
                SwapElement(nums, j, j-1);
            }
        }
        --endIndex;//最大的数下沉完成 endIndex-1

        for(size_t j=endIndex-1; j>=startIndex+1; --j){//startIndex+1末次能向前比较
            if(nums[j] < nums[j-1]){
                SwapElement(nums, j, j-1);
            }
        }
        ++startIndex;//最小的数冒泡完成 startIndex+1
    }
}

/***************************快速排序***************************/
void QuickSort(vector<int>& nums, const int startIndex, const int endIndex)
{
    //即挖坑填数排序
    //[startIndex, endIndex]

    //递归的基础情况 不需要调整
    if(startIndex >= endIndex){
        return;
    }

    //记录枢纽元
    int pivotIndex = startIndex;
    int pivotValue = nums[pivotIndex];

    int i=startIndex, j=endIndex;
    while(i < j){//大循环
        while(j > i){//j向前 寻找比枢纽元小的元素
            if(nums[j] < pivotValue){
                break;
            }
            --j;
        }
        if(j > i){//break out, rather than while out
            //枢纽元和j交换
            SwapElement(nums, pivotIndex, j);
            pivotIndex = j;
        }

        while(i < j){//i向后 寻找比枢纽元大的元素
            if(nums[i] > pivotValue){
                break;
            }
            ++i;
        }
        if(i < j){//break out, rather than while out
            //枢纽元和i交换
            SwapElement(nums, pivotIndex, i);
            pivotIndex = i;
        }
    }

    QuickSort(nums, startIndex, pivotIndex-1);
    QuickSort(nums, pivotIndex+1, endIndex);
}

/***************************改进的快速排序 配合插入排序***************************/
void QuickSortWithMinLen(vector<int>& nums, const int startIndex, const int endIndex, const int minLen)
{
    //即挖坑填数排序
    //[startIndex, endIndex]

    //递归的基础情况 不需要调整
    if(startIndex >= endIndex){
        return;
    }

    /* 相比快速排序所添加的 只对长度大于minLen的进行快速排序 */
    int localLen = endIndex-startIndex+1;
    if(localLen <= minLen){
        return;
    }

    //记录枢纽元
    int pivotIndex = startIndex;
    int pivotValue = nums[pivotIndex];

    int i=startIndex, j=endIndex;
    while(i < j){//大循环
        while(j > i){//j向前 寻找比枢纽元小的元素
            if(nums[j] < pivotValue){
                break;
            }
            --j;
        }
        if(j > i){//break out, rather than while out
            //枢纽元和j交换
            SwapElement(nums, pivotIndex, j);
            pivotIndex = j;
        }

        while(i < j){//i向后 寻找比枢纽元大的元素
            if(nums[i] > pivotValue){
                break;
            }
            ++i;
        }
        if(i < j){//break out, rather than while out
            //枢纽元和i交换
            SwapElement(nums, pivotIndex, i);
            pivotIndex = i;
        }
    }

    /* 相比快速排序所添加的 */
    QuickSortWithMinLen(nums, startIndex, pivotIndex-1, minLen);
    QuickSortWithMinLen(nums, pivotIndex+1, endIndex, minLen);
}

/***************************归并排序***************************/
void Merge(vector<int>& nums, vector<int>& numsResult, size_t i, size_t m, size_t n)
{
    //nums中的[i,n]区间数据 归并排序一次 到numsResult的[i,n]中
    //[i,n]的区间被分割为两个子表=[i~m]和[m+1~n]

    size_t i_result = i;

    size_t j = m+1;
    while(i<=m && j<=n){//子表均没有归并完毕
        //i和j中较小的放入numsResult
        if(nums[i] < nums[j]){//放入i
            numsResult[i_result++] = nums[i++];
        }else{//放入j
            numsResult[i_result++] = nums[j++];
        }
    }

    //有子表归并完毕 填充子表的剩余项
    while(i <= m){//填充i
        numsResult[i_result++] = nums[i++];
    }
    while(j <= n){//填充j
        numsResult[i_result++] = nums[j++];
    }
}

void MergeSort(vector<int>& nums, vector<int>& numsResult, const size_t mergeSize)
{
    //递归的基本情况
    //第一次Size超过, 仍然可以归并, 此时将归合并整个表
    //之后将不会再次递归return 不会继续归并合并
    bool finishMerge = false;
    if(mergeSize > nums.size()){
        finishMerge = true;
    }

    //[mergeStartIndex, mergeEndIndex]
    size_t mergeStartIndex = 0;
    size_t mergeEndIndex = mergeStartIndex+mergeSize-1;

    while(mergeEndIndex < nums.size()){//等长的两个子表合并=[start, middle] [middle+1, end]
        Merge(nums, numsResult, mergeStartIndex, (mergeStartIndex+mergeEndIndex)/2, mergeEndIndex);

        mergeStartIndex += mergeSize;
        mergeEndIndex += mergeSize;
    }

    mergeEndIndex -= mergeSize;//恢复到上一次合并后的end
    if(mergeEndIndex != nums.size()-1){//上一次end之后有剩余部分没有归并 则归并[start, middle] [middle+1, size()-1]这两个子表
        mergeEndIndex = nums.size()-1;
        Merge(nums, numsResult, mergeStartIndex, (mergeStartIndex+mergeEndIndex)/2, mergeEndIndex);
    }

    nums = numsResult;//归并结果放回原始nums
    PrintArray(nums);

    if( !finishMerge ){//没结束 继续递归
        return MergeSort(nums, numsResult, mergeSize*2);//递归表的大小2次方增加
    }
}

void DualMergeSort(vector<int>& nums, vector<int>& numsResult, const size_t startIndex, const size_t endIndex)
{
    //递归基本情况
    if(endIndex-startIndex <= 1){
        Merge(nums, numsResult, startIndex, startIndex, endIndex);
        return;
    }

    //双路递归
    size_t middleIndex = (startIndex+endIndex)/2;
    DualMergeSort(nums, numsResult, startIndex, middleIndex);
    DualMergeSort(nums, numsResult, middleIndex+1, endIndex);
    //双路递归后的结果在numsResult 对numsResult进行整体的归并
    Merge(numsResult, nums, startIndex, middleIndex, endIndex);

    //存放递归结果
    numsResult = nums;
}

/***************************桶排序***************************/
size_t FindBucketIndex(const int num, const int min, const int max, const size_t bucketNum)
{
    //num应当落入那个桶
    //桶的分配: min~max 均分bucketNum个桶
    const int minMaxLen = max-min+1;
    const int bucketCapacity = minMaxLen / (minMaxLen%bucketNum==0? bucketNum: bucketNum-1);//不能整除 最后一个桶需要预留放余数部分
    return (num-min)/bucketCapacity;
}

void BucketSort(vector<int>& nums, const int min, const int max, const size_t bucketNum)
{
    vector<vector<int> > buckets;
    buckets.resize(bucketNum);

    //遍历nums 将每个元素放入合适的桶中
    for(size_t i=0; i<nums.size(); ++i){
        size_t bucketIndex = FindBucketIndex(nums[i], min, max, bucketNum);
        buckets[bucketIndex].push_back( nums[i] );
    }

    //对每个桶 内部进行排序
    for(size_t i=0; i<bucketNum; ++i){
        QuickSort(buckets[i], 0, buckets[i].size()-1);
    }

    //按序输出每个桶的结果
    size_t elementIndex = 0;
    for(size_t i=0; i<bucketNum; ++i){
        for(size_t j=0; j<buckets[i].size(); ++j){//每个桶i
            nums[elementIndex++] = buckets[i].at(j);
        }
    }
}

/***************************基于LSD(最低位优先)方法的链式基数排序***************************/
typedef vector<int> poker_t;//vector保存其优先级从低到高的关键码值 eg. [A, 红桃] [Q, 方块]

void PrintPokers(const vector<poker_t>& pokers)
{
    for(size_t i=0; i<pokers.size(); ++i){
        std::cout<<"[";
        for(size_t j=0; j<pokers[i].size(); ++j){
            std::cout<< pokers[i][j]<<",";
        }
        std::cout<<"]"<<std::endl;
    }
    std::cout<<std::endl;
}

int GetKeyValue(const poker_t& onePoker, const size_t keyIndex)
{
    //返回第keyIndex优先级的关键码值
    return onePoker[keyIndex];
}

void InitPokers(vector<poker_t>& pokers)
{
    for(int i=12; i>=0; --i){//逆序的面值
        for(int j=3; j>=0; --j){//逆序的花色
            poker_t onePoker;//面值-花色 低优先级的在前(低优先级优先排序 LSD)
            onePoker.push_back(i);
            onePoker.push_back(j);

            pokers.push_back( onePoker );
        }
    }

    std::cout<<"init pokers"<<std::endl;
    PrintPokers(pokers);
}

void LsdRadixSort(vector<poker_t>& pokers, vector<int> keyRange)//keyRange 每个关键码的取值范围 [0, keyRange[i])
{
    if(pokers.size() <= 1){//empty or only one poker
        return;
    }

    //keyRange.size()=多少个关键码
    for(size_t keyIndex=0; keyIndex<keyRange.size(); ++keyIndex){//每个关键码 进行一次分配+收集
        const size_t range = keyRange[keyIndex];//该关键码的取值范围
        vector<poker_t> buckets[range];//构造存放每个关键码对应元素的桶

        //分配
        for(size_t i=0; i<pokers.size(); ++i){//遍历扑克 分别放入对应的桶
            int keyValue = GetKeyValue(pokers[i], keyIndex);//该扑克的第keyIndex个关键码的值
            buckets[keyValue].push_back( pokers[i] );
        }
        //收集
        size_t pokersIndex = 0;
        for(size_t i=0; i<range; ++i){//遍历每个桶
            for(size_t j=0; j<buckets[i].size(); ++j){//每个桶的数据 按序放回pokers
                pokers[pokersIndex++] = buckets[i].at(j);
            }
        }
    }
}


void TestFunc()
{
    const int array[] = {49, 38, 65, 97, 76, 13, 27, 49, 22, 123, 12, 100, 38, 5, 13};
    //const int array[] = {49, 38, 65, 97, 76, 13, 27};
    const size_t arrayLen = sizeof(array)/sizeof(array[0]);
    vector<int> nums(array, array+arrayLen);

    //InsertSort(nums);

    //ShellSort(nums);

    //SelectionSort(nums);

    //DualSelectionSort(nums);

    //HeapSort(nums);

    //BubbleSort(nums);

    //BubbleSortWithPos(nums);

    //BubbleSortTwoDirection(nums);

    //QuickSort(nums, 0, nums.size()-1);

    //QuickSortWithMinLen(nums, 0, nums.size()-1, 8);
    //InsertSort(nums);

    //vector<int> numsResult(nums.size(), 0);
    //MergeSort(nums, numsResult, 2);
    //PrintArray(numsResult);

    //vector<int> numsResult(nums.size(), 0);
    //DualMergeSort(nums, numsResult, 0, nums.size()-1);
    //PrintArray(numsResult);

    //BucketSort(nums, 5, 123, 10);

    //std::cout<<"final result="<<std::endl;
    //PrintArray(nums);

    //LsdRadixSort
    std::vector<poker_t> pokers;
    InitPokers(pokers);
    vector<int> keys;
    keys.push_back(13);//面值有13个取值
    keys.push_back(4);//花色有4个取值
    LsdRadixSort(pokers, keys);
    std::cout<<"finial pokers"<<std::endl;
    PrintPokers(pokers);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestFunc();

    return a.exec();
}

```
