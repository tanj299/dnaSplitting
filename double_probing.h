// Name: Jayson Tan 
// Course: CSCI 335
// Instructor: Ioannis Stamos 
// Term: Spring 2019 
// Assignment: Assignment 3 
// External Source Code Used: N/A 
// SN: Student Notes 

#ifndef DOUBLE_PROBING_H
#define DOUBLE_PROBING_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std; 

namespace {

// Internal method to test if a positive number is prime.
bool DoubleIsPrime(size_t n) {
  if( n == 2 || n == 3 )
    return true;
  
  if( n == 1 || n % 2 == 0 )
    return false;
  
  for( size_t i = 3; i * i <= n; i += 2 )
    if( n % i == 0 )
      return false;
  
  return true;
}


// Internal method to return a prime number at least as large as n.
int DoubleNextPrime(size_t n) {
  if (n % 2 == 0)
    ++n;  
  while (!DoubleIsPrime(n)) n += 2;  
  return n;
}

}  // namespace

// Quadratic probing implementation.
template <typename HashedObj>
class HashTableDouble {
 public:
  enum EntryType {ACTIVE, EMPTY, DELETED};

  explicit HashTableDouble(size_t size = 101) : array_(DoubleNextPrime(size))
    { MakeEmpty(); }
  
  bool Contains(const HashedObj & x) { // removed 'const' after (HashedObj &x)
    return IsActive(FindPos(x));
  }
  
  void MakeEmpty() {
    current_size_ = 0;
    for (auto &entry : array_)
      entry.info_ = EMPTY;
  }

  bool Insert(const HashedObj & x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos)) 
      return false;
    
    array_[current_pos].element_ = x;
    array_[current_pos].info_ = ACTIVE;

    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();    
    return true;
  }
    
  bool Insert(HashedObj && x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;
    
    array_[current_pos] = std::move(x);
    array_[current_pos].info_ = ACTIVE;

    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();

    return true;
  }

  bool Remove(const HashedObj & x) {
    size_t current_pos = FindPos(x);
    if (!IsActive(current_pos))
      return false;

    array_[current_pos].info_ = DELETED;
    return true;
  }
//*******************************************************************************************
// new functions
//*******************************************************************************************
  int getSize() {
    return current_size_;
  }

  // gets size of hashtable
  int getArraySize() {
    return array_.size(); 
  }

  size_t returnPos(HashedObj &x) {
    return FindPos(x);
  }

  int countCollisions() {
    return collisionCount;
  }

  int getProbeCount() {
    return probeCount;
  }

  void resetProbeCount() {
    probeCount = 0; 
  }

//*******************************************************************************************
// private 
//******************************************************************************************* 
 private:        
  struct HashEntry {
    HashedObj element_;
    EntryType info_;
    
    HashEntry(const HashedObj& e = HashedObj{}, EntryType i = EMPTY)
    :element_{e}, info_{i} { }
    
    HashEntry(HashedObj && e, EntryType i = EMPTY)
    :element_{std::move(e)}, info_{ i } {}
  };
    
  int probeCount = 1; 
  int collisionCount = 0;
  std::vector<HashEntry> array_;
  size_t current_size_;

  // returns true if element in array is occupied; true it is, false if not
  bool IsActive(size_t current_pos) const
  { return array_[current_pos].info_ == ACTIVE; }

  size_t FindPos(const HashedObj & x) { // removed 'const' after (HashedObj &x)
    //size_t offset = 1;
    size_t current_pos = InternalHash(x);
    size_t tempPos = InternalHash(x);
    size_t nextPos = InternalHashTwo(x);
    probeCount = 1; 
    int multiple = 1; 

    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) {
      collisionCount++;
      probeCount++; 
      // SN: doubleHash = [hash1 + (i * hash2)] % array_.size()
      current_pos = (tempPos + (multiple * nextPos)) % array_.size();  // Compute ith probe.
      multiple++;

     if (current_pos >= array_.size())
      current_pos -= array_.size();
    }
    return current_pos;
  }

  void Rehash() {
    std::vector<HashEntry> old_array = array_;

    // Create new double-sized, empty table.
    array_.resize(DoubleNextPrime(2 * old_array.size()));
    for (auto & entry : array_)
      entry.info_ = EMPTY;
    
    // Copy table over.
    current_size_ = 0;
    for (auto & entry :old_array)
      if (entry.info_ == ACTIVE)
	     Insert(std::move(entry.element_));
  }
  
  size_t InternalHash(const HashedObj & x) const {
    static std::hash<HashedObj> hf;
    return hf(x) % array_.size( );
  }

  size_t InternalHashTwo(const HashedObj  &x) const {
    static std::hash<HashedObj> hf;
    // the prime number, R, is 83 here, yielding 18859 collisions  
    size_t prime = 80;
    size_t nextPrime = 0;
    // SN: Originally made a prime number per every hash value but that was wrong haha
    //size_t key = hf(x)%array_.size();
    //int doubleKey = DoubleNextPrime(key);

    // check if prime is greater than table size
    if(prime > 101) {
      prime = 83; 
    }

    if(DoubleIsPrime(prime) == true) {
      return prime - (hf(x)%prime);
    }

    else {
      nextPrime = DoubleNextPrime(prime);
      if(nextPrime > 101) {
        prime = 83; 
      }
      return nextPrime - (hf(x) % nextPrime);
    }
    
    /*
    if(DoubleIsPrime(key) == true) {
      return key - (hf(x) % key); 
    }

    else {
      return doubleKey - (hf(x) % doubleKey); 
    }*/
  }
};

#endif  // QUADRATIC_PROBING_H
