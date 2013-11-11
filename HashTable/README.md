
HashMap Implementation in C++ 
------------

### BackGround
hash_map is not included in the C++ standard library. It is a class in
the Standard Template Library (STL) and there are several implementations of it,
includeing MSVC++ and GCC. In C++11, there is this [std::unordered_map][1] which
serves similarly to HashMap in Java.

Note. C++ [STL][2] is not the same as C++ [Standard Library][3]! 

#### STL

* A C++ library of container classes, algorithms, and iterators
* Provides many of the basic algorithms and data structures 
* A generic library: its components are heavily parameterized that almost every component in the STL 
 is a template

#### STD

* A collection of classes and functions, which are written in the core language and part of the C++ ISO Standard itself
* Declared within the **std** namespace
* Based upon conventions introduced by the Standard Template Library (STL)
* Although STD and STL share many features, neither is a strict superset of the other

### HashMap Features

Consists of:

1. **Key**
2. **Hash Function**
3. **Hash Table**

#### Hash Function

A typical hash function with integer key is:
$$Index = h(key)%array_size$$, where *array_size* is the fixed size of the array as Hash Table.
**h(key)** maps key to interger in range [0, *array_size*-1], which might be 
a *many-to-one* mapping. 

* Good Hash Function

> 1. Distribute keys uniformly over all table indices. This means *array_size* should 
be a **prime** number to minimize collision.
> 2. Fast to compute

* Hash Function for String keys

	- Add up character ASCII values (0-255) for all letters to produce integer keys

		Potential Problems:
		* Anagrams would have collisions
		* Lookup time proportional to string length
		
	- Use all N letters of string as an **N-digit base-K** number

		Let K be a number larger than 27 and be a prime number: 29, 31, 37.
		
		$h(S) = \sum_{i=0}^{L-1} S[L-1-i]*K^{i}$
		
		Limit L < N for long strings.
		
		The equation {$ x^2 + y^2 = z^2 $} is really interesting!

#### Collision

Let $\phi$ be the load factor, which represents the average number of elements at each
hash table index. By default, $\phi$ should be around 0.75 before the hash table is 
resized.

- Chaining

	Store colliding keys in a linked list at the same hash table index. Unsuccessul Search
	and Insert would run in **O($\phi$)** time. Successful search finish in **O($\phi$/2)** time.
	
	Potential Problem:
	
	* Linked list could get long and result in O(N) time for a bad hash function

- Open Addressing

When collision occurs, look elsewhere in the table for an empty slot.




#### Hash Table

An array with fixed size: *array_size*. 

Note. Might need to store the key and value together in the table for check-ups due to collision.







#### Pros

1. ***Fast Insert and Search*** in on average constant time ***O(1)***, Delete might degrade performance (if Open-Addressing, it destroys the probing)
2. Commonly used in applications


#### Cons

1. **NOT** useful if want to maintain some kind of order among elements. Neither can you measure how "close" two keys are
> For example, **Tries** is better for auto-correction than HashMap 
 

### Applications of Hash Table

* Accessing Tree/Graph Nodes by Name (the value stores the physical address)
* Dictinary Lookup (Spell Check, but inefficient for auto correction)



~~~
define foobar() {
    print "Welcome to flavor country!";
}
~~~

[1]: http://www.cplusplus.com/reference/unordered_set/unordered_set/
[2]: http://www.sgi.com/tech/stl/stl_introduction.html
[3]: http://en.wikipedia.org/wiki/C++_Standard_Library

