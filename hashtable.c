#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct table {
    char ticket_id[100];
    char helptopic[100];
    char issue_summary[100];
    char problem_explaination[500];
    char location[100];
    char Department_Hostel[100];
    char mobilelenumber[100];
    char preferred_time[100];
    struct ticket_details *next;
};
unsigned int hash(char *ticket_id) {
    unsigned int hash_value = 0;
    for (int i=0;i<strlen(ticket_id);i++) {
        hash_value+=(ticket_id[i]-(4*i)%10)*(i+1)*9-i*i;
    }
    return hash_value;
}

int main() {
    printf("%d\n", hash("AC-101"));
    printf("%d\n", hash("AC-102"));
    printf("%d\n", hash("AC-103"));
    printf("%d\n", hash("AC-110"));
    printf("%d\n", hash("AC-200"));

    printf("%d\n", hash("PL-001"));
    printf("%d\n", hash("PL-015"));
    printf("%d\n", hash("PL-120"));

    printf("%d\n", hash("EL-050"));
    printf("%d\n", hash("EL-075"));
    printf("%d\n", hash("EL-999"));

    printf("%d\n", hash("IT-001"));
    printf("%d\n", hash("IT-250"));
    printf("%d\n", hash("IT-404"));

    printf("%d\n", hash("ME-010"));
    printf("%d\n", hash("ME-111"));
    printf("%d\n", hash("ME-500"));

    printf("%d\n", hash("CS-101"));
    printf("%d\n", hash("CS-202"));
    printf("%d\n", hash("CS-303"));
}

