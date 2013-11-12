#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <class TypeKey, class TypeElement>
class HashMap {
	
private:
	// internal storage table
	// Note that list in STL is a doubly-linked list
	vector< list<TypeElement> > hashtable;
	int cur_num_elements;
	int arraySize;
	
public:
	// the explicit keyword disables implicit type conversion by the compiler
	explicit HashMap(int arraySize=100){
		this->arraySize = arraySize;
		this->cur_num_elements = 0;
		
		//initialize hashtable
		for(int i=0; i<arraySize; i++){
			list<TypeElement> mylist;
			hashtable.push_back(mylist);
		}
	}
	
	// key can only be of type string or integer 
	int hashCode(const string & key){
		int result = 0;
		for(int i=0; i<key.size(); i++){
			result += key[i];
		}
		return result%arraySize;
	}
	
	int hashCode(int key){
		return key%arraySize;
	}
	
	bool contains(const TypeElement & x) const;
	void makeEmpty();
	
	// insert the element into the hashtable
	void insert(const TypeKey & key, const TypeElement & x){
		int index = hashCode(key);
		
		// get a REFERENCE to the list element
		list<TypeElement> & cur_list = hashtable[index];
		cur_list.push_back(x);
		
		cur_num_elements++;	
	}
	

	bool remove(const TypeElement & x){
		for(int row = 0; row < arraySize; row++){
			list<TypeElement> & cur_list = hashtable[row];
			typename list<TypeElement>::iterator it;
			it = find(cur_list.begin(), cur_list.end(), x);
			
			if(it != cur_list.end()){
				// found it
				cur_list.erase(it);
				cur_num_elements--;
				return true;
			}
		}
		return false;
	}
	
	void print(){
		cout<<"--- "<<this->cur_num_elements<<" elements in the HashMap"<<endl;
		for(int row = 0; row < arraySize; row++){
			list<TypeElement> & cur_list = hashtable[row];
			typename list<TypeElement>::iterator col;
			for(col = cur_list.begin(); col != cur_list.end(); col++){
				cout<<*col<<", ";
			}
		}
		cout<<endl;
	}
	
	
};

int main(){
	HashMap<int, string> mymap(10);
	mymap.insert(1,"abc");
	mymap.insert(2,"abc");
	mymap.print();
	
	mymap.insert(3,"");
	mymap.print();
	
	mymap.insert(1,"abcdeft");
	mymap.insert(2,"popo");
	mymap.print();
	
	mymap.remove("popo");
	mymap.print();
	
	mymap.remove("abc");
	mymap.print();
	
	mymap.remove("");
	mymap.print();
	
	mymap.remove("abc");
	mymap.print();
	
	return 0;
}


