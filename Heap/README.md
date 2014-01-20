Heap Implementation in C++ 
------------

### BackGround
Heap is available in the Standard Template Library (STL) algorithms. It operates on a container like a vector by the function calls: [make_heap][1], [push_heap][2] and [pop_heap][3] functions. An example is as follows:

~~~ cpp
// range heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap

#include <vector>       // std::vector

int main () {
	
	  int myints[] = {10,20,30,5,15};
	  std::vector<int> v(myints,myints+5);
	
	  std::make_heap (v.begin(),v.end());
	  std::cout << "After make_heap():";
	  for (unsigned i=0; i<v.size(); i++)
		  std::cout << ' ' << v[i];
	  std::cout<<std::endl;
	  
	  std::cout << " with max heap: " << v.front() << '\n';
	
	  std::pop_heap (v.begin(),v.end()); 
	  std::cout << "After pop_heap():";
	  for (unsigned i=0; i<v.size(); i++)
		  std::cout << ' ' << v[i];
	  std::cout<<std::endl;
	  
	  // now the maximum value just been popped is placed at the back
	  v.pop_back();
	  std::cout << "max heap after pop : " << v.front() << '\n';
	
	  // push the new value from the back
	  v.push_back(99); 
	  // inform the heap that new value has been pushed in
  	  // NOTE!! Only the last element in the vector will be processed
	  std::push_heap (v.begin(),v.end());
	  v.push_back(3);
	  std::push_heap (v.begin(),v.end());
	  v.push_back(19);
	  std::push_heap (v.begin(),v.end());
	  
	  std::cout << "max heap after push: " << v.front() << '\n';
	
	  // sort the heap 
	  std::sort_heap (v.begin(),v.end());
	
	  std::cout << "final sorted range :";
	  for (unsigned i=0; i<v.size(); i++)
	    std::cout << ' ' << v[i];
	
	  std::cout << '\n';

  return 0;
}
~~~

The output is:

~~~
After make_heap(): 30 20 10 5 15
 with max heap: 30
After pop_heap(): 20 15 10 5 30
max heap after pop : 20
max heap after push: 99
final sorted range : 3 5 10 15 19 20 99
~~~



### Heap Data Structure

Consists of:

1. ***Heap Properties***
2. ***Building a Heap from Array***
3. ***Insert***
4. ***Delete***

#### Heap Properties

* Nearly Complete Binary Tree
* If ***index from 1***, the array holding the heap will have the following property:

	- Parent(i) : ***floor(i/2.0)***
	- LeftChild(i): ***2i***
	- RightChild(i): ***2i+1***
	
	Note. These operations can be done by bit-manipulation
	
* Max-Heap: for i > 1 (not including the root) , we have A[parent(i)] >= A[i]. A\[1\] is the maximum element in the array.
* Min-Heap: for i > 1 (not including the root) , we have A[parent(i)] <= A[i] 
* Height of the heap: theta(logN)


#### Building a Heap from Array

* An array A can represent a heap with two attributes:
1. A.length representing the total length of the array
2. A.heapsize representing how many elements belongs to the heap A[1...A.heapsize]

* Basic operations on A

1. ***MAX-HEAPIFY(A, i)*** assuming the trees rooted at ***LEFT(I) & RIGHT(I) are valid Max-Heap***. Takes O(lgN) time.
	Note. When moving down A[i], should exchange it with max(LEFT(i), RIGHT(i)) to maintain heap property

2. ***BUILD-MAX-HEAP(A)*** produce a max-heap from an un-sorted input array. Takes O(N) time
	- build the heap from the bottom-up fashion
	- A[(floor(N/2))+1, ..., N] are all the leaves of the heap, therefore we only start at the non-leaves
	- A.heapsize = A.length
	- ***For i in floor(N/2) down to 1:***
		MAX-HEAPIFY(A,i);
	- Note. this is important to build the heap from ***bottom-up*** because it will move the bigger nodes upwards!!
	- The upper bound is O(NlogN), however, it is not asymptotically tight. Note that for the leaf level of the heap, it can has at most floor(N/2), which all have height 0. For the nodes with height 1, it can have at most floor(N/2^2) nodes, if you consider the heap built from A[1...N/2] and apply the leaf-level-node again. Thus, for a given height, it can have at most floor(N/2^(h+1)) nodes. 
	- Run time: \sum_{h=0}^{logN} h \cdot N/2^{h+1} = N \cdot \sum_{h=0}^{logN} h/2^{h+1} = O(N)
	

3. ***HEAPSORT(A)*** sort the array in place. Takes O(NlogN) time
	- First, build the heap from array A: BUILD-MAX-HEAP(A)
	- Exchange A\[1\] with A\[n\], reduce A.heapsize by 1
	- Call MAX-HEAPIFY(A, 1)
	- iterate the previous two steps until A.heapsize = 1
	- Now the array A is sorted in an increasing order

4. Implement a ***max-priority queue*** using Heap -  MAX-HEAP-INSERT, HEAP-EXTRACT-MAX, HEAP-INCREASE-KEY,
and HEAP-MAXIMUM, all execute in ***O(logN)*** time.
	- HEAP-MAXIMUM returns A[1] in O(1) time
	- HEAP-EXTRACT-MAX runs in O(logN) time:
		* If heapsize < 1, return error;
		* max = A[1]
		* A[1] = A[heapsize]
		* heapsize--;
		* MAX_HEPIFY(A, 1)
	- HEAP-INCREASE-KEY(i, keyValue) increase the key for position i to keyValue:
		* ***If keyValue < A[i], return error;***
		* A[i] = keyValue;
		* While(i>1 && A[i]>A[parent] ): exchange A[i] & A[parent], i = parent
	- MAX-HEAP-INSERT(keyValue):
		* heapsize++
		* A[heapsize] = -inf.
		* HEAP-INCREASE-KEY(heapsize, keyValue)





### Applications of Hash Table

* Priority Queue Implementation



[1]: http://www.cplusplus.com/reference/algorithm/make_heap/
[2]: http://www.cplusplus.com/reference/algorithm/push_heap/
[3]: http://www.cplusplus.com/reference/algorithm/pop_heap/


