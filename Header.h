#define Header_h

using namespace std;
struct node{
    int data;
    struct node *next;
};
class LinkedList{
public:
    node *head, *tail;

    LinkedList();
    ~LinkedList();
    void AddNode(int n);
    void DeleteNode(node **head, int key);
    void print (node *head );
    int Sum(node **head);
    LinkedList Transfer(vector<int> v);
};
