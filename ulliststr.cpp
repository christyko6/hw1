#include <cstddef>
#include <stdexcept>
#include <iostream>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  //check if it is empty
  if(empty()){
    //create a new Item if it is empty
    Item* newNode = new Item;
    tail_ = newNode;
    head_ = newNode;
    tail_ -> val[tail_->last] = val;
    tail_->last++;
    //if it is full
  }else if(tail_->last == 10){
    //need a temp variable to store the pointer of the previous node so we can reassign the tail
    Item* newNode = new Item;
    Item* temp = tail_;
    tail_ = newNode;
    tail_->prev = temp;
    tail_->last= 1;
    //delete temp; -> causes valgrind error
    tail_ -> val[tail_->last] = val;
  }else{
    //add val onto the next item
    tail_ -> val[tail_->last] = val;
    tail_-> last++;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val){
  //create a new Item if it is empty
 if(empty()){
   Item* newNode = new Item;
   head_= newNode;
   tail_= newNode;
   head_ -> val[head_->first]=val;
   //head_->first=10;
   head_->last++;
 }else if(head_->first==0){
   //need a temp variable to store the pointer of the next Node
   Item* newNode = new Item;
   Item* temp = head_;
   head_ = newNode;
   head_->next=temp;
   head_->last=10;
   head_->first = 9;
   //delete temp;
   head_->val[head_->first]=val;
 }else{
   //add val onto the node before it
   head_->val[head_->first-1]=val;
   head_->first--;
 }
 size_++;
}


void ULListStr::pop_front(){
  if(empty()){
    return;
  } else{
    //move first pointer to the next position
    head_->first= head_->first+1;
    size_--;
}
}

void ULListStr::pop_back(){
  if(empty()){
    return;
  } else{
    //move last pointer to the one behind it
    tail_->last= tail_->last-1;
    size_--;
}
  
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(empty()){
    return NULL;
  }
  Item* temp = head_;
  while(size_<=loc){
    loc-=size_;
    temp = temp->next;
  }
  return &temp->val[temp->first+loc];

}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
