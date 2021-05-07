#include<bits/stdc++.h>
using namespace std;

int randint(int a, int b){
    return a + rand() % (b - a + 1);
}

char randchar(char a, char b){
    return (char) a + randint(0,b-a);
}

int main(int argc, char* argv[]){
    // TODO
    // use gen.exe > inp.txt to redirect output into the file.
    // use a.exe < inp.txt to take input from inp.txt
    srand(atoi(argv[1]));
    for(int i=0;i<2;i++){
        cout << randint(1,10) << endl;
        cout.flush();
    }
    return 0;
}