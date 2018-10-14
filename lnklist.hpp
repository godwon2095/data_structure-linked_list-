#pragma once

#include <iostream>
using namespace std;

template<class DT> //Forward declaration of the List class
class List;

template<class DT>
class ListNode    //Facilitator class for the List class
{
private:
    ListNode( const DT &nodeData, ListNode *nextPtr );
    
    //Data members
    DT dataItem; //List data item
    ListNode *next; //Pointer to the next list node
    
    friend class  List<DT>;
};

//------------------------

template<class DT>
class List
{
public:
    //Constructor
    List( int ignored = 0);
    //Destructor
    ~List();
    //List manipulation operations
    void insert(const DT &newData);
    void remove();
    void replace(const DT &newData);
    void clear();
    void moveToBeginning();
    void insertBefore(const DT & newDataItem);
    
    //List status operations
    bool isEmpty() const;
    bool isFull() const;
    
    //List iteration operations
    bool gotoBeginning();
    bool gotoEnd();
    bool gotoNext();
    
    bool gotoPrior();
    
    DT getCursor() const;
    //Output the list structure - used in testing/debugging
    void showStructure() const;
    
private:
    
    //Data members
    ListNode<DT> *head,        //Pointer to the beginning of the list
    *cursor;    //Cursor pointer
    int listSize;
};
