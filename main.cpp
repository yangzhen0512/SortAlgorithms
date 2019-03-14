#include <vector>
#include <iostream>

#define UNUSED(x) (void)x

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

int main(int argc, char *argv[])
{
    //消除编译器警告
    UNUSED(argc);
    UNUSED(argv);

    /*************以下为各种排序算法*************/
    enum SortAlgorithm{
        InsertSorting,
        ShellSorting,
        SelectionSorting,
        DualSelectionSorting,
        HeapSorting,
        BubbleSorting,
        BubbleSortingWithPos,
        BubbleSortingTwoDirection,
        QuickSorting,
        QuickSortingWithMinLen,
        MergeSorting,
        DualMergeSorting,
        BucketSorting,
        LsdRadixSorting
    };
    int sortType = LsdRadixSorting;//指定使用的算法

    //构造待排序的数据
    const int array[] = {49, 38, 65, 97, 76, 13, 27, 49, 22, 123, 12, 100, 38, 5, 13};
    const size_t arrayLen = sizeof(array)/sizeof(array[0]);
    vector<int> nums(array, array+arrayLen);

    switch(sortType){
    case InsertSorting:
        InsertSort(nums);
        PrintArray(nums);
        break;
    case ShellSorting:
        ShellSort(nums);
        PrintArray(nums);
        break;
    case SelectionSorting:
        SelectionSort(nums);
        PrintArray(nums);
        break;
    case DualSelectionSorting:
        DualSelectionSort(nums);
        PrintArray(nums);
        break;
    case HeapSorting:
        HeapSort(nums);
        PrintArray(nums);
        break;
    case BubbleSorting:
        BubbleSort(nums);
        PrintArray(nums);
        break;
    case BubbleSortingWithPos:
        BubbleSortWithPos(nums);
        PrintArray(nums);
        break;
    case BubbleSortingTwoDirection:
        BubbleSortTwoDirection(nums);
        PrintArray(nums);
        break;
    case QuickSorting:
        QuickSort(nums, 0, nums.size()-1);
        PrintArray(nums);
        break;
    case QuickSortingWithMinLen:
        QuickSortWithMinLen(nums, 0, nums.size()-1, 8);
        InsertSort(nums);
        PrintArray(nums);
        break;
    case MergeSorting:
        do{
            vector<int> numsResult(nums.size(), 0);
            MergeSort(nums, numsResult, 2);
            PrintArray(numsResult);
        }while(0);
        break;
    case DualMergeSorting:
        do{
            vector<int> numsResult(nums.size(), 0);
            DualMergeSort(nums, numsResult, 0, nums.size()-1);
            PrintArray(numsResult);
        }while(0);
        break;
    case BucketSorting:
        BucketSort(nums, 5, 123, 10);
        PrintArray(nums);
        break;
    case LsdRadixSorting:
        do{
            std::vector<poker_t> pokers;
            InitPokers(pokers);
            vector<int> keys;
            keys.push_back(13);//面值有13个取值
            keys.push_back(4);//花色有4个取值
            LsdRadixSort(pokers, keys);

            std::cout<<"finial pokers"<<std::endl;
            PrintPokers(pokers);
        }while(0);
        break;
    }

    return 0;
}
