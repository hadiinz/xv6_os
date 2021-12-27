#include "types.h"
#include "stat.h"
#include "user.h"

#define PAGESIZE  4096

int
thread_creator(void (*fn) (void *), void *arg)
{
//create pagealined stack
// allocate 2 * pageSize for fptr in parent's heap
void *fptr = malloc(2 * (PAGESIZE));
void *stack;

//if cant allocate
if(fptr == 0)
return -1;

int mod = (uint)fptr % PAGESIZE;

// if mod==0 means fptr is pagealined
if(mod == 0)
  stack = fptr;
  
//fptr is not pagealined then we modify it to pagealined
else
  stack = fptr + (PAGESIZE - mod);

int thread_id = thread_create((void*)stack);

// threadCreate failed
if(thread_id < 0)
    printf(1, "thread_create failed\n");
    
// thread successfully id created
else if(thread_id == 0){

    // call the function passed to thread_creator
    (fn)(arg);
    // free stack's space after finish the function
    free(stack);
    exit();
}
    return thread_id;

}