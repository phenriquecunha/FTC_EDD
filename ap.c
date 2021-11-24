// #include <termios.h> //lib linux
#include <conio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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
int del(void);
void joinLists(void);
void loading(void);

int main(){
    int r = 0;
    int count = 0;
    int total = 0;
    int itemDeleted = 0;

    while(r != -1){
        system("cls");
        printf("Digite os inteiros do conjunto A: (digite -1 para ir ao proximo conjunto)\n");
        scanf("%d",&r);
        if(r > 0) addL1(r);
    }
    r = 0;
    while(r != -1){
        system("cls");
        printf("Digite os inteiros do conjunto B: (digite -1 para ir ao proximo conjunto)\n");
        scanf("%d",&r);
        if(r > 0) addL2(r);
    }
    joinLists();
    loading();

    printf("- Elementos do conjunto C -\n");
    while(l3 != NULL){
        itemDeleted = del();
        if(itemDeleted != -1){
            printf("%d, ", itemDeleted);
            total += itemDeleted; // Somatório dos itens
            count++; // Contagem dos itens
        }
    }

    total = total / count; // Cáculo da média

    printf("\n Media do conjunto C => %d", total);

    getch();
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
    Node *prev;
    Node *next;
    int smaller;

    // Caso a lista esteja vazia
    if(l3 == NULL) return -1;

    smaller = l3->item;
    temp = l3;
    
    if(l3->link == NULL){
        // Verifica se há apenas 1 item na lista para retornar este único item e deixar a lista vazia 
        l3 == NULL;
        return smaller;
    }

    // Verifica qual o elemento de menor valor
    while(temp->link != NULL){
        if(temp->item < smaller){
            smaller = temp->item;
            next = temp->link;
        }
        temp = temp->link;
    }

   // Retira o nó pertencente ao menor valor da lista 
    temp = l3;
    while(temp->link != NULL){
        if(temp->item == smaller){
            prev->link = next;
        }
        prev = temp;
        temp = temp->link;
    }
    temp = NULL;
    return smaller;
}

void joinLists(void){
    Node *temp;
    int r;

    // Verifica a lista 1
    temp = l1;
    while(temp->link != NULL){
        r = check(temp->item);
        if(r != 3) addL3(temp->item);
        temp = temp->link;
    }

    // Verifica a lista 2
    temp = l2;
    while(temp->link != NULL){
        r = check(temp->item);
        if(r != 3) addL3(l2->item);
        temp = temp->link;
    }
}

void loading(){
    system("cls");
    printf("Gerando conjunto C  [          ]");
    Sleep(1000);
    system("cls");
    printf("Gerando conjunto C  [=         ]");
    Sleep(1000);
    system("cls");
    printf("Gerando conjunto C  [==        ]");
    Sleep(1000);
    system("cls");
    printf("Gerando conjunto C  [===       ]");
    Sleep(800);
    system("cls");
    printf("Gerando conjunto C  [====      ]");
    Sleep(600);
    system("cls");
    printf("Gerando conjunto C  [=====     ]");
    Sleep(1000);
    system("cls");
    printf("Gerando conjunto C  [======    ]");
    Sleep(1000);
    system("cls");
    printf("Gerando conjunto C  [=======   ]");
    Sleep(500);
    system("cls");
    printf("Gerando conjunto C  [========  ]");
    Sleep(1000);
    system("cls");
    printf("Gerando conjunto C  [========= ]");
    Sleep(1000);
    system("cls");
    printf("Gerando conjunto C  [==========]");
    Sleep(1000);
    system("cls");
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