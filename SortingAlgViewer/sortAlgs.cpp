#include "sortAlgs.h"


//Merge sort implementation
void MergeSort::merge(std::vector<listElement>::iterator begin, std::vector<listElement>::iterator mid, std::vector<listElement>::iterator end)
{
    auto leftArray = std::vector<listElement>(begin, mid),
        rightArray = std::vector<listElement>(mid, end);
    
    auto leftIter = leftArray.begin(),
        rightIter = rightArray.begin();


    
    while (leftIter != leftArray.end() && rightIter != rightArray.end()) {
        if (*leftIter < *rightIter) {
            begin->setValue(leftIter->getValue());
            leftIter++;
        }
        else {
            begin->setValue(rightIter->getValue());
            rightIter++;
        }
        begin++;
        std::this_thread::sleep_for(std::chrono::milliseconds(8));
    }
    while (leftIter != leftArray.end()) {
        begin->setValue(leftIter->getValue());
        leftIter++;
        begin++;
    }
    while (rightIter != rightArray.end()) {
        begin->setValue(rightIter->getValue());
        rightIter++;
        begin++;
    }
    
}
void MergeSort::split(std::vector<listElement>::iterator begin, std::vector<listElement>::iterator end){
    if (begin->getIndex() == (end-1)->getIndex())
        return; // Returns recursively
   
    auto mid = begin+((end-begin)/2);

    split(begin, mid);
    split(mid, end);
    merge(begin, mid, end);
}
void MergeSort::mergeSort(std::vector<listElement>& array) {
    if (std::is_sorted(array.begin(), array.end())) return;
    split(array.begin(), array.end());
}

//Selection sort implementation
void SelectionSort::selectionSort(std::vector<listElement>& array) {
    if (std::is_sorted(array.begin(), array.end())) return;
    for (auto insIter = array.begin(); insIter < array.end(); insIter++) {
        auto minIter = insIter;
        for (auto sIter = insIter; sIter < array.end(); sIter++) {
            if (sIter->getValue() < minIter->getValue()) {
                minIter = sIter;
            }
        }
        //std::iter_swap(minIter, insIter);
        (*minIter).swap(*insIter);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

//Insertion sort implementation
void InsertionSort::insertionSort(std::vector<listElement>& array) {
    if (std::is_sorted(array.begin(), array.end())) return;
    for (int curr = 0; curr < array.size(); curr++) {
        for (int ins = 0; ins < curr; ins++) {
            if (array[curr] < array[ins]) {
                auto tmp1 = array[ins].getValue(), tmp2=array[ins+1].getValue();
                array[ins].setValue(array[curr].getValue());
                for (int i = ins+1; i <= curr; i++) {
                    array[i].setValue(tmp1);
                    tmp1 = tmp2;
                    if(i<array.size()-1)
                        tmp2 = array[i + 1].getValue();
                    
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::nanoseconds(700));
    }
}

//Heap sort implementation
void HeapSort::heapSort(std::vector<listElement>& array) {
    std::make_heap(array.begin(), array.end());
    int i = 0;
    for (auto& e : array) {
        e.setIndex(i++);
        std::this_thread::sleep_for(std::chrono::nanoseconds(100));
    }
    std::vector<listElement> cpy(array);
    for (auto iter = array.rbegin(); iter != array.rend(); iter++) {
        (*iter).setValue(cpy[0].getValue());
        std::pop_heap(cpy.begin(), cpy.end());
        cpy.pop_back();
        std::this_thread::sleep_for(std::chrono::nanoseconds(1000));
    }
}