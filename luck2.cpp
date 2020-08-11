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


using namespace std;
vector <bool> casi_K(10000,0);

int limite= numeric_limits<int>::max();
vector <int> soluzione;

void possi_util2(int a,int b,int c, int LEN, int gettoni, vector <int> codice, int caso)
{
    switch (caso):
        case 0:
        for (i = a*1000+b*100+c*10; i < a*1000+b*100+c*10+10; i++)  //Provo tutte le possibilità in cui si aggiunge un gettone all'aggiunta di un numero
    {
        if(casi_K[i]==1)
        {
            int temp= i/10;
            temp= i-temp*10;
            vector <int> codice_parziale;
            codice_parziale= codice;
            codice_parziale.push_back(temp);
            possi_util(b,c,temp,LEN+1,gettoni+1,codice_parziale);
        }
    }
case 1:
    for (i = b*1000+c*100; i < b*1000+c*100+100; i++)  //Provo tutte le possibilità in cui si aggiunge un gettone all'aggiunta di 2 numeri
    {
        if(casi_K[i]==1)
        {
            int temp= i/10;
            temp= i-temp*10;
            int tempb= i/100;
            tempb= (i-tempb*100-temp)/10;
            vector <int> codice_parziale;
            codice_parziale= codice;
            codice_parziale.push_back(temp);
            possi_util(c,temp,tempb,LEN+2,gettoni+1, codice_parziale);
        }
    }
    break;
case 2:
    for (i = c*1000; i < c*1000+1000; i++)  //Provo tutte le possibilità in cui si aggiunge un gettone all'aggiunta di 3 numeri
    {
        if(casi_K[i]==1)
        {
            int temp= i/10;
            temp= i-temp*10;
            int tempb= i/100;
            tempb= (i-tempb*100-temp)/10;
            int tempc= i/1000;
            tempc= (i-tempc*1000-tempb*10-temp)/100;
            vector <int> codice_parziale;
            codice_parziale= codice;
            codice_parziale.push_back(temp);
            possi_util(c,temp,tempb,LEN+2,gettoni+1, codice_parziale);
        }
    }
    break;
case 3:
    for (i = c*1000; i < c*1000+1000; i++)  //Provo tutte le possibilità in cui si aggiunge un gettone all'aggiunta di 3 numeri
    {
        if(casi_K[i]==1)
        {
            int temp= i/10;
            temp= i-temp*10;
            int tempb= i/100;
            tempb= (i-tempb*100-temp)/10;
            int tempc= i/1000;
            tempc= (i-tempc*1000-tempb*10-temp)/100;
            vector <int> codice_parziale;
            codice_parziale= codice;
            codice_parziale.push_back(temp);
            possi_util(c,temp,tempb,LEN+2,gettoni+1, codice_parziale);
        }
    }
    break;

}

void possi_util(int a,int b,int c, int LEN, int gettoni, vector <int> codice)
{
    switch (LEN-C):
        case 0:
        if(gettoni<limite)
    {
        soluzione= codice;
        limite= gettoni;
    }
    break;
case 1:
    if(gettoni<limite)
    {
        soluzione= codice;
        soluzione.push_back(0);
        limite= gettoni;
    }
    possi_util2(a,b,c,LEN,gettoni,codice,0);
    break;
case 2:
    if(gettoni<limite)
    {
        soluzione= codice;
        soluzione.push_back(0);
        soluzione.push_back(0);
        limite= gettoni;
    }
    possi_util2(a,b,c,LEN,gettoni,codice,0);
    possi_util2(a,b,c,LEN,gettoni,codice,1);
    break;
case 3:
    if(gettoni<limite)
    {
        soluzione= codice;
        soluzione.push_back(0);
        soluzione.push_back(0);
        soluzione.push_back(0);
        limite= gettoni;
    }
    possi_util2(a,b,c,LEN,gettoni,codice,0);
    possi_util2(a,b,c,LEN,gettoni,codice,1);
    possi_util2(a,b,c,LEN,gettoni,codice,2);
    break;
}

void possi (int stringa)
{
    vector <int> codice_parziale;

    int temp= stringa/10;
    temp= stringa-temp*10;
    int tempb= stringa/100;
    tempb= (stringa-tempb*100-temp*10)/10;
    int tempc= stringa/1000;
    tempc= (stringa-tempc*1000-tempb*10-temp)/100;
    int tempd= (stringa-tempc*100-tempb*10-temp)/1000;

    codice_parziale.push_back(temp);
    codice_parziale.push_back(tempb);
    codice_parziale.push_back(tempc);
    codice_parziale.push_back(tempd);

    possi_util(tempb, tempc, tempd, 4, 1, codice_parziale);
}

int main()
{
    //  uncomment the following lines if you want to read/write from files
    freopen("input0.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>K>>C;

    int L[K];
    for (i = 0; i < K; i++)
    {
        cin>>L[i];
        casi_K[L[i]]=true;
        /*if(L[i][0]==L[i][1]&&L[i][1]==L[i][2]&&L[i][2]==L[i][3]){
            printf("%s\n", string(L[i][0],C));
            return 0;
        }*/
    }
    for (i = 0; i < casi_K.size(); i++)
    {
        if(casi_K[i])
            possi(L[i]);
    }
    long long soluzione_finale=0;
    for (i = 0; i < soluzione.size(); i++)
        soluzione_finale= soluzione_finale*10+soluzione[i];

    cout << soluzione_finale << endl;  // change 42 with actual answer
    return 0;
}
