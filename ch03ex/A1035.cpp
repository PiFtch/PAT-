/*
1035 Password（20 分）

To prepare for PAT, the judge sometimes has to generate random passwords for the users. The problem is that there are always some confusing passwords since it is hard to distinguish 1 (one) from l (L in lowercase), or 0 (zero) from O (o in uppercase). One solution is to replace 1 (one) by @, 0 (zero) by %, l by L, and O by o. Now it is your job to write a program to check the accounts generated by the judge, and to help the juge modify the confusing passwords.
Input Specification:

Each input file contains one test case. Each case contains a positive integer N (≤1000), followed by N lines of accounts. Each account consists of a user name and a password, both are strings of no more than 10 characters with no space.
Output Specification:

For each test case, first print the number M of accounts that have been modified, then print in the following M lines the modified accounts info, that is, the user names and the corresponding modified passwords. The accounts must be printed in the same order as they are read in. If no account is modified, print in one line There are N accounts and no account is modified where N is the total number of accounts. However, if N is one, you must print There is 1 account and no account is modified instead.
Sample Input 1:

3
Team000002 Rlsp0dfa
Team000003 perfectpwd
Team000001 R1spOdfa

Sample Output 1:

2
Team000002 RLsp%dfa
Team000001 R@spodfa

Sample Input 2:

1
team110 abcdefg332

Sample Output 2:

There is 1 account and no account is modified

Sample Input 3:

2
team110 abcdefg222
team220 abcdefg333

Sample Output 3:

There are 2 accounts and no account is modified

*/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
struct user {
    char name[11];
    char pswd[11];
};
vector<user> output;
bool judge(char str[], int len) {
    bool flag = true;
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case '1': str[i] = '@'; flag = false; break;
            case '0': str[i] = '%'; flag = false; break;
            case 'l': str[i] = 'L'; flag = false; break;
            case 'O': str[i] = 'o'; flag = false; break;
            default: break;
        }
    }
    return flag;
}
int main() {
    char name[11], pswd[11];
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", name, pswd);
        if (!judge(pswd, strlen(pswd))) {
            count++;
            user temp;
            strcpy(temp.name, name);
            strcpy(temp.pswd, pswd);
            output.push_back(temp);
        }
    }
    if (count > 0) {
        printf("%d\n", count);
        for (int i = 0; i < count; i++) {
            printf("%s %s\n", output[i].name, output[i].pswd);
        }
    } else if (n > 1) {
        printf("There are %d accounts and no account is modified\n", n);
    } else {
        printf("There is 1 account and no account is modified\n");
    }
}