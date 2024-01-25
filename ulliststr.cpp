#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>

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

void ULListStr::push_back(const std::string &val)
{
  if (tail_ == nullptr)
  {
    tail_ = new Item();
    tail_->prev = nullptr;
    tail_->next = nullptr;
    tail_->first = 0;
    tail_->last = 0;
    head_ = tail_;
  }
  if (tail_->last == ARRSIZE)
  {
    Item *temp = new Item();
    temp->prev = tail_;
    temp->next = nullptr;
    temp->first = 0;
    temp->last = 0;
    tail_->next = temp;
    tail_ = temp;
  }
  tail_->val[tail_->last] = val;
  tail_->last++;
  size_++;
}
void ULListStr::pop_back()
{
  if (tail_ == nullptr)
  {
    return;
  }
  if (tail_->last == 0)
  {
    Item *temp = tail_->prev;
    delete tail_;
    tail_ = temp;
    tail_->next = nullptr;
  }
  tail_->last--;
  size_--;
}
void ULListStr::push_front(const std::string &val)
{
  if (head_ == nullptr)
  {
    head_ = new Item();
    head_->prev = nullptr;
    head_->next = nullptr;
    head_->first = 10;
    head_->last = 10;
    tail_ = head_;
  }
  if (head_->first == 0)
  {
    Item *temp = new Item();
    temp->prev = nullptr;
    temp->next = head_;
    temp->first = 10;
    temp->last = 10;
    head_->prev = temp;
    head_ = temp;
  }
  head_->first--;
  head_->val[head_->first] = val;
  size_++;
}
void ULListStr::pop_front()
{
  if (head_ == nullptr)
  {
    return;
  }
  if (head_->first == head_->last)
  {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
    head_->prev = nullptr;
  }
  head_->first++;
  size_--;
}

std::string const &ULListStr::back() const
{
  return get(size_-1);
}

std::string const &ULListStr::front() const
{
  return get(0);
}

std::string *ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_)
  {
    return nullptr;
  }
  Item *temp = head_;
  bool locFound = false;
  while (!locFound)
  {
    if (loc >= temp->last - temp->first)
    {
      loc -= temp->last - temp->first;
      temp = temp->next;
    }
    else
    {
      locFound = true;
    }
  }
  return &(temp->val[temp->first + loc]);
}

void ULListStr::set(size_t loc, const std::string &val)
{
  std::string *ptr = getValAtLoc(loc);
  if (ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string &ULListStr::get(size_t loc)
{
  std::string *ptr = getValAtLoc(loc);
  if (ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const &ULListStr::get(size_t loc) const
{
  std::string *ptr = getValAtLoc(loc);
  if (ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while (head_ != NULL)
  {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
