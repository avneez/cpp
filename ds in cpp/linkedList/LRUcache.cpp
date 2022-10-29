#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

class LRUCache{
public:
    struct node{
        public:
            int key,val;
            node *next, *prev;
        node(int _key, int _val){
            key=_key;
            val=_val;
        }
    };
    //fixed node head and tail to avoid multiple if conditions for NULL
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);

    //directly take a list to avoid DLL implementation
    //list<int> dq;
    int cap;
    unordered_map<int, node*> m;

    LRUCache(int capacity){
        ans.push_back(-2);  //-2 means null operation
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNode(node *newnode){
        node *temp = head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }

    void delNode(node *delnode){
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delnext->prev = delprev;
        delprev->next = delnext;
    }

    int get(int key){
       if(m.find(key)!=m.end()){
            node *resnode = m[key];
            int res=resnode->val;
            m.erase(key);
            delNode(resnode);
            addNode(resnode);
            m[key]=head->next;
            ans.push_back(res);
            return res;
       }
       ans.push_back(-1);
       return -1;
    }

    void put(int key, int val){
        ans.push_back(-2);
        if(m.find(key)!=m.end()){
            node *nodeexist = m[key];
            m.erase(key);
            delNode(nodeexist);
        }
        if(m.size()==cap){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }
        addNode(new node(key,val));
        m[key] = head->next;
    }

};

void printVal(vector<int>& ans){
    for(auto it:ans){
        if(it==-2) cout<<"null"<<" ";
        else cout<<it<<" ";
    }
}


// We can use stl container list as a double
// ended queue to store the cache keys, with
// the descending time of reference from front
// to back and a set container to check presence
// of a key. But to fetch the address of the key
// in the list using find(), it takes O(N) time.
// This can be optimized by storing a reference
//	 (iterator) to each key in a hash map.

class LRUCache2 {
	// store keys of cache
	list<int> dq;

	// store references of key in cache
	unordered_map<int, list<int>::iterator> ma;
	int csize; // maximum capacity of cache

public:
	LRUCache2(int);
	void refer(int);
	void display();
};

// Declare the size
LRUCache2::LRUCache2(int n)
{
	csize = n;
}

// Refers key x with in the LRU cache
void LRUCache2::refer(int x)
{
	// not present in cache
	if (ma.find(x) == ma.end()) {
		// cache is full
		if (dq.size() == csize) {
			// delete least recently used element
			int last = dq.back();

			// Pops the last element
			dq.pop_back();

			// Erase the last
			ma.erase(last);
		}
	}

	// present in cache
	else
		dq.erase(ma[x]);

	// update reference
	dq.push_front(x);
	ma[x] = dq.begin();
}

// Function to display contents of cache
void LRUCache2::display()
{
	// Iterate in the deque and print all the elements in it
	for (auto it = dq.begin(); it != dq.end();
		it++)
		cout << (*it) << " ";
	cout << endl;
}



int main(){
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    lRUCache.get(1);    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
    printVal(ans);

    cout<<endl;

    LRUCache2 ca(4);
	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);
	ca.display();
return 0;
}
