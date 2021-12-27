#include "types.h"
#include "stat.h"
#include "user.h"

void
run(void* arg)
{
  int id = *(int*) arg;
  id++;
  int i;
  sleep(100);
  for( i = 0 ; i < 3 ; i++){
    printf(1, "thread with id : %d  print %d\n", id, i);
    sleep(100);
  }
  printf(1, "Thread with id : %d finished\n", id);
  exit();
}


void
test(int n)
{
  int i,tid;
  for (i = 0; i < n; i++) {
    tid = thread_creator(run, &i);
    sleep(10);
    if (tid < 0) 
      printf(1, "thread create is failed\n");
    else {
      printf(1, "thread %d is created\n",i+1);
      sleep(10);
    }
  }
  
  // thread_wait or wait
  for (i = 0; i < n ; i++) {
    tid = thread_wait();
  }
  printf(1, "all threads joined\n");
}

int
main(int argc, char *argv[]){
   test(2);
   exit();
}