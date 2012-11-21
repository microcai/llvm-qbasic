#include <stdio.h>

 int fibonacci(n) {
     if (n < 2) {
         return n;
     }else{
         int prev=0, curr=1, tmp, idx;
         for(idx=2; idx<=n; idx++){
             tmp = prev;
             prev = curr;
             curr = tmp + prev;
         }
         return curr;
     }
 }

  int main() {
      printf("%d\n", fibonacci(36));
      return 0;
  }
