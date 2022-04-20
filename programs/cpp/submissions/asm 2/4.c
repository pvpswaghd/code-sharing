#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char str[31], temp;
    int odd, even;
    scanf("%s", str);
    int point = strlen(str)-1;
    for (int i = 0; i<point; i++){ //reverse the string
        temp = str[i];
        str[i] = str[point];
        str[point] = temp;
        point--;
    }
    printf("%s\n", str); //print out the reversed string
    odd = 0, even = 0;
    for (int i = 0; i < strlen(str); i++){ //calculate the odd
        odd += str[i] - '0'; //convert string into int
        i++; //to ensure the for loop takes odd number
    }
    for (int i = 1; i < strlen(str); i++){
        int x = (str[i] - '0') * 2;
        if(x >= 10){
            even += (x/10); //to find the tenth digit 
            even += (x%10); //to find the single digit
        }
        else even+=x;
        i++;
    }
    printf("%d %d\n", odd, even); //print the odd and even sum result
    if((odd+even) % 10 == 0) printf("valid\n");
    else printf("invalid\n");

}
