#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cstring>
using namespace std;
char words[30][100];
char temp[10];
int n;

string lower(string word){ //a function to change the input string to lower (in order to compare lexicographically)
    string changed;
    for (int i = 0; i < word.size(); i++){
        changed += (word[i] >= 'A' && word[i] <= 'Z') ? word[i] + int('a'-'A') : word[i];
    }
    return changed;
}
int main(){
    string inp;
    int n = 0;
    cin >> inp;
    while (inp != "???"){
        for (int i = 0; i < inp.size(); i++){
            words[n][i] = inp[i];
        }
        cin >> inp;
        n++;
    }
    for (int i = n-1; i > 0; i--){
        for (int j = 0; j < i; j++){
          //swap when words[j+1] is longer, and when words[j] and words[j+1] are equal, compare it lexicographically
            if (strlen(words[j]) < strlen(words[j+1]) || (strlen(words[j]) == strlen(words[j+1]) && lower(string(words[j]))> lower(string(words[j+1]))) == 1){
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1],temp);
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << words[i] << endl;
    }
}
