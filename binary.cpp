#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class Unsuccessful_Search: exception {
	const char*what() const throw() {
		return "number not found";
	}
};

int num_comp = 0;
template <typename T>
int Binary_Search(vector<T> &v, T x) {	
   int mid, low = 0;     
   int high = (int) v.size()-1;     
   while (low < high) {         
      mid = (low+high)/2;                 
      if (num_comp++, v[mid] < x) low = mid+1;         
      else high = mid;     
   }     
   if (num_comp++, x == v[low]) return low; //OK: found          
   throw Unsuccessful_Search(); //exception: not found 

} 


int main() {
	
	  vector<int> vect{1, 2,3,4,5,6,7,8,9,10,11,12,13,14,15};
   int index = Binary_Search(vect,15);
   cout<<" found at index "<<index<<" and number of comparisons are "<<num_comp<<endl;

  
	return 0;
}
        