/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <assert.h>
#include <stdio.h>
#include <string>


// constraints
#define MAXK 200
#define MAXC 10000

// input data
int K, C, i;

    using namespace std;

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  assert(2 == scanf("%d %d", &K, &C));
  int L[K];
  for (i = 0; i < K; i++){
        assert(1 == scanf("%d", &L[i]));
        if(L[i]%1111==0){
            string a= to_string(L[i]/1000);
            printf("%s\n", string(a,C));
            return 0;
        }
  }





  // insert your code here


  printf("%d\n", 42);  // change 42 with actual answer
  return 0;
}
