/* WAP to simulate a music player using a dynamic doubly linked playlist. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[100];
    struct Song* next;
    struct Song* prev;
} Song;

void Addsong( Song * head, const char* title) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    if (!newSong) {
        printf("Memory allocation failed\n");
        return;
    }
    strncpy(newSong->title, title, sizeof(newSong->title));
    newSong->next = NULL;
    newSong->prev = NULL;

    if (head == NULL) {
        head = newSong;
    } else {
        Song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
        newSong->prev = temp;
    }
}

void displayPlaylist(Song* head) {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    Song* temp = head;
    printf("Playlist:\n");
    while (temp != NULL) {
        printf("%s\n", temp->title);
        temp = temp->next;
    }
}

void playSong(Song* song) {
    if (song == NULL) {
        printf("No song to play.\n");
        return;
    }
    printf("Now playing: %s\n", song->title);
}

void NextSong(Song** current) {
    if (*current == NULL || (*current)->next == NULL) {
        printf("No next song.\n");
        return;
    }
    *current = (*current)->next;
    playSong(*current);
}

void PreviousSong(Song** current) {
    if (*current == NULL || (*current)->prev == NULL) {
        printf("No previous song.\n");
        return;
    }
    *current = (*current)->prev;
    playSong(*current);
}

void freePlaylist(Song* head) {
    while (head != NULL) {
        Song* temp = head;
        head = head->next;
        free(temp);
    }
}

void menu() {
    Song* playlist = NULL;
    Song* currentSong = NULL;
    int choice;
    char title[100];

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add song\n");
        printf("2. Display playlist\n");
        printf("3. Play current song\n");
        printf("4. Next song\n");
        printf("5. Previous song\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter song title: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0; // Remove newline character
                Addsong(playlist, title);
                if (currentSong == NULL) {
                    currentSong = playlist; // Set the first song as current
                }
                break;
            case 2:
                displayPlaylist(playlist);
                break;
            case 3:
                playSong(currentSong);
                break;
            case 4:
                NextSong(&currentSong);
                break;
            case 5:
                PreviousSong(&currentSong);
                break;
            case 6:
                freePlaylist(playlist);
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void main() {
    menu();
}