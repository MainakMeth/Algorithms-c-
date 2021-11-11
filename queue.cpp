#include<iostream>
#include<climits>
using namespace std;

class Qnode{
   public:
   int value;
   Qnode *next;
};

class Queue{
    Qnode *front;
    Qnode *rear;
    public:
    Queue(){
       front=NULL;
       rear=NULL;
    }
    void enQueue(int);
    int deQueue();
    int isEmpty();
    int peek();
    void display();
};

int Queue::isEmpty(){
     if(front==NULL){
         return 1;
     }
     return 0;
}

void Queue::enQueue(int item){
     Qnode *curr=new Qnode();
     curr->value=item;
     curr->next=NULL;
     if(isEmpty()){
         rear=curr;
         front=curr;
         return;
     }

     rear->next=curr;
     rear=curr;
}

int Queue::deQueue(){
	if(isEmpty()){
		return INT_MIN;
	}
	Qnode *temp=front;
	int item=front->value;
	front=front->next;

        if(front==NULL){
            rear=NULL;
        }
	delete(temp);
	return item;

}

int Queue::peek(){
	if(isEmpty()){
		return INT_MIN;
	}

	return front->value;
}

void Queue::display(){
	if(isEmpty()){
		cout<<"Queue is Empty"<<endl;
		return;
	}
	Qnode *temp=front;
	while(temp!=NULL){
	    cout<<temp->value<<" ";
	    temp=temp->next;
	}
	cout<<endl;
}

 /*int main(){
  system("clear");
  Queue q;
  while(1){
     cout<<"1 Enqueue "<<endl;
     cout<<"2 Dequeue "<<endl;
     cout<<"3 IsEmpty"<<endl;
     cout<<"4 Peek"<<endl;
     cout<<"5 Display the Queue"<<endl;
     cout<<"6 exit"<<endl;
     cout<<endl;
     cout<<"Enter your choice"<<endl;
     int ch,item;
     cin>>ch;
     switch(ch){
	case 1:
            cout<<"Enter the item"<<endl;
            cin>>item;
            q.enQueue(item);
        break;
        case 2:
            item=q.deQueue();
            if(item==INT_MIN){
               cout<<"Queue is Empty"<<endl;
            }
            else{
               cout<<"Popped item is "<<item<<endl;
            }
        break;
        case 3:
            if(q.isEmpty()){
                cout<<"The Queue is Empty"<<endl;
            }

            else{
              cout<<"The Queue is not Empty"<<endl;
            }
        break;
        case 4:
           item=q.peek();
           if(item==INT_MIN){
              cout<<"The Queue is Empty"<<endl;
           }
           else{
              cout<<"The peek item is "<<item<<endl;
           }
        break;
        case 5:
            q.display();
        break;

        default:
          exit(0);
        break;
     }
  }
return 0;
}
*/
