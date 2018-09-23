#include<string>
#include<iostream>
using namespace std;
template <typename V>
class mapNode{
public:
	string key;
	V value;
	mapNode<V> *next;
	mapNode(string key, V value){
		this -> key = key;
		this -> value = value;
		next = nullptr;
	}
	~mapNode(){
		delete next;
	}
};
template <typename V>
class ourmap{
	mapNode<V> **buckets;
	int size;
	int numBuckets;
public:
	ourmap(){
		numBuckets = 10;
		buckets = new mapNode<V>*[numBuckets];
		size = 0;
		for(int i = 0; i < numBuckets; i++)
			buckets[i] = nullptr;
	}
	~ourmap(){
		for(int i = 0; i < numBuckets; i++)
			delete buckets[i];
		delete[] buckets;
	}
private:
	int hashFunction(string temp){
		int hashCode = 0;
		int coeffecient = 1;
		for(int i = temp.size()-1; i >=0; i--){
			hashCode = hashCode + temp[i] * coeffecient;
			hashCode = hashCode % numBuckets;
			coeffecient *= 7;
			coeffecient = coeffecient % numBuckets;
		}
		return hashCode % numBuckets;
	}
public:
	void insert(string k, V val){
		int hash = hashFunction(k);
		mapNode<V> *head = buckets[hash];
		while(head != nullptr){
			if(head -> key == k){
				head -> value = val;
				return ;
			}
			head = head -> next;
		}
		head = buckets[hash];
		mapNode<V> *node = new mapNode<V>(k, val);
		node -> next = head;
		buckets[hash] = node;
		return;
	}

	V deleteMap(string key){
		int bucketIndex = hashFunction(key);
		mapNode<V> *head = buckets[bucketIndex];
		mapNode<V> *prev = nullptr;

        while(head != nullptr)
		{
			if(head -> key == key){
				if(prev == nullptr){
					buckets[bucketIndex] = head -> next;
					break;
				}else{
					prev -> next = head -> next;
					break;
				}
			}
			prev = head;
			head = head -> next;
		}
		if(head == nullptr){
            return 0;
		}
		V val = head -> value;
		head -> next = nullptr;
		delete head;
		return val;
	}
	V getValue(string key){
	    int hash = hashFunction(key);
	    mapNode<V> *head = buckets[hash];
	    while(head != nullptr){
            if(head -> key == key){
                return head -> value;
            }
            head = head -> next;
	    }
	    return -1;
	}

};
