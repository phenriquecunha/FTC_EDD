//#include <termios.h> //lib linux
//#include <conio.h>
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
Node joinLists();

int main(){

    int test;

    addL1(5);
    addL1(10);
    addL1(15);
    test = check(10);
    test = check(2);

    return 0;
}

int check(int n){
//FIXME While de verificação não funciona caso a lista esteja vazia
    
    Node *temp;
    int r=0;

    //verificar lista 1
    temp = l1;
    while(temp->item != r && temp->link != NULL){
        temp = temp->link;
    }
    if(temp->item == r) r=1;

    //verificar lista 2
    temp = l2;
    while(temp->item != r && temp->link != NULL){
        temp = temp->link;
    }
    if(temp->item == r){
        //verificar se existe nas duas listas
        if(r)r = 3;
        else r = 2;
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
// }