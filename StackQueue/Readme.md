
Stack & Queue 
------------

**Stack**: Last In First Out. Main Functions: 

* push()
* pop()
* peek()

**Queue**: First In First Out. Main Functions:

* enqueue()
* dequeue()
* peek()

Stacks and Queues can be implemented by Linked List or (dynamic)arrays in the common case. In addition, 
it might be possible to implement [stack by two queues][1], or [queue by two stacks][2]. 

## Stack

In C++, there is this STL implementation of [stack][3], whose sample code is as follows.

~~~
  #include <stack>          // std::stack

  std::stack<int> mystack;

  for (int i=0; i<5; ++i){ 
  	mystack.push(i);
  }

  std::cout << "Popping out elements...";
  
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';

~~~


### Memory Storage

Depending on its implementation, whether it is on Linked list or Array. 

### [Applications of Stack][4]

* Convert a decimal number into a binary number **Reverse the Order**

	1. Read a number
	2. Iteration (while number is greater than zero)
		Find out the remainder after dividing the number by 2
		Print the remainder
		Divide the number by 2
	3. End the iteration 
	
	In this iteration, however, we will get the least significant digit first. 13(Base10) should be 1101(base2),
	but we would get 1,0,1,1 as a naturl order from the algorithm. Therefore, we could use a stack to store all 
	the digits as we obtain them from step 2, and pop all digits at the end for display.
	
* Towers of Honoi  **Towers -> stack** && **Recursion is using the memory stack!**

	For example, if there are three towers, a recursion solution is:
	
	~~~
	void TowersofHanoi(int n, int a, int b, int c)
	{
	    if(n > 0)
	    {
	        TowersofHanoi(n-1, a, c, b);   //recursion
	        printf("> Move top disk from tower %d to tower %d.\n", a, b);
	        TowersofHanoi(n-1, c, b, a);   //recursion
	    }
	}
	~~~
	
* [Expression evaluation and syntax parsing][5]
	
	There are three types of expressions: **inflix**,**prefix**,**postfix** expressions. 
	
	1. Inflix Expression 
	
		-Fully parenthesized: (((2 * 5) - (1 * 2)) / (11 - 9)) 
		-Not fully parenthesized (need priority between operators): (2 * 5 - 1 * 2) / (11 - 9)
		
	2. Preix Expression
	
		/ - * 2 5 * 1 2 - 11 9 should yield:
		 
		(11-9) = 2;
		(1*2) = 2;
		(2*5) = 10;
		(10-2) = 8;
		(8/2) = 4;
		
		The expression is evaluated **from right to left** using a stack:
		1. Read one character input one-by-one and push it into the **character stack** until new line 
   		2. Pop from the **character stack** until empty:
   		
      		-Number                        Push into the **integer stack** 
      		-Operator                      Assign the operator to op,
                                           Pop a number from  **integer stack** -> op1.
                                           Pop another number from **integer stack** ->op2.                            
                                           Calculate op1 op op2.
										   Push the output into the **integer stack**.                                   
   		3. Pop the result from **integer stack** and display 
		
	3. Postfix Expression
		1 2 4 * + 3 + should yield:
		(2*4) = 8;
		(1+8) = 9;
		(9+3) = 12;
		
		The expression is evaluated **from left to right** using a stack:
		1. when encountering an operand: push it
		2. when encountering an operator: pop two operands, evaluate the result and push it.
		
	
* Backtracking

	Consider a simple example of finding the correct path in a maze. With the help of stacks,
	we remember the point where we have reached. 

* QuickSort 

	Use two stacks to store the current lowerbounds and upperbounds. [TODO][6]

* Runtime memory management for Programming Languages (e.g. C)


## Queue

In C++, there is this STL implementation of [queue][7], whose sample code is as follows.

~~~
  #include <queue>          // std::queue

  std::queue<int> myqueue;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";
  do {
    std::cin >> myint;
    myqueue.push (myint);
  } while (myint);

  std::cout << "myqueue contains: ";
  while (!myqueue.empty())
  {
    std::cout << ' ' << myqueue.front();
    myqueue.pop();
  }
  std::cout << '\n';

~~~


### Memory Storage

Commonly implemented in an Linked list. 

### Applications of Queue

* Mostly used in operating systems

	-Scheduling of processes

[1]: http://stackoverflow.com/questions/688276/implement-stack-using-two-queues
[2]: http://stackoverflow.com/questions/69192/how-to-implement-a-queue-using-two-stacks
[3]: http://www.cplusplus.com/reference/stack/stack/pop/
[4]: http://en.wikipedia.org/wiki/Stack_(abstract_data_type)#Applications
[5]: http://en.wikipedia.org/wiki/Stack_(abstract_data_type)#Expression_evaluation_and_syntax_parsing
[6]: http://en.wikipedia.org/wiki/Stack_(abstract_data_type)#Quicksort
[7]: http://www.cplusplus.com/reference/queue/queue/push/


