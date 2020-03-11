#include <iostream>

#include <stdlib.h>

#include <string.h>

using namespace std;

int main(){

 char b[13];

 int a[13];

 strcpy(b, "6661311");

 for(int z=0; z<7; z++){

  a[z] = (int) b[z][color=red]-'0'[/color]; //konversi char ke int

  cout<<a[z];

    }

 return 0;

}