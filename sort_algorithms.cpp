#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

void print(int* S, int n){               //wyœwietla dane

    for(int i=0; i<n;i++){
        cout<<S[i]<<" ";
    }

    cout<<endl;
}

void init(int* S, int n){               //generuje losowe dane
    srand (time(NULL));
    for(int i=0; i<n; i++){
        S[i]=rand()%9;
    }
}

void insertionSort(int* S, int n){
    int aux=0;
    int j;
    for(int i=1; i<n; i++){
        aux=S[i];//pomocnicze liczba przed czêœci¹ uporz¹dkowan¹

        for(j=i-1; j>=0; j--){
            if(S[j]>aux){ // Kolejna liczb¹ mniejsza wiêc szukamy jej miejsca
                S[j+1]=S[j];
            }
            else{  //zakoncz jezeli kolejna jest wiêksza
                break;
            }
        }
        S[j+1]=aux;
    }
}

void selectionSort(int* S, int n){
    int min=0;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(S[j]<S[min]){
                min=j;
            }
        }
        swap(S[i],S[min]);
    }
}

void bubbleSort(int* S, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(S[j]<S[i]){
                swap(S[j],S[i]);
            }
        }
    }
}

int dzielenie(int* S, int start, int koniec) // zakładamy tutaj że idziemy zawsze od lewej
{
    int count=0; //pozycja na ktorej powinien byc pivot
    int pivot = S[(start+koniec)/2];

    for(int i=0;i<(start+koniec)/2;i++)//po prawej stronie powinny być większe
    {
        if(pivot>=S[i]){
            count++;
        }
    }

    for(int i=((start+koniec)/2)+1;i<=koniec;i++)//po prawej stronie powinny być większe
    {
        if(pivot>=S[i]){
            count++;
        }
    }

    int pivotIndex=count;
    swap(S[pivotIndex], S[(start+koniec)/2]);

    int begginig=start;
    int end=koniec;

    while(begginig<pivotIndex && end>pivotIndex){

        while(S[begginig]<=S[pivotIndex]){
            begginig++;
        }

        while(S[end]>S[pivotIndex]){
            end--;
        }

        if(begginig<pivotIndex && end>pivotIndex){
            swap(S[begginig],S[end]);
            begginig++;
            end--;
        }
    }
    return pivotIndex;
}

void quickSort(int* S, int start, int koniec){
    if(start<koniec){
        int index = dzielenie(S,start,koniec);
        quickSort(S,start,index-1);
        quickSort(S,index+1,koniec);
    }
}


void cntSort(int* S, int n)
{
    int max=0;
    int tab_pomoc[n];

    for(int i=0;i<n;i++){ //pierwszy krok to znalezienie największego elementu
        if(S[i]>max){
            max=S[i];
        }
        tab_pomoc[i]=S[i];
    }

    int tab[max+1]{0}; //następnie stworzenie tablicy o rozmiarze max+1


    for(int i=0; i<n ; i++){ //znajdujemy ile czego jest np. tab[4]++; tab[0]++;
        tab[S[i]]++;
    }

    for(int i=0;i<max+1;i++){ //wypisujemy
        cout<<tab[i]<< " ";
    }

    for(int i=1; i<=max; i++){ //sumujemy po kolei
        tab[i]=tab[i-1]+tab[i];
    }

    cout<<endl;
    for(int i=0;i<max+1;i++){ //wypisujemy
        cout<<tab[i]<< " ";
    }

   for(int i=n-1; i>=0; i--){
        S[tab[tab_pomoc[i]]-1] = tab_pomoc[i];

        tab[tab_pomoc[i]]--;
   }
}



int main(){
    int n=10;
    int *S=new int(n);
    init(S,n);
    print(S,n);
    cout<<endl;
    cntSort(S,n);
    cout<<endl;
    cout<<endl;
    print(S,n);
}
