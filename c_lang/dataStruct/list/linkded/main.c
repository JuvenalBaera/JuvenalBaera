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
    //PERSON person;
    PERSON data;
    struct Node *next;
}NODE;

typedef struct{
    NODE *begin;
    unsigned int size;
}LIST;

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
    printf("%02d - %02d/%02d/%4d - %s\n", p.id, p.day, p.month, p.year, p.name);
}


// #############################   QUEUE ##################################
void startList(LIST *list){
    list->begin = NULL;
    list->size = 0;
}

void erroAlloc(){
    printf("Error in memory allocation\n");
}

void insertBegin(LIST *list, PERSON data){
    NODE *new = malloc(sizeof(NODE));
    if(new){
        new->data = data;
        new->next = list->begin;
        list->begin = new;
        list->size++;
    }
    else erroAlloc();
}

void insertEnd(LIST *list, PERSON data){
    NODE *aux, *new = malloc(sizeof(NODE));
    if(new){
        new->data = data;
        new->next = NULL;
        if(list->begin == NULL)
            list->begin = new;
        else{
            aux = list->begin;
            while(aux->next)
                aux = aux->next;
            aux->next = new;
        }
        list->size++;
    }
    else erroAlloc();
}

void insertAfter(LIST *list, PERSON data, int id){
    NODE *aux, *new = malloc(sizeof(NODE));
    if(new){
        new->data = data;
        if(list->begin == NULL){ // If it's first
            new->next = NULL;
            list->begin = new;
        }
        else{
            aux = list->begin;
            while(aux->next && aux->data.id != id)
                aux = aux->next;
            new->next = aux->next;
            aux->next = new;
        }
        list->size++;
    }
    else erroAlloc();
}

void insertSorted(LIST *list, PERSON data){
    NODE *aux, *new = malloc(sizeof(NODE));
    if(new){
        new->data = data;
        if(list->begin == NULL){
            new->next = NULL;
            list->begin = new;
        }
        else if(data.id < list->begin->data.id){
            new->next = list->begin;
            list->begin = new;
        }
        else{
            aux = list->begin;
            while(aux->next && aux->next->data.id < data.id)
                aux = aux->next;
            new->next = aux->next;
            aux->next = new;
        }
        list->size++;
    }
    else erroAlloc();
}

NODE* removeData(LIST *list, int id){
    NODE *aux, *rem = NULL;
    if(list->begin){
        if(list->begin->data.id == id){ // If is First data to remve
            rem = list->begin;
            list->begin = rem->next;
            list->size--;
        }
        else{
            aux = list->begin;
            while(aux->next && aux->next->data.id != id)
                aux = aux->next;
            if(aux->next){
                rem = aux->next;
                aux->next = rem->next;
                list->size--;
            }
        }
    }
    return rem;
}

NODE* search(LIST list, int id){
    NODE *aux = list.begin;
    while(aux){
        if(aux->data.id == id)
            return aux;
        aux = aux->next;
    }
    return NULL;
}

void showList(LIST list){
    printf("======= LIST %2d =======\n", list.size);
    while(list.begin){
        printf("\t");
        showPerson(list.begin->data);
        list.begin = list.begin->next;
    }
    printf("=======================\n");
}


// ####################### FILE ######################
void writeFile(char filename[], LIST list, int ids){
    FILE *file = fopen(filename, "w");
    if(file){
        fprintf(file, "%d\n", ids);
        while(list.begin){
            fprintf(file, "%d\n", list.begin->data.id);
            fprintf(file, "%s\n", list.begin->data.name);
            fprintf(file, "%d %d %d\n", list.begin->data.day,
                                        list.begin->data.month, list.begin->data.year);
            list.begin = list.begin->next;
        }
    }
    else
        printf("Error on open o file %s\n", filename);
}

void readFile(char filename[], LIST *list, int *ids){
    FILE *file = fopen(filename, "r");
    PERSON p;
    if(file){
        fscanf(file, "%d\n", ids);
        while(!feof(file)){
            fscanf(file, "%d\n", &(p.id));
            fscanf(file, "%30[^\n]", p.name);
            fscanf(file, "%d %d %d\n", &(p.day), &(p.month), &(p.year));
            insertSorted(list, p);
        }
    }
    else
        printf("Error on open o file %s\n", filename);
}

void mainMenu(int *option){
    printf("\n========== MENU =========\n");
    printf("\t0 - Exit\n");
    printf("\t1 - Insert in begin\n");
    printf("\t2 - Insert in the End\n");
    printf("\t3 - Insert after\n");
    printf("\t4 - Insert Sorted\n");
    printf("\t5 - Remove data\n");
    printf("\t6 - Search Element\n");
    printf("\t7 - Show Queue\n\n");
    *option = readInt(0, 7, "Choose one option[0 - 7]: ");
    putchar('\n');
}

int main(){
    LIST list;
    NODE *removed = NULL;
    PERSON data;
    char filename[] = "../../database/database.txt";
    int option, idGenerate=1, idInput;

    startList(&list);
    readFile(filename, &list, &idGenerate);
    do{
        mainMenu(&option);
        switch(option){
            case 0: printf("Thank You. Goodbye!!!\n"); break;
            case 1:
                readPerson(&data, &idGenerate);
                insertBegin(&list, data);
            break;
            case 2: 
                readPerson(&data, &idGenerate);
                insertEnd(&list, data);
            break;
            case 3:
                readPerson(&data, &idGenerate);
                idInput = readInt(1, 32000, "\nInsert After with ID: ");
                insertAfter(&list, data, idInput);
            break;
            case 4:
                readPerson(&data, &idGenerate);
                insertSorted(&list, data);
            break;
            case 5:
                if(list.begin){
                    idInput = readInt(1, 32000, "Enter ID to remove: ");
                    removed = removeData(&list, idInput);
                    if(removed){
                        printf("\nDeleted element\n");
                        showPerson(removed->data);
                        free(removed);
                    }
                    else
                        printf("The Id %d doesn't exist\n", idInput);
                }
                else
                    printf("List is empty\n");
            break;
            case 6:
                if(list.begin){
                    idInput = readInt(1, 32000, "Enter ID to Search: ");
                    removed = search(list, idInput);
                    if(removed){
                        printf("\nElement was found\n");
                        showPerson(removed->data);
                    }
                    else
                        printf("The Id %d wasn't found\n", idInput);
                }
                else
                    printf("List is empty\n");
            break;
            case 7: showList(list); break;
            default:
                printf("Invalid Option\n");
        }
    }while(option != 0);
    writeFile(filename, list, idGenerate);
    return 0;
}
