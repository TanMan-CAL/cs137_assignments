#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Person{
    int id;
    int speed;
    struct Person* next;
}Person;
Person updatePerson(int id, int speed){
    Person person;
    person.id = id;
    person.speed = speed;
    person.next = NULL;
    return person;
}

void addPerson(Person** start, Person* new) { // new is equal to memory address of person struct
    if (*start == NULL){ // if *lop is NULL, so if lop deosn't contain any person yet 
        *start = new;  // now *start = lop, and lop is a pointer, so lop points to what new points to, 
                      // which is the person stuct
        new->next = new; // now assign the struct that new points to itself as its a circular linked list
    }
    else{
        Person *init = *start; // keep note of the starting element;
        while (init->next != *start){
            init = init->next;
        } // get last element
        init->next = new; // now last element links to memory of struct person new
        new->next = *start; // new element that is added at the end now points to starting element, hence made 
        // a circular linked list with n+1 nodes
    }
}

int length(Person *start) {
    if (start == NULL) return 0;

    int count = 1;
    Person *current = start;
    while (current->next != start) {
        count++;
        current = current->next;
    }
    return count;
}

Person* play(Person* start) {
    while (length(start) > 1) {
        Person* gooser = start; 
        int n = gooser->id;

        // Call n people "duck"
        for (int i = 0; i < n; i++) { 
            gooser = gooser->next; 
            if (gooser->id == start->id) { // Skip same player
                gooser = gooser->next;
            }
            printf("%d duck %d\n", start->id, gooser->id); 
        }
        
        // Call n+1th person "goose"
        gooser = gooser->next; 
        if (gooser->id == start->id) { // Skip same player
            gooser = gooser->next;
        }
        printf("%d goose! %d\n", start->id, gooser->id);

        // Determine the winner and loser
        if (gooser->speed >= start->speed) {
            if (start->next == start) { 
                free(start);
                start = NULL;
            } else {
                Person* temp = start;
                while (temp->next != start) {
                    temp = temp->next;
                }
                temp->next = start->next;
                Person* to_free = start;
                start = start->next;
                free(to_free);
            }
            start = gooser; 
        } else {
            Person* current = start;
            while (current->next != gooser) {
                current = current->next;
            }
            current->next = gooser->next;
            free(gooser);
        }
    }


    printf("winner! %d\n", start->id);
    return start;
}



int main(){
    int p, s;
    // List of people
    Person* lop = NULL;

    // Read in participants
    while (scanf("%d %d", &p, &s) == 2){
        Person* np = (Person*)malloc(sizeof(Person));
        *np = updatePerson(p, s);
        addPerson(&lop, np);
    }

    Person* winner = play(lop);
    free(winner);
}