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

#### Hash Table

An array with fixed size: *arraySize*. 

Note. Might need to store the key and value together in the table for check-ups due to collision.


#### Hash Function

A typical hash function with integer key is:



* Good Hash Function

	1. Distribute keys uniformly over all table indices. This means *arraySize* should 
be a **prime** number to minimize collision.
	2. Fast to compute

* Hash Function for String keys

	- Add up character ASCII values (0-255) for all letters to produce integer keys

		Potential Problems:
		* Anagrams would have collisions
		* Lookup time proportional to string length
		
	- Use all N letters of string as an **N-digit base-K** number

		Let K be a number larger than 27 and be a prime number: 29, 31, 37.
		
		**h(S)=\sum_{i=0}^{L-1} S[L-1-i]*K^{i}**
		
		Limit L < N for long strings.
		


	


### Applications of Hash Table

* Accessing Tree/Graph Nodes by Name (the value stores the physical address)
* Dictinary Lookup (Spell Check, but inefficient for auto correction)



[1]: http://www.cplusplus.com/reference/algorithm/make_heap/
[2]: http://www.cplusplus.com/reference/algorithm/push_heap/
[3]: http://www.cplusplus.com/reference/algorithm/pop_heap/


