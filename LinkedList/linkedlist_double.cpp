#include <iostream>
#include <math.h> 
using namespace std;


/**
 * Should have an individual class for Node.
 * 
 * Do NOT mix up Linkedlist data structure and Node
 */
template <class TypeElement>
class listNode{
public:
	TypeElement data;
	listNode * prev;
	listNode * next;

	listNode(const TypeElement &x){
		data = x;
		prev = NULL;
		next = NULL;
	}
};

template <class TypeElement>
class LinkedList{
	
	// used for insertion in front
	listNode<TypeElement> * head;
	// used for insertion from back
	listNode<TypeElement> * tail;
	int num_element;
	
public:
	LinkedList(){
		head = NULL;
		tail = NULL;
		num_element = 0;
	}
	
	
	// default behavior: insert in front
	void insert(const TypeElement & x){
		listNode<TypeElement> * newNode = new listNode<TypeElement>(x);
		newNode->next = head;
		newNode->prev = NULL;
		if(head != NULL){
			head->prev = newNode;
		}
		else{
			// head is NULL, it is currently an empty list
			tail = newNode;
		}
		
		head = newNode;
		num_element++;
	}
	
	
	// insert by appending to the back of the list
	void insert_back(const TypeElement & x){
		listNode<TypeElement> * newNode = new listNode<TypeElement>(x);
		newNode->prev = tail;
		newNode->next = NULL;
		if(tail != NULL){
			tail->next = newNode;
		}
		else{
			// tail is NULL, it is currently an empty list
			head = newNode;
		}
		tail = newNode;
		num_element++;
	}
	
	
	bool contains(const TypeElement & x) const{
		listNode<TypeElement> * first = head;
		listNode<TypeElement> * last = tail;
		
		// search by moving inwards from the two ends
		// NOTE. here should use /2.0 to avoid integer devision!
		for(int i=0; i<ceil(num_element/2.0); i++){
			if(first->data == x || last->data == x){
				return true;
			}
			else{
				first = first->next;
				last = last->prev;
			}
		}
		
		return false;
	}
	
	
	// default behavior: search from head and remove when found
	bool remove(const TypeElement & x){
		
		if(isEmpty()){
			return false;
		}
		
		listNode<TypeElement> * first = head;
		while(first != NULL){
			if(first->data == x){
				// need to delete the current node
				listNode<TypeElement> * tmp = first;
				
				if(first->prev != NULL){
					first->prev->next = first->next;
				}else{
					// this is the first element
					head = first->next;
				}
				
				if(first->next != NULL){
					first->next->prev = first->prev;
				}else{
					// this is the last element
					tail = first->prev;
				}
				delete tmp;
				num_element--;
				return true;
			}
			first = first->next;
		}
		
		// do not find this element
		return false;
	}
	
	
	bool isEmpty(){
		return (head == NULL && tail == NULL);
	}
	
	void print(){
		if(isEmpty()){
			cout<<"Empty List"<<endl;
		}
		else{
			listNode<TypeElement> * tmp = head;
			while(tmp != NULL){
				cout<<tmp->data<<"->";
				tmp = tmp->next;
			}
			cout<<"==>"<<num_element<<" elements"<<endl;
		}
	}
	
	
};



int main(){
	
	//Empty
	LinkedList<string> mylist = LinkedList<string>();
	mylist.remove("abc");
	mylist.print();
	//cout<<mylist.contains("abc")<<endl;
	
	
	//One Element
	mylist.insert("first");
	mylist.remove("abc");
	mylist.remove("first");
	mylist.insert("first");
	mylist.print();
	//cout<<mylist.contains("first")<<endl;
	//cout<<mylist.contains("abc")<<endl;
	
	//Two Element
	mylist.insert("second");
	mylist.remove("abc");
	mylist.remove("second");
	mylist.insert("second");
	mylist.remove("first");
	mylist.insert("first");
	mylist.print();
	//cout<<mylist.contains("first")<<endl;
	//cout<<mylist.contains("second")<<endl;
	//cout<<mylist.contains("abc")<<endl;
	
	//Three Element
	mylist.insert("third");
	mylist.remove("third");
	mylist.insert("third");
	mylist.remove("second");
	mylist.insert("second");
	mylist.remove("third");
	mylist.insert("third");
	mylist.print();
	//cout<<mylist.contains("third")<<endl;
	//cout<<mylist.contains("second")<<endl;
	//cout<<mylist.contains("abc")<<endl;
	
	mylist.insert_back("fourth");
	mylist.print();
	
	mylist.insert_back("fifth");
	mylist.insert("fifth");
	mylist.remove("fifth");
	mylist.print();

	
	return 0;
}