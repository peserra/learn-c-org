#include <stdio.h>
#include <stdlib.h>
// -fsanitize=adress
typedef struct node node_t;

struct node {
  int val;
  node_t *next;
};

void print_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf("%d ", current->val);
    current = current->next;
  }
}

void append_list(node_t **head, int n) {
  node_t *newNode = malloc(sizeof(node_t));
  if(newNode == NULL) return;
  newNode->val = n;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  node_t *current = *head;
  while (current->next != NULL)
    current = current->next;

  current->next = newNode;
}

node_t *push_list(node_t *head, int n) {
  node_t *newNode = malloc(sizeof(node_t));
  if (newNode == NULL)
    return head;
  newNode->val = n;
  newNode->next = head;
  return newNode;
}

int pop_list(node_t **head) {
  if (head == NULL)
    return -1;
  node_t *newHead = (*head)->next;
  int val = (*head)->val;
  free(*head);
  *head = newHead;
  return val;
}

int return_last_list(node_t *head) {
  int return_val;
  if (head->next == NULL) {
    return_val = head->val;
    free(head);
    return return_val;
  }

  node_t *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  return_val = current->next->val;
  free(current->next);
  current->next = NULL;
  return return_val;
}

int remove_by_index(node_t **head, int index) {
  int curr_index = 0;
  int return_val;

  node_t *current_node = *head;
  node_t *temp_node = NULL;

  if (index == 0)
    return pop_list(head);
  while (curr_index < index - 1) {
    if (current_node->next == NULL)
      return -1;
    current_node = current_node->next;
    curr_index++;
  }

  if (current_node->next == NULL)
    return -1;

  temp_node = current_node->next;
  return_val = temp_node->val;
  current_node->next = temp_node->next;
  free(temp_node);
  return return_val;
}

int remove_by_value(node_t **head, int val){
  if (*head == NULL){
    return -1;
  }
  node_t *current_node = *head;
  node_t *temp_node = NULL;
  // retorna primeiro elemento
  if (current_node->val == val){
    return pop_list(head);    
  }  

  while(current_node->next->val != val){
    if (current_node->next == NULL) {
      return -1;
    }
    current_node = current_node->next;
  }

  int return_val = current_node->next->val;
  temp_node = current_node->next;
  current_node->next = temp_node->next;
  free(temp_node);
  return return_val;  
}


int main() {

  node_t *test_list= NULL;
  append_list(&test_list, 1);
  append_list(&test_list, 2);
  append_list(&test_list, 3);
  append_list(&test_list, 4);
  remove_by_value(&test_list, 3);
  print_list(test_list);
}
