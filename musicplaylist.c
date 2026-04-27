#include <stdio.h>
#include <stdlib.h>
typedef struct song {
    int id;
    char title[50];
    char artist[50];
    int duration;
    struct song* next;
} song;
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
int count = 0;

struct song* playNext(struct song* head) {
	if (head == NULL) {
		return NULL; 
	}
	struct song* temp = head;
	head = head->next;
	free(temp);
	return head;
}

void menu() {
    printf("----- Menu -----\n");
    printf("1. Add Song to Playlist\n2. View Current Playlist\n3. Play Next Song\n4. Show Total Duration\n5. Exit\n");
}
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
void addSong(struct song* head) {
    int songID;
    printf("Enter Song Number to Add: ");
    scanf("%d", &songID);

    if (songID >= 1 && songID <= 10) {
    	struct song* current = head;
    	//if
    	while(current != NULL) {
    		current = current->next;
		}
        printf("Added %s\n", library[songID - 1].title);
    } else {
        printf("Song number not found\n");
    }
    
    
}

void viewPlaylist(struct song* head) {
	struct song* current = head;
	if(head == NULL) {
		printf("The playlist is empty.\n");
		return;
	} printf("--- Current Playlist ---\n");
	if  (current != NULL) {
		printf("Song: %s\n", current->title, current->artist);
		current = current->next;
	}
}
int main() {
    int choice;
    struct song* myPlaylist = NULL;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            displayLibrary();
            addSong(head);
        }
        if (choice == 2) {
        	viewPlaylist(myPlaylist);
		}
		if (choice == 3) {
			playNext(head);
		}
		
    } while (choice != 5);

    return 0;
}

