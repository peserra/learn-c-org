#include <_stdio.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_errno_t.h>

// -fsanitize=adress
typedef struct node node_t;

struct node {
  int8_t value;
  node_t *next;
};

void print_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf("%d", current->value);
    current = current->next;
  }
}

void append_list(node_t *head, int8_t n) {
  node_t *current = head;
  while (current != NULL)
    current = current->next;
  node_t *newNode = malloc(sizeof(node_t));
  newNode->value = n;
  newNode->next = NULL;
  current->next = newNode;
}

node_t *push_list(node_t *head, int8_t n) {
  node_t *newNode = malloc(sizeof(node_t));
  if (newNode == NULL)
    return head;
  newNode->value = n;
  newNode->next = head;
  return newNode;
}

int8_t pop_list(node_t **head) {
  if (head == NULL)
    return -1;
  node_t *newHead = (*head)->next;
  int8_t val = (*head)->value;
  free(*head);
  *head = newHead;
  return val;
}

int8_t return_last_list(node_t *head) {
  int8_t return_value;
  if (head->next == NULL) {
    return_value = head->value;
    free(head);
    return return_value;
  }

  node_t *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  return_value = current->next->value;
  free(current->next);
  current->next = NULL;
  return return_value;
}

int8_t remove_by_index(node_t **head, int8_t index) {
  int8_t curr_index = 0;
  int8_t return_value;

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
  return_value = temp_node->value;
  current_node->next = temp_node->next;
  free(temp_node);
  return return_value;
}

int return_by_value(node_t **head, int val){
  if (*head == NULL){
    return -1;
  }

  node_t *current_node = *head;
  node_t *temp_node = NULL;

  if(current_node->value == val){
    return pop_list(head);
  }
  /*TODO: deal with edge cases */
  return 0;  
}


int main() {
  node_t *head = NULL;
  head = malloc(sizeof(node_t));
  if (head == NULL)
    return 1;
  head->value = 1;
  head->next = NULL;
  return 0;
}
