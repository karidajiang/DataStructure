
Linked List Implementation in C++ 
------------

### BackGround

Objects in linked list are arranged in a linear order connected through pointers. There are several forms 
of linked list:

* Singly/Doubly linked
* Sorted/Unsorted
* Circular/Not circular


C++ provides a linked list implementation: [list][3]. An example for usage:

~~~

   list<int> L;
   L.push_back(0);              // Insert a new element at the end
   L.push_front(0);             // Insert a new element at the beginning
   L.insert(++L.begin(),2);     // Insert "2" at ++L.begin()

   L.push_back(5);
   L.push_back(6);
 
   list<int>::iterator i;

   for(i=L.begin(); i != L.end(); ++i) cout << *i << " ";
   cout << endl;

~~~


#### Memory Storage

Data items need not be stored contiguously in memory or on disk.


#### Sentinel nodes

* An extra sentinel or dummy node 
* May be added before the first data record and/or after the last one
* Simplifies and accelerates some list-handling algorithms
* Ensures all links to be safely dereferenced and every list always has a "first" and/or "last" node


#### Pros

1. Elements can easily be inserted or removed at any point in the list without reallocation or reorganization (as in Dynamic Array)
2. An arbitrary number of elements can be inserted/removed 
3. Operations can be in constant time if the pointer of the previous action is stored

#### Cons

1. Unsuitable for applications where you need to look up an element *by its index* quickly (since normally it requires a scan)

2. Slower than Array/Dynamic Arrays for **sequential access** due to array's compact storage(cache)

3. **Extra storage** needed for references, often impractical for lists of small data items (characters/boolean),
 because the storage overhead for the links may exceed by a factor of two or more over the size of the data.
	
4. Compared to a **Balanced Tree**, they have similar access patterns and space overhead. However, tree is more
efficient for a random access with O(logN) whereas linked list requires O(N). However, insertion/deletion might
cause extra work for trees to maintain its balance	



### Applications of Linked List

* Might be used to implement [Stack][1] and [Queue][2]
* Circular Linked List


[1]: http://en.wikipedia.org/wiki/Stack_(abstract_data_type)
[2]: http://en.wikipedia.org/wiki/Queue_(abstract_data_type)
[3]: http://www.cplusplus.com/reference/list/list/list/


