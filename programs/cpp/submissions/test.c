#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getCourseName(char a, char* b)
{
    if(strcmp(a, "CSIS1122") == 0) {strcpy(b, "Computer PRogramming II");}
    else strcpy(b, "Hello");
}

int main(){
    char courseCode;
    char courseName[] = "hi";
    printf("What is the course code?\n%s   %s", courseCode, courseName);
    scanf("%s", courseCode);
    getCourseName(courseCode, courseName);
    printf("%s-%s", courseCode);


}

