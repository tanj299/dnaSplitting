// Name: Jayson Tan 
// Course: CSCI 335
// Instructor: Ioannis Stamos 
// Term: Spring 2019 
// Assignment: Assignment 3 
// External Source Code Used: N/A 
// SN: Student Notes 

#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std; 

namespace {

// Internal method to test if a positive number is prime.
bool LinearIsPrime(size_t n) {
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
int LinearNextPrime(size_t n) {
  if (n % 2 == 0)
    ++n;  
  while (!LinearIsPrime(n)) n += 2;  
  return n;
}

}  // namespace

// Quadratic probing implementation.
template <typename HashedObj>
class HashTableLinear {
 public:
  enum EntryType {ACTIVE, EMPTY, DELETED};

  explicit HashTableLinear(size_t size = 101) : array_(LinearNextPrime(size))
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
    
  int collisionCount = 0;
  std::vector<HashEntry> array_;
  size_t current_size_;
  int probeCount = 1; 

  // returns true if element in array is occupied; true it is, false if not
  bool IsActive(size_t current_pos) const
  { return array_[current_pos].info_ == ACTIVE; }


  size_t FindPos(const HashedObj & x) { // removed 'const' after (HashedObj &x)
    size_t current_pos = InternalHash(x);
    probeCount = 1; 
    while (array_[current_pos].info_ != EMPTY &&
     array_[current_pos].element_ != x) {
      collisionCount++;
      probeCount++;
      current_pos++;  // Compute ith probe.
      if (current_pos >= array_.size())
       current_pos -= array_.size();
    }
    return current_pos;
  }

  void Rehash() {
    std::vector<HashEntry> old_array = array_;
    // Create new double-sized, empty table.
    array_.resize(LinearNextPrime(2 * old_array.size()));
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
};

#endif  // QUADRATIC_PROBING_H
