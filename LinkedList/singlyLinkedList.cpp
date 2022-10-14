#include <iostream>
using namespace std;
struct ListNode{
	int data;
	ListNode *next;
};
 
ListNode* createNodeUsingMethod1(int val){
	ListNode *temp = new ListNode;
	temp->data = val;
	return temp;
}
 
ListNode* createNodeUsingMethod3(int val){
	ListNode *temp = new ListNode();
	temp->data = val;
	return temp;
}
 
 
ListNode* createNodeUsingMethod2(int val){
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->data = val;
	return node;
}
 
ListNode* createNode(int val){
	return createNodeUsingMethod3(val);
}
 
void printLinkedList(ListNode *head){
	if(head == NULL){
		cout<<"YES";
	}
	while(head!=NULL){
		cout<<head->data<<" -> ";
		head= head->next;
	}
 
	cout << "NULL" << endl;
}
int main() {
	int n; //LinkedList of Size N
	cin>>n;
	ListNode *head = NULL;
	ListNode *temp = NULL;
 
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		//if head is null then assign the value to head
		if(head==NULL){
			head= createNode(val);
			temp = head;
		}
		else{
			//temp is the end node of the linked list, new node will be next of temp
			temp->next = createNode(val);
			temp = temp->next;
		}
	}
 
	printLinkedList(head);
	return 0;
}
