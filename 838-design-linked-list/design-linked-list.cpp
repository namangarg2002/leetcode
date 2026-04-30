class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(): data(0), next(NULL), prev(NULL) {}
        Node(int x): data(x), next(NULL), prev(NULL) {}
        Node(int x, Node* next, Node* prev): data(x), next(next), prev(prev) {}
};
class MyLinkedList {
public:
    Node* head;
    Node* prev;
    MyLinkedList() {
        head = NULL;
        prev = NULL;
    }
    int getLength(){
        if(head == NULL) return 0;
        int count = 1;
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    int get(int index) {
        if(head == NULL) return -1;
        if(index < 0) return -1;

        Node* prevNode = NULL;
        Node* currNode = head;
        int currNodeIndex = 0;
        while(currNode != NULL && currNodeIndex < index){
            currNode = currNode->next;
            currNodeIndex++;
        }

        if(currNode == NULL) return -1;
        return currNode->data;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        }else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    
    void addAtIndex(int index, int val) {
        int length = getLength();
        if(index < 0) return;
        if(index > length) return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == length){
            addAtTail(val);
            return;
        }else{
            Node* newNode = new Node(val);

            Node* prevNode = NULL;
            Node* currNode = head;
            int currNodeIndex = 0;
            while(currNodeIndex < index){
                prevNode = currNode;
                currNode = currNode->next;
                currNodeIndex++;
            }
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
    void deleteAtHead(){
        if(head == NULL) return;
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    
    void deleteAtTail(){
        if(head == NULL) return;
        if(head->next == NULL){
            delete head;
            head = NULL;
            return;
        }

        Node* prevNode = NULL;
        Node* currNode = head;
        while(currNode->next != NULL){
            prevNode = currNode;
            currNode = currNode->next;
        }
        prevNode->next = NULL;
        currNode->prev = NULL;
        delete currNode;
    }

    void deleteAtIndex(int index) {
        int length = getLength();
        if(index < 0) return;
        if(index >= length) return;
        if(index == 0){
            deleteAtHead();
            return;
        }
        if(index == length-1){
            deleteAtTail();
            return;
        }else{
            Node* prevNode = NULL;
            Node* currNode = head;
            int currNodeIndex = 0;
            while(currNodeIndex < index){
                prevNode = currNode;
                currNode = currNode->next;
                currNodeIndex++;
            }
            prevNode->next = currNode->next;
            currNode->next->prev = prevNode;
            currNode->prev = NULL;
            currNode->next = NULL;

            delete currNode;

        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */