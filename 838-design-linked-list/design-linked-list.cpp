class Node{
    public:
        int data;
        Node* next;
        Node(): data(0), next(NULL) {}
        Node(int x): data(x), next(NULL) {}
        Node(int x, Node* next): data(x), next(next) {}
};
class MyLinkedList {
public:
    Node* head;
    MyLinkedList() {
        head = NULL;
    }
    int getLength(){
        int count = 0;
        Node* temp = head;
        while(temp != NULL){
            temp = temp->next;
            count++;
        }
        return count;
    }
    
    int get(int index) {
        if(index < 0) return -1;

        Node* temp = head;
        int tempIndex = 0;
        while(temp != NULL && tempIndex != index){
            temp = temp->next;
            tempIndex++;
        }
        
        if(temp == NULL) return -1;

        return temp->data;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if(head == NULL){
            head = newNode;
        }else{
            newNode->next = head;
            head = newNode;
        }
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void addAtIndex(int index, int val) {
        int length = getLength();
        if(index < 0){
            return;
        }else if(index > length){
            return;
        }else if(index == 0){
            addAtHead(val);
        }else if(index == length){
            addAtTail(val);
        }else{
            Node* newNode = new Node(val);
            Node* prev = NULL;
            Node* curr = head;
            int currIndex = 0;
            while(currIndex < index){
                prev = curr;
                curr = curr->next;
                currIndex++;
            }
            prev->next = newNode;
            newNode->next = curr;
        }
    }
    void deleteAtHead(){
        if(head == NULL) return;

        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    
    void deleteAtTail(){
        if(head == NULL) return;
        if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
            
        Node* prev = NULL;
        Node* curr = head;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }

    void deleteAtIndex(int index) {
        int length = getLength();
        if(index < 0){
            return;
        }else if(index >= length){
            return;
        }else if(index == 0){
            deleteAtHead();
        }else if(index == length - 1){
            deleteAtTail();
        }else{
            Node* prev = NULL;
            Node* curr = head;
            int currIndex = 0;
            while(currIndex < index){
                prev = curr;
                curr = curr->next;
                currIndex++;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
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