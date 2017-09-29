#include <stdio.h>
#include <stdlib.h>

struct Node{
   int data;
   struct Node *next;
};

//struct Node *indertOrdered(struct Node, int);
//struct Node *deleteNode(struct Node, int);

struct Node *insertOrdered(struct Node* head, int data){
   struct Node *ptr, *ptr2;
   
   if(head== NULL){ // list is empty
	head= malloc(sizeof(struct Node)); //create new node
	(*head).data=data; //make new node head of LL 
	(*head).next=NULL; //head node points to NULL
     
	}else if
	   (data < (*start).data){ //value of new node is less than head node
	   struct Node *nextNode =malloc(sizeof(struct Node)); //create new node
	   (*nextNode).data=data; // new node data is set to incoming data
	   (*nextNode).next=head; // new node link points to head, head link still points to NULL
	return nextNode; //returns LL with new head
      }else{
	ptr = head; //set pointer to beginning of LL
	
	while(ptr != NULL){ //iterates  pointer through LL
	 if(data < (*ptr).data){//finds where greater value node then insert before
	      struct Node *newNode =malloc(sizeof(struct Node)); //create node
	      (*newNode).data = data; //newNode data is set to incoming data
	      (*newNode).next = (*ptr).next;
	      (*ptr).next = newNode;
	      return head;
	    }else if(data == (*ptr).data){ // node with data already in LL
			return head; //silently ignore and return LL
		    }
	ptr2 = ptr;
	ptr = (*ptr).next;
       }

	struct Node *santoshNode = malloc(sizeof(struct Node));
	(*santoshNode).data=data;
	(*santoshNode).next=NULL;
	(*ptr2).next=santoshNode;
	
	return head;
	} 
	     
}	

struct Node *deleteNode(struct Node *head, int data){
   struct Node *ptr = head;
   struct Node *ptr2 = head;

   if(data == (*head).data){//node has same value as head
	return (*head).next;//deletes link to first node
	}
   if(head == NULL){ //case where list is empty
	return head; //return empty list
   }

   while(ptr != NULL){
	if(data == (*ptr).data){
		(*ptr2).next = (*ptr).next;
		return head;
		}
	ptr2 = ptr;
	ptr2 = (*ptr2).next;
return head;
}

}



int main(int argc, char** argv){
    struct Node *head;
    
    /*If no file was inputed*/
    if (argc != 2){
        return 0;
    }
    
    FILE *inputFile = fopen(argv[1], "r");
    char action;
    int num;
    
   // File doesn't exist
  if (inputFile == NULL){
        printf("error\n");
        return 0;
    }
    
    while(fscanf(inputFile, "%c %d\n", &action, &num) == 2 ){
        if(action == 'i'){
            head = insertOrdered(head, num);
        }
        
        else if(action == 'd'){
            head = deleteNode(head, num);
        }
        
        else {
            printf("error");
            return 0;
        }
   }

    if(!feof(inputFile)){
      printf("error");
      return 0;
    }
    
    while (head != NULL){
      printf("%d\t", head->data);
      head = head->next;
    }
    
    fclose(inputFile);
    free(head);
    return 0;    
}
