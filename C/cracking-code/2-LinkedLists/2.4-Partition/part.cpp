#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node *next;
};
 
Node* Insert( Node *head, int d ) {
    Node *newNode = new Node();
    newNode->data = d;

    if ( head == NULL ) {
        head = newNode;
    } else {
         Node *prev = head;
         while ( prev->next != NULL ) {
             prev = prev->next;
         }

         prev->next = newNode;

         return head;
    }
}

Node* Delete( Node* head, int d ) {
    if ( head == NULL ) {
        return head;
    } else {
        Node *prev = head;
        Node *curr = head;
        while ( ( curr != NULL ) && ( curr->data != d ) ) {
            prev = curr;
            curr = curr->next;
        }

        if ( curr != NULL ) {
            prev->next = curr->next;
            delete curr;
        }
    }

    return head;
}

Node* Delete( Node* head, Node* remove ) {
    if ( head == NULL ) {
        return head;
    } else {
        Node *prev = head;
        Node *curr = head;
        while ( ( curr != NULL ) && ( curr != remove ) ) {
            prev = curr;
            curr = curr->next;
        }

        if ( curr != NULL ) {
            prev->next = curr->next;
            delete curr;
        }
    }

    return head;
}

void RemoveDups( Node* head ) {
    Node* outer = head;
    Node* inner = head;

    while ( outer != NULL ) {

        inner = outer->next;
        
        while ( inner != NULL ) {

            if ( outer->data == inner->data ) {
                Delete( head, inner );
            }

            inner = inner->next;
        }

        outer = outer->next;
    }
}

Node* ReturnKthLast( Node* head, int k ) {    
    int i;
    Node* kth = head;
    Node* curr = head;

    if ( head == NULL ) {
        return kth;
    }

    for ( i = 0; ( i < k ) && ( curr != NULL ) ; i++ ) {
        curr = curr->next;
    }

    while ( curr->next != NULL ) {
        kth = kth->next;
        curr = curr->next;
    }

    return kth;
}

void PrintList( Node* head ) {
    Node *curr = head;

    while ( curr != NULL ) {
        cout << curr->data << " ";
        curr = curr->next;
    }

    cout << endl;
}

int main()
{
    Node *head = NULL;

    head = Insert( head, 1 );
    head = Insert( head, 2 );
    head = Insert( head, 3 );
    head = Insert( head, 4 );
    head = Insert( head, 5 );
    head = Insert( head, 6 );
    head = Insert( head, 7 );
    head = Insert( head, 8 );
    head = Insert( head, 9 );
    PrintList( head );

    int kth = 0;
    cout << kth << " from last is " << ReturnKthLast( head, kth )->data << endl;
    kth = 3;
    cout << kth << " from last is " << ReturnKthLast( head, kth )->data << endl;
    kth = 8;
    cout << kth << " from last is " << ReturnKthLast( head, kth )->data << endl;

    Delete( ReturnKthLast( head, 3 ) );
    PrintList( head );
    
    Delete( ReturnKthLast( head, 3 ) );
    PrintList( head );
    
    return 0;
}
