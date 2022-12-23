#include <stdio.h>
#include <stdlib.h>

#define boolean int
#define TRUE 1
#define FALSE 0

typedef struct{
    unsigned int id, day, month, year;
    char name[30];
}PERSON;

typedef struct Node{
    PERSON person;
    struct Node *next;
}NODE;

typedef struct{
    NODE *top;
    unsigned int size;
}STACK;

void clearBuffer(){
    char ch;
    do{
        ch = getchar();
    }while(ch != '\n');
}

boolean checkRange(int num, int min, int max){
    return (num >= min && num <= max) ? TRUE : FALSE;
}

int readInt(int min, int max, char msg[]){
    int number, ret;
    do{
        printf("%s", msg);
        ret = scanf("%d", &number);
        clearBuffer();
        if(ret != 1)
            continue;
    }while(checkRange(number, min, max) == FALSE);
    return number;
}


//##################    PERSON HANDLE   ################
void readPerson(PERSON *p, int *id){
    p->id = (*id)++;
    printf("Enter a name: ");
    scanf("%50[^\n]", p->name);
    p->day = readInt(0, 150, "Enter a day..: ");
    p->month = readInt(0, 12, "Enter a month: ");
    p->year = readInt(1900, 2022, "Enter a year.: ");
}

void showPerson(PERSON p){
    printf("%2d - %02d/%02d/%4d - %s\n", p.id, p.day, p.month, p.year, p.name);
}


// #############################   STACK ##################################

void erroAlloc(){
    printf("\nError in memory allocation\n");
}

void startStack(STACK *stack){
    stack->top = NULL;
    stack->size = 0;
}

void push(STACK *stack, PERSON person){
    NODE *new = malloc(sizeof(NODE));
    if(new){
        new->person = person;
        new->next = stack->top;
        stack->top = new;
        stack->size++;
    }
    else
        erroAlloc();
}

void pop(STACK *stack){
    if(stack->top){
        printf("Removed Person\n");
        showPerson(stack->top->person);
        stack->top = stack->top->next;
        stack->size--;
    }
    else
        printf("STACK IS EMPTY\n");
}

void showStack(STACK stack){
    printf("============= STACK %2d ============\n", stack.size);
    printf("\tID - BIRTH DATE - NAME\n");
    while(stack.top){
        putchar('\t');
        showPerson(stack.top->person);
        stack.top = stack.top->next;
    }
    printf("=============== END ===============\n");
}


// ####################### FILE ######################
void writeFile(char filename[], STACK stack, int ids){
    FILE *file = fopen(filename, "w");
    if(file){
        fprintf(file, "%d\n", ids);
        while(stack.top){
            fprintf(file, "%d\n", stack.top->person.id);
            fprintf(file, "%s\n", stack.top->person.name);
            fprintf(file, "%d %d %d\n", stack.top->person.day,
                                        stack.top->person.month, stack.top->person.year);
            stack.top = stack.top->next;
        }
    }
    else
        printf("Error on open o file %s\n", filename);
}

void readFile(char filename[], STACK *stack, int *ids){
    FILE *file = fopen(filename, "r");
    PERSON p;
    if(file){
        fscanf(file, "%d\n", ids);
        while(!feof(file)){
            fscanf(file, "%d\n", &(p.id));
            fscanf(file, "%30[^\n]", p.name);
            fscanf(file, "%d %d %d\n", &(p.day), &(p.month), &(p.year));
            push(stack, p);
        }
    }
    else
        printf("Error on open o file %s\n", filename);
}


void mainMenu(int *option){
    printf("\n========== MENU =========\n");
    printf("\t0 - Exit\n");
    printf("\t1 - Push\n");
    printf("\t2 - Pop\n");
    printf("\t3 - Show Stack\n\n");
    *option = readInt(0, 3, "Choose one option[0 - 3]: ");
    putchar('\n');
}

int main(){
    STACK stack;
    PERSON person;
    int option, ids = 1;
    char filename[] = "../database/database.txt";

    startStack(&stack);
    readFile(filename, &stack, &ids);
    do{
        mainMenu(&option);
        switch(option){
            case 0: printf("Thank You. Goodbye!!!\n"); break;
            case 1:
                readPerson(&person, &ids);
                push(&stack, person);
            break;
            case 2: pop(&stack); break;
            case 3: showStack(stack); break;
            default:
                printf("Invalid Option\n");
        }
    }while(option != 0);
    writeFile(filename, stack, ids);
    return 0;
}