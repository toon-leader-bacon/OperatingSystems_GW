//
//  main.c
//  Playground
//
//  Created by Arthur Bacon on 8/29/24.
//

#include <stdio.h>
#include "NocabObject.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ForkExample(void) {
    // https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf
    // Chapter 5, Page 2
    // vmmap <pid>
    printf("hello (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("child (pid:%d)\n", (int) getpid());
    } else {
        // parent goes down this path (main)
        printf("parent of %d (pid:%d)\n",
        rc, (int) getpid());
    }
    
    sleep( 100 );
    return 0;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return ForkExample();
}
