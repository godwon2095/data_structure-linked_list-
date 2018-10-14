#include "lnklist.hpp"

using namespace std;


template<class DT>
ListNode<DT>::ListNode(const DT &dataItem, ListNode<DT> *nextPtr)
// Creates a stack node containing element elem and next pointer
// nextPtr.
: dataItem(dataItem),
next(nextPtr)
{
    
}

template<class DT>
List<DT>::List(int ignored)
{
    cursor = 0;
    head = 0;
    listSize = 0;
}

//------------------------------------------------

template<class DT>
List<DT>::~List()
{
    this->clear();
}

//------------------------------------------------


template<class DT>
void List<DT>::insert(const DT &newData)
{
    if (head == NULL)
    {
        ListNode<DT>* location = new ListNode<DT>(newData, NULL);
        head = location; // head setting
        cursor = location;
        listSize++;
    }
    else
    {
        ListNode<DT>* location = new ListNode<DT>(newData, cursor->next);
        cursor->next = location;
        cursor = location;
        listSize++;
    }
}

//------------------------------------------------


template<class DT>
void List<DT>::remove()
{
    if (this->isEmpty())
    {
        cout << "Empty List!" << endl;
    }
    else {
        if (cursor != head)
        {
            ListNode<DT>* saveCursor = cursor->next;
            ListNode<DT>* deleteCursor = cursor;
            
            this->gotoPrior();
            cursor->next = saveCursor;
            
            delete deleteCursor;
            listSize--;
        }
        else
        {
            ListNode<DT>* saveCursor = cursor->next;
            ListNode<DT>* deleteCrusor = cursor;
            
            List<DT>::gotoNext();
            head = saveCursor;
            
            delete deleteCrusor;
            listSize--;
        }
    }
}
//------------------------------------------------


template<class DT>
void List<DT>::replace(const DT &newData)
{
    if (this->isEmpty())
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        ListNode<DT> *location = cursor;
        location->dataItem = newData;
    }
}

//------------------------------------------------


template<class DT>
void List<DT>::clear()
{
    if (this->isEmpty())
    { 
        cout << "Empty List!" << endl;
    }
    else
    {
        int count = listSize;
        this->gotoEnd();
        do
        {
            this->remove();
            count--;
        } while (count != 0);
    }
}

//------------------------------------------------


template<class DT>
bool List<DT>::isEmpty() const
{
    if (head == 0)
        return true;
    else
        return false;
}

//------------------------------------------------


template<class DT>
bool List<DT>::isFull() const
{
    return false;
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoBeginning()
{
    if (this->isEmpty())
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        cursor = head;
    }
    return false;
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoEnd()
{
    if (this->isEmpty())
    {
        cout << "Empty List!" << endl;
        return false;
    }
    else
    {
        this->gotoBeginning();
        do
        {
            this->gotoNext();
        } while (cursor->next != NULL);
        return true;
    }
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoNext()
{
    if (this->isEmpty())
    {
        cout << "Empty List!" << endl;
    }
    else if (cursor->next == NULL)
    {
        return false;
    }
    else
    {
        cursor = cursor->next;
        return true;
    }
}

//------------------------------------------------


template<class DT>
bool List<DT>::gotoPrior()
{
    if (this->isEmpty())
    {
        cout << "Empty Stack!" << endl;
        return false;
    }
    else
    {
        if (cursor == head) return false;
        else
        {
            int count = 1;
            int retrieve = 0;
            
            while (gotoNext())
            {
                count++;
            }
            retrieve = listSize - count;
            gotoBeginning();
            while (retrieve > 1)
            {
                gotoNext();
                retrieve--;
            }
        }
    }
    return true;
}

//------------------------------------------------


template<class DT>
DT List<DT>::getCursor() const
{
    if (this->isEmpty())
    {
        cout << "Empty Stack!" << endl;
    }
    else
    {
        return cursor->dataItem;
    }
    
}

template<class DT>
void List<DT>::moveToBeginning()
{
    if (!List<DT>::isEmpty())
    {
        ListNode<DT>* saveCursorDataItem =  cursor;
        this->remove();
        this->gotoBeginning();
        this->insertBefore(saveCursorDataItem->dataItem);
        cursor = head;
    }
    else
        cout << "This is Empty Stack" << endl;
        }
        
template<class DT>
void List<DT>::insertBefore(const DT & newDataItem)
{
    if (!List<DT>::isEmpty())
    {
        this->gotoPrior();
        if (head != cursor)
        {
            this->insert(newDataItem);
        }
        else
        {
            ListNode<DT>* newHead = new ListNode<DT>(newDataItem, head);
            head = newHead;
            cursor = head;
        }
    }
else
    cout << "Empty Stack" << endl;
}
//------------------------------------------------
        
        
template<class DT>
void List<DT>::showStructure() const
{
if (head == 0)
{
    cout << "Empty Stack" << endl;
}
else
{
    for (ListNode<DT>* temp = head; temp != 0; temp = temp->next)
    {
        if (temp == cursor)
        {
            cout << "cursor -> "; cout <<"Node DataItem : " << temp->dataItem << endl;
        }
        else
        {
            cout << "          Node DataItem : " << temp->dataItem << endl;
        }
    }
    cout << endl;
}
}

//------------------------------------------------
        
        
