// #include <termios.h> //lib linux
#include <conio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Globais
typedef struct node{
    int item;
    struct node *link;
}Node;

Node *l1, *l2, *l3;

// Protótipos
int check(int n);
int addL1(int n);
int addL2(int n);
int addL3(int n);
int del();
void joinLists(void);

int main(){

    joinLists();

    return 0;
}

int check(int n){
    
    Node *temp;
    int r=0;

    //verificar lista 1
    if(l1 != NULL){
        temp = l1;
        while(temp->item != n && temp->link != NULL){
            temp = temp->link;
        }
        if(temp->item == n) r=1;
    }

    //verificar lista 2
    if(l2 != NULL){
        temp = l2;
        while(temp->item != n && temp->link != NULL){
            temp = temp->link;
        }
        if(temp->item == n){
            //verificar se existe nas duas listas
            if(r)r = 3;
            else r = 2;
        }
    }
    
    return r;
}

int addL1(int n){

    if(n<=0){
        return 1;
    }

    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode -> item = n;
    newNode -> link = NULL;

    if(l1 == NULL){
        l1 = newNode;
        return 0;
        //Primeiro item da lista
    }
    
    Node *lastNode = l1;
    while(lastNode->link != NULL){
        lastNode = lastNode->link;
    }
    lastNode->link = newNode;
    return 0;
}


int addL2(int n){

    if(n<=0){
        return 1;
    }

    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode -> item = n;
    newNode -> link = NULL;

    if(l2 == NULL){
        l2 = newNode;
        return 0;
        //Primeiro item da lista
    }
    
    Node *lastNode = l2;
    while(lastNode->link != NULL){
        lastNode = lastNode->link;
    }
    lastNode->link = newNode;
    return 0;
}

int addL3(int n){
    if(n<=0){
        return 1;
    }

    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    newNode -> item = n;
    newNode -> link = NULL;

    if(l3 == NULL){
        l3 = newNode;
        return 0;
        //Primeiro item da lista
    }
    
    Node *lastNode = l3;
    while(lastNode->link != NULL){
        lastNode = lastNode->link;
    }
    lastNode->link = newNode;
    return 0;
}

int del(){
    Node *temp;
    int smaller;

    if(l3 == NULL) return -1;

    smaller = l3->item;
    temp = l3;
    
    while(temp->link != NULL){
        if(temp->item < smaller){
            smaller = temp->item;
        }
        temp = temp->link;
    }

    return smaller;
}

void joinLists(void){
    Node *temp;
    int r;
    // l3 = (Node *)malloc(sizeof(Node));
    // l3 -> item = NULL;
    // l3 -> link = NULL;
    temp = l1;
    while(temp->link != NULL){
        r = check(temp->item);
        if(r != 3) addL3(temp->item);
        temp = temp->link;
    }
    temp = l2;
    while(temp->link != NULL){
        r = check(temp->item);
        if(r != 3) addL3(l2->item);
        temp = temp->link;
    }
}

// int getch(void){ // Implementação getch para linux
//     struct termios oldattr, newattr;
//     int ch;
//     tcgetattr( STDIN_FILENO, &oldattr );
//     newattr = oldattr;
//     newattr.c_lflag &= ~( ICANON | ECHO );
//     tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
//     ch = getchar();
//     tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
//     return ch;
//