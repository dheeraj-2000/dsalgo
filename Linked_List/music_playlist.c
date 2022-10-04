//creating a music playlist using doubly circular linked list

#include <stdio.h>
#include <string.h>

//initializing circular doubly linked list
struct node
{
    struct node *prev;
    char data[20];
    struct node *next;
};
struct node *start = NULL, *ptr = NULL, *now = NULL;
//function declarations
void add(void);
struct node *deletee(struct node *);
void display(void);
void play_next(void);
void play_prev(void);
void play_first(void);
void play_last(void);
void play_specific(void);

int main()
{
    int c;
    printf("\t\t---Music Playlist Application---\n");

    //do-while
    do
    {
        printf("--MENU--\n");
        printf("1. Add Music\n2. Delete Music\n3. View Playlist\n4. Play Next Music\n5. Play Previous Music\n6. Play First Music\n7. Play Last Music\n8. Play Specific Music\n9. Exit\n\n");
        printf("->Enter your choice: ");
        scanf("%d", &c);

        switch(c)
        {
        case 1:
            add();  //adding music
            break;
        case 2:
            start = deletee(start); //deleting music
            if(start == NULL && now != NULL)
                printf("\n\t!Playlist is Empty now!\n");
            break;
        case 3:
            display();  //traversing playlist
            break;
        case 4:
            play_next();    //next music
            break;
        case 5:
            play_prev();    //previous music
            break;
        case 6:
            play_first();   //first music
            break;
        case 7:
            play_last();    //last music
            break;
        case 8:
            play_specific();    //specific music
            break;
        case 9:
            exit(0);
        default:
            printf("\n\t!Please Choose Correct Option!\n");
        }
        if(start != NULL)
            printf("\n\t-->>Playing \"%s\"...\n\n", now->data);
    }while(c != 9);
    return 0;
}

void add()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));  //dynamic memory allocation
    printf("\n->Enter music name: ");
    fflush(stdin);
    gets(new_node->data);
    if(start == NULL)   //for the first time entry
    {
        start = new_node;
        new_node->next = start;
        new_node->prev = NULL;
        now = start;
    }
    else
    {
        ptr = start;
        while(ptr->next != start)
            ptr = ptr->next;
        ptr->next = new_node;
        new_node->prev = ptr;
        new_node->next = start;
        start->prev = new_node;
        printf("\n\"%s\" is added successfully!\n\n", new_node->data);
    }
}

struct node *deletee(struct node *start)
{
    if(start == NULL)
    {
        printf("\n\t!Playlist is empty! Cannot Delete\n\n");
        return NULL;
    }
    else
    {
        char music[20];
        int c;
        here1:
        printf("1. Delete by name\n2. Delete by number\n");    //2 options for deletion
        printf("->Choose Option: ");
        scanf("%d", &c);

        switch(c)
        {
        case 1:    //delete by name
            printf("\n->Enter the music name: ");
            fflush(stdin);
            gets(music);
            ptr = start;
            do
            {
                if(strcmpi(music, ptr->data) == 0)
                    break;
                else if(ptr->next == start)
                {
                    printf("\n\t!No Result Found!\n");
                    return start;
                }

                else
                    ptr = ptr->next;
            } while(ptr != start);
            break;
        case 2:    //delete by number
            here3:
            printf("\n->Enter the music number: ");
            scanf("%d", &c);
            ptr = start;
            for(int i=1; i<c; i++)
            {
                ptr = ptr->next;
                if(ptr == start)
                {
                    printf("\n!\tInvalid Music Number from the playlist!\n");
                    goto here3;
                }
            }
            break;
        default:
            printf("\n!Please Choose Correct Option!\n");
            goto here1;
        }
        if(start->prev == NULL)
            start = NULL;
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            printf("\n\t->\"%s\" is deleted!\n", ptr->data);
            if(ptr == start)
                start = ptr->next;
        }
        if(now == ptr);
            now = now->next;
        return start;
    }
}

void display()
{
    if(start == NULL)
        printf("\n\t!Playlist is empty!\n\n");
    else
    {
        int i = 1;
        ptr = start;
        printf("\n\t--Playlist--\n");
        for(ptr = start; ptr->next != start; ptr = ptr->next)   //traversing playlist with for loop
            printf("%d. %s\n", i++, ptr->data);
        printf("%d. %s\n\n", i, ptr->data);

    }
}

void play_next()
{
    if(start == NULL)
        printf("\n\t!Playlist is empty! Can't play!\n\n");
    else
        now = now->next;
}

void play_prev()
{
    if(start == NULL)
        printf("\n\t!Playlist is empty! Can't play!\n\n");
    else
        now = now->prev;
}

void play_first()
{
    if(start == NULL)
        printf("\n!Playlist is empty! Can't play!\n\n");
    else
        now = start;
}

void play_last()
{
    if(start == NULL)
        printf("\n\t!Playlist is empty! Can't play!\n\n");
    else
        now = start->prev;
}

void play_specific()
{
    if(start == NULL)
        printf("\n\t!Playlist is empty! Can't play!\n\n");
    else
    {
        int c;
        char music[20];
        here:
        printf("->Select music by \n1. Name\n2. Number\n");    //2 options for selection
        printf("->Choose Option: ");
        scanf("%d", &c);

        switch(c)
        {
        case 1:    //search by name
            printf("->Enter the music name: ");
            fflush(stdin);
            gets(music);
            ptr = start;
            do
            {
                if(strcmpi(music, ptr->data) == 0)
                {
                    printf("\n\t->\"%s\" found in the playlist!\n", music);
                    now = ptr;
                    break;
                }
                else if(ptr->next == start)
                    printf("\n\t!No Result Found!\n");
                else
                    ptr = ptr->next;
            } while(ptr != start);
            break;
        case 2:    //search by number
            here2:
            printf("->Enter the music number: ");
            scanf("%d", &c);
            ptr = start;
            for(int i=1; i<c; i++)
            {
                ptr = ptr->next;
                if(ptr == start)
                {
                    printf("\n!\tInvalid Music Number from the playlist!\n");
                    goto here2;
                }
            }
            now = ptr;
            break;
        default:
            printf("\n!\tPlease Choose Correct Option!\n");
            goto here;
        }
    }
}

