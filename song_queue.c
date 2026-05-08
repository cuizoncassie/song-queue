#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    int id;
    char title[50];
    char artist[50];
    int duration;
    struct song* next;
} song; 

song* head = NULL;
song* end = NULL;

struct song library[10] = {
    {1, "Damocles", "Sleep Token", 264, NULL},
    {2, "Past Self", "Sleep Token", 214, NULL},
    {3, "Afterlife", "Awaken I Am", 182, NULL},
    {4, "Almost Ecstasy", "Wind Walkers", 244, NULL},
    {5, "Frozen", "Rain City Drive", 215, NULL},
    {6, "Tightrope", "Awaken I Am", 198, NULL},
    {7,"Follow You", "Bring Me The Horizon", 198, NULL},
    {8, "Chokehold", "Sleep Token", 305, NULL},
    {9, "Look To Windward", "Sleep Token", 466, NULL},
    {10, "Even In Arcadia", "Sleep Token", 268, NULL}
};

void displayLibrary() {
	int i;
    printf("----- Initial Song Library -----\n");
    for (i=0; i<10; i++) {
        printf("%d. %s - %s (%d sec)\n", 
        library[i].id,
        library[i].title,
        library[i].artist,
        library[i].duration);
    }
}

void menu() {
    printf("----- Menu -----\n");
    printf("1. View Song Library\n");
    printf("2. Add song to playlist\n");
    printf("3. Play next song\n");
    printf("4. View playlist\n");
    printf("5. Check playlist\n");
    printf("6. Exit\n");
}

void addSong(song selectSong) {
    song* newSong = (song*)malloc(sizeof(song));
    strcpy(newSong->title, selectSong.title);
    strcpy(newSong->artist, selectSong.artist);
    newSong->duration =  selectSong.duration;

    newSong->next = NULL;

    if (head == NULL) {
        head = newSong;
        end = newSong;
    } else {
        end->next = newSong;
        end = newSong;
    }

    printf("\nSong added to playlist.\n");
}

void playNext() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    song* temp = head;
    printf("Now Playing:\n");
    printf("Title: %s\n", temp->title);
    printf("Artist: %s\n", temp->artist);
    printf("Duration: %d seconds\n", temp->duration);

    head = head->next;

    if (head == NULL) {
        end = NULL;
    }
    free(temp);
}

void viewPlaylist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    song* current = head;
    int count = 1;
    printf("----- CURRENT PLAYLIST -----\n");
    while (current != NULL) {
        printf("Song %d\n", count);
        printf("Title: %s\n", current->title);
        printf("Artist: %s\n", current->artist);
        printf("Duration: %d seconds\n", current->duration);

        current = current->next;
        count++;
    }
}

void isEmpty() {
    if (head == NULL) {
        printf("The playlist is empty.\n");
    } else {
        printf("The playlist is not empty.\n");
    }
}

int main() {
    int choice;
    int songChoice;

    do {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayLibrary();
        }
        if (choice == 2) {
            displayLibrary();

            printf("Select song number to add: ");
            scanf("%d", &songChoice);

            if (songChoice >= 1 && songChoice <= 10) {
                addSong(library[songChoice - 1]);
            } else {
                printf("Invalid song choice");
            }
        }
        if (choice == 3) {
            playNext();
        }
        if (choice == 4) {
            viewPlaylist();
        }
        if (choice == 5) {
            isEmpty();
        }
        if (choice == 6) {
            printf("Exiting....\n");
        }

    } while (choice != 6);

    return 0;
}
