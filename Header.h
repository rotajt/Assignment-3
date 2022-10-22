#define Header_h

using namespace std;
struct node{
    int data;
    struct node *next;
};
class LinkedList{
private:
    node *head, *tail;
public:
    LinkedList();
    void AddNode(int n);
    void RemoveNode(int n);
    void DeleteNode(node &head, int key);
    void print (node *head );
    int Sum(node &head);
    node* Transfer(vector<int> v);
};
