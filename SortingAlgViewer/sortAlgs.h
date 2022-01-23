#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include "listElement.h"


namespace MergeSort {
	void merge(std::vector<listElement>::iterator begin, std::vector<listElement>::iterator mid, std::vector<listElement>::iterator end);
	void split(std::vector<listElement>::iterator begin, std::vector<listElement>::iterator end);
	void mergeSort(std::vector<listElement>& array);
}

namespace SelectionSort {
	void selectionSort(std::vector<listElement>& array);
}

//Insertion sort gets a bad rep here
//The contiguous storage nature of vectors makes it hard to insert elements in between others
//Insertion sort is much faster on data structures better suited to it
namespace InsertionSort {
	void insertionSort(std::vector<listElement>& array);
}

namespace QuickSort {
	void quickSort(std::vector<listElement>& array);
}

namespace BubbleSort {
	void bubbleSort(std::vector<listElement>& array);

}

namespace HeapSort {
	void heapSort(std::vector<listElement>& array);
}

namespace RadixSort {
	void radixSort(std::vector<listElement>& array);
}

namespace BucketSort {
	void bucketSort(std::vector<listElement>& array);
}