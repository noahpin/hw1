/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even
numbers and the other contains the odd numbers. Students
will receive no credit  non-recursive solutions.
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/
#include <iostream>
#include <iomanip>
#include "split.h"
using namespace std;

/* Add a prototype  a helper function here if you need */

void split(Node *&in, Node *&odds, Node *&evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  if (in == nullptr)
  {
    return;
  }
  if(in->value % 2) { // odd
    Node* newNode = new Node(in->value, nullptr);
    if(odds == nullptr) {
      odds = newNode;
      split(in->next, odds, evens);
    }else {
      odds->next = newNode;
      split(in->next, odds->next, evens);
    }
    delete in;

  }else {
    Node* newNode = new Node(in->value, nullptr);
    if(evens == nullptr) {
      evens = newNode;
      split(in->next, odds, evens);
    }else {
      evens->next = newNode;
      split(in->next, odds, evens->next); 
    }
    delete in;
  }
}

/* If you needed a helper function, write it here */
