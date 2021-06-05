// SHORTEST JOB FIRST
#include <stdio.h>
#include <stdlib.h>

struct node {
    int pid;
    int burst_time;
    int wait_time;
    int tat;
    struct node *next;
}*head = NULL, *ptr;

void swap(struct node *a, struct node *b){
    int pid = a->pid;
    int burst = a->burst_time;
    int wait = a->wait_time;
    int tat = a->tat;
    a->pid = b->pid;
    a->burst_time = b->burst_time;
    a->wait_time = b->wait_time;
    a->tat = b->tat;
    b->pid = pid;
    b->burst_time = burst;
    b->wait_time = wait;
    b->tat = tat;
}

void sort(){
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
  
    /* Checking for empty list */
    if (head == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = head;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->burst_time > ptr1->next->burst_time)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

void insertbeg(int id, int bt){
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->pid = id;
    temp->burst_time = bt;
    temp->wait_time = 0;
    temp->tat = 0;
    temp->next = head;
    head = temp;
}

void printDetail(){
    printf("Processes\tBurst time\tWaiting time\tTurn around time\n");
    for(ptr = head; ptr != NULL; ptr = ptr->next){
        printf("%d ",ptr->pid);
        printf("\t\t%d ", ptr->burst_time );
        printf("\t\t%d", ptr->wait_time);
        printf("\t\t%d\n", ptr->tat);
    }
}

int main(){
    printf("Enter number of processes: ");
    int n; 
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int b_time;
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &b_time);
        insertbeg(i+1, b_time);
    }
    sort();
    for (ptr = head; ptr != NULL; ptr=ptr->next)
    {
        if(ptr->next != NULL){
            ptr->next->wait_time = ptr->burst_time + ptr->wait_time;            
        }
        ptr->tat = ptr->wait_time + ptr->burst_time;
    }
    
    printDetail();
    return 0;
}