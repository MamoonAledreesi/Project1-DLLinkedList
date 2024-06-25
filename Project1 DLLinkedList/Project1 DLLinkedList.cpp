

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;


int main()
{

    clsDblLinkedList <int> MydblLinkedList;

    if (MydblLinkedList.ISEmpty())
        cout << "\n\n Yes list is Empty\n";
    else
        cout << "\n\n No list is not Empty\n";

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    cout << "\nNumber of items in the linked List = " << MydblLinkedList.Size()<<endl;
  //  MydblLinkedList.Clear();

    
    /*MydblLinkedList.Reverse();
    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();*/

    /*clsDblLinkedList<int>::Node *N;
    N = MydblLinkedList.GetNode(1);
    cout << "\n\n vlaue of N : " << N->_value;
  */

   // cout << "\nItem(2) value is  " << MydblLinkedList.GetItem(2);



 /*   MydblLinkedList.UpdateItem(0, 500);
    cout << "\nLinked List After Update:\n";
    MydblLinkedList.PrintList();*/

    MydblLinkedList.InsertAfter(0, 500);
    MydblLinkedList.PrintList();
    system("pause>0");

}