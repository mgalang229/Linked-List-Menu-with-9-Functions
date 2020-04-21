#include <iostream>
#include <cstdlib>
using namespace std;
struct Node{
	int info;
	struct Node *link;
}*start;
void createList(int data);
void addNodeBegin(int data);
void addNodeSpecific(int pos, int data);
void deleteNodeBegin();
void deleteNodeEnd();
void deleteNodeSpecific(int pos);
void reverseList();
void changeNode(struct Node *x, struct Node *y);
void sortList();
void display();
int main(){
	int choice, element, n, i, position;
	while(1){
		cout << "\nMENU\n";
		cout << "1 - Create List\n";
		cout << "2 - Add at beginning\n";
		cout << "3 - Add at a specific node\n";
		cout << "4 - Delete node in the beginning\n";
		cout << "5 - Delete node in the end\n";
		cout << "6 - Delete at a specific node\n";
		cout << "7 - Reverse\n";
		cout << "8 - Sort\n";
		cout << "9 - Display\n";
		cout << "10 - Exit\n";
		cout << "\nEnter choice: ";
		cin >> choice;
		switch(choice){
			case 1:
				cout << "How many nodes you want to create? \n";
				cin >> n;
				for(i = 0; i < n; i++){
					cout << "Enter the elements: \n";
					cin >> element;
					createList(element);
				}
				break;
			case 2:
				cout << "Add a node in the beginning: \n";
				cin >> element;
				addNodeBegin(element);
				break;
			case 3:
				cout << "Add at a specific node: \n";
				cout << "Enter element: ";
				cin >> element;
				cout << "Enter position: ";
				cin >> position;
				addNodeSpecific(position, element);
				break;
			case 4:
				cout << "Delete node in the beginning: \n";
				deleteNodeBegin();
				cout << "Beginning Node Deleted\n";
				break;
			case 5:
				cout << "Delete node in the end: \n";
				deleteNodeEnd();
				cout << "End Node Deleted\n";
				break;
			case 6:
				cout << "Delete at a specific node: \n";
				cout << "Enter position: ";
				cin >> position;
				deleteNodeSpecific(position);
				cout << "Specific Node Deleted\n";
				break;
			case 7:
				cout << "Linked List Reversed \n";
				reverseList();
				break;
			case 8:
			    cout << "Linked List Sorted \n";
			    sortList();
			    break;
			case 9:
			    display();
			    break;
			case 10:
			    cout << "Exiting...\n";
			    exit(1);
			    break;
			default:
				exit(1);
		}
	}
	return 0;
}
void createList(int data){
	struct Node *p, *tmp;
	tmp = new Node;
	tmp -> info = data;
	tmp -> link = NULL;
	if(start == NULL){
		start = tmp;
	} else{
		p = start;
		while(p -> link != NULL){
			p = p -> link;
		}
		p -> link = tmp;
	}
}
void addNodeBegin(int data){
	struct Node *p2;
	p2 = new Node;
	p2 -> info = data;
	if(start == NULL){
		p2 -> link = NULL;
	} else{
		p2 -> link = start;
	}
	start = p2;
}
void addNodeSpecific(int pos, int data){
    struct Node *p2, *temp;
    int k = 1;
    if(pos == 1){
        p2 = new Node;
        p2 -> info = data;
        p2 -> link = start;
        start = p2;
      } else{
        temp = start;
        pos--;
        while(k < pos){
          temp = temp -> link;
          if(temp == NULL){
            cout << "Node is less than position\n";
            exit(1);
          }
          k++;
        }
    
        p2 = new Node;
        p2 -> info = data;
        p2 -> link = temp -> link;
        temp -> link = p2;
      }
}
void deleteNodeBegin(){
	struct Node *p;
	if(start == NULL){
		cout << "List Empty";
	}else{
		p = start;
		start = start -> link;
		free(p);
	}
}
void deleteNodeEnd(){
	struct Node *p, *tmp;
	if(start == NULL){
		cout << "List Empty";
	}else{
		if(start -> link == NULL){
			p = start;
			start = NULL;
			free(p);
		} else{
			p = start;
			while(p -> link != NULL){
				tmp = p;
				p = p-> link;
			}
			tmp -> link = NULL;
		}
	}
}
void deleteNodeSpecific(int position){
    struct Node *p, *temp, *link;
    temp = start;
    if(position == 1){
        p = start;
		start = start -> link;
		free(p);
    } else{
        if(temp == NULL || temp -> link == NULL){
            cout << "List is empty";
            return;
        } else{
            for (int i = 2; temp != NULL && i < position; i++){
                temp = temp -> link;
            }  
            link = temp -> link -> link;
            free(temp -> link);
            temp -> link = link;
        }
    }
}
void reverseList(){
    struct Node *current, *prev, *link;
    current = start;
    prev = link = NULL;
    while(current != NULL){
        link = current -> link;
        current -> link = prev;
        prev = current;
        current = link;
    }
    start = prev;
}
void changeNode(struct Node *x, struct Node *y) { 
    int temp;
    temp = x -> info; 
    x -> info = y -> info; 
    y -> info = temp; 
}
void sortList(){
    int change;
    struct Node *p, *temp;
    temp = NULL;
    if(start == NULL){
        return;
    }
    do{
        change = 0;
        p = start;
        
        while(p -> link != temp){
            if(p -> info > p -> link -> info){
                changeNode(p, p -> link);
                change = 1;
            }
            p = p -> link;
        }
        temp = p;
    }while(change);
}
void display(){
	struct Node *p;
	if(start == NULL){
		cout << "It's empty!\n";
		return;
	}
	p = start;
	cout << "The list: \n";
	while(p != NULL){
		cout << p -> info << endl;
		p = p -> link;
	}
}