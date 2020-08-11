/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>


// constraints
#define MAXK 200
#define MAXC 10000

// input data
int K, C, i;
char carattere_iniziale;


using namespace std;
vector <bool> casi_K(10000,0);
int limite= numeric_limits<int>::max();

vector <vector <int> > prove(2);

void possi_util(char a,char b,char c, int LEN, int gettoni){
    if(LEN==C && gettoni<(limite-1)){

    }
    for (i = a*1000+b*100+c*10; i < a*1000+b*100+c*10+10; i++){ //Provo tutte le possibilitÓ in cui si aggiunge un gettone all'aggiunta di un numero
        if(L[i]==1){
            int temp= L[i]/10;
            temp= L[i]-temp*10;
            possi_util(b,c,temp,LEN+1,gettoni+1);
        }
    }
    if(LEN+1<C){
        for (i = b*1000+c*100; i < b*1000+c*100+100; i++){ //Provo tutte le possibilitÓ in cui si aggiunge un gettone all'aggiunta di 2 numeri
            if(L[i]==1){
                int temp= L[i]/10;
                temp= L[i]-temp*10;
                int tempb= L[i]/100;
                tempb= (L[i]-tempb*100-temp)/10;
                possi_util(c,temp,tempb,LEN+2,gettoni+1);
            }
        }
    }
    if(LEN+2<C){
        for (i = c*1000; i < c*1000+1000; i++){ //Provo tutte le possibilitÓ in cui si aggiunge un gettone all'aggiunta di 3 numeri
            if(L[i]==1){
                int temp= L[i]/10;
                temp= L[i]-temp*10;
                int tempb= L[i]/100;
                tempb= (L[i]-tempb*100-temp*10)/10;
                int tempc= L[i]/1000;
                tempc= (L[i]-tempc*1000-tempb*100-temp*10)
                possi_util(c,temp,tempb,LEN+2,gettoni+1);
            }
        }
    }
}

int possi (string stringa){
    carattere_iniziale=stringa[0];
    possi_util(stringa[1],stringa[2],stringa[3], 4, 1);
    return 0
}

int main() {
  //  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);
    cin>>K>>C;

  string L[K];
  for (i = 0; i < K; i++){
        cin>>L[i];
        casi_K[L[i]]=1;
        /*if(L[i][0]==L[i][1]&&L[i][1]==L[i][2]&&L[i][2]==L[i][3]){
            printf("%s\n", string(L[i][0],C));
            return 0;
        }*/
  }
  for (i = 0; i < K; i++)
    int gettoni= possi(L[i]);

  printf("%d\n", 42);  // change 42 with actual answer
  return 0;
}
