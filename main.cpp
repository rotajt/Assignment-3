#include <iostream>
#include  <vector>
#include "Header.h"

using namespace std;

LinkedList::LinkedList(){
    head= NULL;
    tail= NULL;
}
LinkedList::~LinkedList(){
    node * tmp=NULL;
    while(head!=NULL)
    {
     tmp =head;
     head = head->next;
    delete tmp;
    }
}
void LinkedList::AddNode(int n){
    node *tmp = new node;
    tmp-> data = n;
    tmp-> next = NULL;
    if (head == NULL ){
        head = tmp;
        tail= tmp;
    }
    else {
        tail->next=tmp;
        tail = tail->next;
    }
};
/*
void LinkedList::DeleteNode(node *head, int key){

    node *tmp = this->head;
    node *prev= NULL;

    while(tmp->next!=NULL){

        if (tmp->data==key){

                prev->next = tmp->next;

                if(tmp == this->head && prev==NULL)
                    this->head = tmp->next;
                else
                    this->head = prev;

            delete tmp;
            return;

        }

        prev=tmp;
        tmp=tmp->next;
    }


};
*/
void LinkedList::DeleteNode(node** h, int key)
{
    node* temp = *h;
    node* prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *h = temp->next;
        delete temp;
        return;
    }
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    delete temp;
    }
}
LinkedList LinkedList::Transfer(vector<int> v){
    LinkedList tmp;

    for(int i : v)
    {
        tmp.AddNode(i);
    }
    return tmp;

}
int LinkedList::Sum(node **head){
    int sum=0;
    node *a = *head;
        while (a!= NULL){
            sum = a->data;
            cout<<"sum: "+sum<<endl;
            a = a-> next;
        }

    return sum;
}

 void LinkedList :: print(node *head){
        node *a = head;
        while (a!= NULL){
            cout << a-> data <<endl;
            a = a-> next;
        }
    }
vector<int> insertAfter(int num1, int num2, vector<int> v){

        int k=1;
       for(auto i : v){

            if(i == num1){
                v.insert(v.begin()+k,num2);
            }
            k++;

        }

        return v;
};

int main() {

    LinkedList *f = new LinkedList();
    cout<<"---------------LinkedList----------------"<<endl;
    f->AddNode(3);
    f->AddNode(4);
    f->AddNode(3);
    f->print(f->head);
    f->DeleteNode(&f->head,4);
    f->print(f->head);


    cout<<"----------------Vector------------------"<<endl;


    vector<int> v;
    int n;
    int number;
    cout<<"Please enter the number of numbers";
    cin>>n;
    for (int i=0;i<n;i++){
        cin >> number;
        v.push_back(number);
    }

    //for(int i : v)
    //cout << "i = " << i << endl;


    v =insertAfter(2,3,v);

    for (int i=0;i<n;i++){

        cout<<v[i]<<endl;
    }

}
