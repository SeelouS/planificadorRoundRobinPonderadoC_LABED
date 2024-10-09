//
// Luis Llopis, Data Structures, UMA.
//

#include "Scheduler.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct Node* Scheduler_new() {
  struct Node* p_last = NULL;
  return p_last;
}

size_t Scheduler_size(const struct Node* p_last) {
  unsigned long value = 0;
  if(p_last != NULL) {
    struct Node* aux = p_last -> p_next;
    value = value + 1;
    while(p_last != aux) {
      value = value + 1;
      aux = aux -> p_next;
    }
  }
  return value;
}

void Scheduler_clear(struct Node** p_p_last) {
  unsigned long listSize = Scheduler_size(*p_p_last);
  struct Node *auxNode;
  while (listSize > 1)
  {
    auxNode = *p_p_last;
    *p_p_last = (*p_p_last) -> p_next;
    free(auxNode);
    listSize = listSize - 1;
  }
  if(listSize == 1) {
    free(*p_p_last); //Delete the last node of the list
    *p_p_last = NULL;
  }
}

struct Task* Scheduler_first(const struct Node* p_last) {
    struct Task FirstTask = (p_last -> p_next) -> task;
  return Task_copyOf(&FirstTask);
}

void Scheduler_first_v2(const struct Node* p_last, struct Task* p_task) {
}

void Scheduler_enqueue(struct Node** p_p_last, const struct Task* p_task) {
  struct Node* p_newNode = malloc(sizeof(struct Node));
  if (p_newNode != NULL)
  {
    struct Task* p_newTask = Task_copyOf(p_task);
    p_newNode -> task = *p_newTask;
    if (*p_p_last == NULL) {
      p_newNode -> p_next = p_newNode;
    } else {
      p_newNode -> p_next = (*p_p_last) -> p_next; //Pointer of last element points to first element
      (*p_p_last) -> p_next = p_newNode;
    }
    *p_p_last = p_newNode;
  } else {
    printf("ERROR: No se ha podido crear el nodo correctamente");
  }
}

void Scheduler_dequeue(struct Node** p_p_last) {
  unsigned long sizeList = Scheduler_size(*p_p_last);
  switch (sizeList)
  {
  case 0:
    *p_p_last = NULL;
    break;
  case 1:
    free(*p_p_last);
    *p_p_last = NULL;
    break;
  default:
    struct Node* p_Aux = (*p_p_last) -> p_next;
    while (p_Aux -> p_next != *p_p_last)
    {
      p_Aux = p_Aux -> p_next;
    }
    p_Aux -> p_next = (*p_p_last) -> p_next;
    free(*p_p_last);
    *p_p_last = p_Aux;
    break;
  }
}

void Scheduler_print(const struct Node* p_last) {
  if (p_last != NULL) {
    struct Node* p_aux = p_last -> p_next;
    printf("--------------\n");
    printf(" └---> ");
    while (p_aux != p_last)
    {
      Task_print(&(p_aux -> task));
      printf(" └---> ");
      p_aux = p_aux -> p_next;
    }
    Task_print(&(p_last -> task));
    printf("\n--------------\n");
  }
  

;
}