//Stack using LinkedList

#include<iostream>
#include<climits>

using namespace std;

class Snode{
     public:
        int value;
        Snode *next;
};

class Stack{
   Snode *top;
   public:
     Stack(){
        top=NULL;
     }
     void push(int);
     int pop();
     int isEmpty();
     int peek();
     void display();

};

int Stack::isEmpty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}

void Stack::push(int item){
    Snode *curr=new Snode();
    curr->value=item;
    curr->next=NULL;

    if(top==NULL){
       top=curr;
       return;
    }

    curr->next=top;
    top=curr;
}

int Stack::pop(){
   if(top==NULL){
      return INT_MIN;
   }
   int item=top->value;
   Snode *temp=top;
   top=top->next;
   delete(temp);
   return item;
}



int Stack::peek(){
   if(top==NULL){
      return INT_MIN;
   }
   return (top->value);
}

void Stack::display(){
   if(top==NULL){
      cout<<"Stack is empty"<<endl;
      return;
   }

   Snode *temp=top;
   while(temp!=NULL){
      cout<<temp->value<<endl;
      temp=temp->next;
   }
}

/*int main(){
  system("clear");
  Stack s;
  while(1){
     cout<<"1 Push "<<endl;
     cout<<"2 Pop "<<endl;
     cout<<"3 IsEmpty"<<endl;
     cout<<"4 Peek"<<endl;
     cout<<"5 Display the Stack"<<endl;
     cout<<"6 exit"<<endl;
     cout<<endl;
     cout<<"Enter your choice"<<endl;
     int ch,item;
     cin>>ch;
     switch(ch){
	case 1:
            cout<<"Enter the item"<<endl;
            cin>>item;
            s.push(item);
        break;
        case 2:
            item=s.pop();
            if(item==INT_MIN){
               cout<<"Stack is Empty"<<endl;
            }
            else{
               cout<<"Popped item is "<<item<<endl;
            }
        break;
        case 3:
            if(s.isEmpty()){
                cout<<"The Stack is Empty"<<endl;
            }

            else{
              cout<<"The Stack is not Empty"<<endl;
            }
        break;
        case 4:
           item=s.peek();
           if(item==INT_MIN){
              cout<<"The Stack is Empty"<<endl;
           }
           else{
              cout<<"The peek item is "<<item<<endl;
           }
        break;
        case 5:
            s.display();
        break;

        default:
          exit(0);
        break;
     }
  }
return 0;
}*/
