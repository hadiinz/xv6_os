#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
    getHello();
    printf(1,"successful hello\n"); 
    fork();
    getProcCount();
    exit();
}