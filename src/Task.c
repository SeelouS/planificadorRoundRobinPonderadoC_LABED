//
// Luis Llopis, Data Structures, UMA.
//

#include "Task.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char DEFAULT_NAME[] = "ERR: LONG_NAME";

struct Task* Task_new(unsigned int id, const char* name, int quantum) {
  struct Task* newTaskPointer = malloc(sizeof(struct Task));
  if(newTaskPointer != NULL) {
    newTaskPointer -> id = id;
    newTaskPointer -> quantum = quantum;
    if(strlen(name) > MAX_NAME_LEN){
      strcpy(newTaskPointer -> name, DEFAULT_NAME);
    }
    else{
      strcpy(newTaskPointer -> name, name);
    }
  }
  return newTaskPointer;
}

void Task_free(struct Task** p_p_task) {
  if(p_p_task != NULL && *p_p_task != NULL) {
    free(*p_p_task);
    *p_p_task = NULL;
  }
}

struct Task* Task_copyOf(const struct Task* p_task) {
  if(p_task != NULL) {
    return Task_new(p_task -> id, p_task -> name, p_task -> quantum);
  }
  return NULL;
  ;
}

void Task_print(const struct Task* p_task) {
  if(p_task != NULL){
    printf("ID: %d\nTASK NAME: %s\nQUANTUM: %d\n", p_task -> id, p_task -> name, p_task -> quantum);
  }
}