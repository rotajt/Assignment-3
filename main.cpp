#include <iostream>
#include  <vector>
#include "Header.h"

using namespace std;

LinkedList::LinkedList(){
    head= NULL;
    tail= NULL;
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

void LinkedList::DeleteNode(node &head, int key){

    node *tmp = &head;
    node *prev= nullptr;

    while(tmp->next!=nullptr){

        if (tmp->data==key){
                prev->next = tmp->next;
                if(tmp == &head && prev==nullptr)
                    head = *tmp->next;
                else
                    head = *prev;

            delete tmp;

        }
        prev=tmp;
        tmp=tmp->next;
    }


};

node* LinkedList::Transfer(vector<int> v){
    LinkedList tmp;

    for(int i : v)
    {
        tmp.AddNode(i);
    }
    return tmp.head;

}
int LinkedList::Sum(node &head){
    int sum=0;
    node tmp = head;
    while(tmp.next!=nullptr)
    {
        sum+=head.data;
        tmp=*tmp.next;
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
    vector<int> v;
    int n;
    int number;
    cout<<"Please enter the number of numbers";
    cin>>n;
    for (int i=0;i<n;i++){
        cin >> number;
        v.push_back(number);
    }

    for(int i : v)
    cout << "i = " << i << endl;


    v =insertAfter(2,3,v);

    for (int i=0;i<n;i++){

        cout<<v[i]<<endl;
    }

}
