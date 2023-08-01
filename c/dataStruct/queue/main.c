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
    NODE *first;
    NODE *last;
    unsigned int size;
}QUEUE;

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
    scanf("%30[^\n]", p->name);
    p->day = readInt(0, 150, "Enter a day..: ");
    p->month = readInt(0, 12, "Enter a month: ");
    p->year = readInt(1900, 2022, "Enter a year.: ");
}

void showPerson(PERSON p){
    printf("%2d - %02d/%02d/%4d - %s\n", p.id, p.day, p.month, p.year, p.name);
}


// #############################   QUEUE ##################################

void erroAlloc(){
    printf("\nError in memory allocation\n");
}

void startQueue(QUEUE *queue){
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;
}

void enqueue(QUEUE *queue, PERSON person){
    NODE *new = malloc(sizeof(NODE));
    if(new){
        new->person = person;
        new->next = NULL;
        if(queue->first == NULL){
            queue->first = new;
            queue->last = new;
        }
        else{
            queue->last->next = new;
            queue->last = new;
        }
        queue->size++;
    }
    else
        erroAlloc();
}

void dequeue(QUEUE *queue){
    if(queue->first){
        printf("Removed Person\n");
        showPerson(queue->first->person);
        queue->first = queue->first->next;
        queue->size--;
    }
    else
        printf("QUEUE IS EMPTY\n");
}

void showQueue(QUEUE queue){
    printf("============= QUEUE %2d ============\n", queue.size);
    printf("\tID - BIRTH DATE - NAME\n");
    while(queue.first){
        putchar('\t');
        showPerson(queue.first->person);
        queue.first = queue.first->next;
    }
    printf("=============== END ===============\n");
}


// ####################### FILE ######################
void writeFile(char filename[], QUEUE queue, int ids){
    FILE *file = fopen(filename, "w");
    if(file){
        fprintf(file, "%d\n", ids);
        while(queue.first){
            fprintf(file, "%d\n", queue.first->person.id);
            fprintf(file, "%s\n", queue.first->person.name);
            fprintf(file, "%d %d %d\n", queue.first->person.day,
                                        queue.first->person.month, queue.first->person.year);
            queue.first = queue.first->next;
        }
    }
    else
        printf("Error on open o file %s\n", filename);
}

void readFile(char filename[], QUEUE *queue, int *ids){
    FILE *file = fopen(filename, "r");
    PERSON p;
    if(file){
        fscanf(file, "%d\n", ids);
        while(!feof(file)){
            fscanf(file, "%d\n", &(p.id));
            fscanf(file, "%30[^\n]", p.name);
            fscanf(file, "%d %d %d\n", &(p.day), &(p.month), &(p.year));
            enqueue(queue, p);
        }
    }
    else
        printf("Error on open o file %s\n", filename);
}


void mainMenu(int *option){
    printf("\n========== MENU =========\n");
    printf("\t0 - Exit\n");
    printf("\t1 - Enqueue\n");
    printf("\t2 - Dequeue\n");
    printf("\t3 - Show Queue\n\n");
    *option = readInt(0, 3, "Choose one option[0 - 3]: ");
    putchar('\n');
}

int main(){
    QUEUE queue;
    PERSON person;
    char filename[] = "../database/database.txt";
    int option, data, id = 1;

    startQueue(&queue);
    readFile(filename, &queue, &id);
    do{
        mainMenu(&option);
        switch(option){
            case 0: printf("Thank You. Goodbye!!!\n"); break;
            case 1:
                readPerson(&person, &id);
                enqueue(&queue, person);
            break;
            case 2: dequeue(&queue); break;
            case 3: showQueue(queue); break;
            default:
                printf("Invalid Option\n");
        }
    }while(option != 0);
    writeFile(filename, queue, id);
    return 0;
}