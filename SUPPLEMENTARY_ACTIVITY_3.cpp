#include <iostream>
#include <string>
using namespace std;

// Node structure representing a song in the playlist
class SongNode {
public:
    string songName;
    SongNode* next;
    
    // Constructor to create a new node with a song name
    SongNode(string song) {
        songName = song;
        next = nullptr;
    }
};

// Circular Linked List class for managing the song playlist
class Playlist {
private:
    SongNode* last; // Points to the last node (song) in the playlist

public:
    Playlist() {
        last = nullptr; // Initially, playlist is empty
    }

    // Function to add a new song to the playlist
    void addSong(string songName) {
        SongNode* newSong = new SongNode(songName);
        
        if (last == nullptr) {  // If the list is empty
            last = newSong;
            last->next = last;  // Points to itself, forming a circular link
        } else {
            newSong->next = last->next;  // Link the new song to the first song
            last->next = newSong;  // The current last song points to the new song
            last = newSong;  // The new song becomes the last song
        }
        cout << "Added: " << songName << " to the playlist." << endl;
    }

    // Function to remove a song from the playlist by name
    void removeSong(string songName) {
        if (last == nullptr) {  // If the playlist is empty
            cout << "Playlist is empty, cannot delete." << endl;
            return;
        }

        SongNode* temp = last->next;
        SongNode* prev = last;
        do {
            if (temp->songName == songName) {
                if (temp == last && temp->next == last) {  // Only one song in the list
                    delete temp;
                    last = nullptr;  // Empty the playlist
                } else {
                    prev->next = temp->next;
                    if (temp == last) last = prev;  // Update last if last song is removed
                    delete temp;
                }
                cout << "Removed: " << songName << " from the playlist." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);  // Stop when we loop back to the first song

        cout << "Song not found in the playlist." << endl;
    }

    // Function to play all songs (traverse playlist in a loop)
    void playAllSongs() {
        if (last == nullptr) {
            cout << "Playlist is empty." << endl;
            return;
        }

        SongNode* temp = last->next;  // Start from the first song
        cout << "Playing all songs in the playlist:" << endl;
        do {
            cout << temp->songName << " -> ";
            temp = temp->next;
        } while (temp != last->next);  // Loop back to the start
        cout << "Repeat..." << endl;  // Since it's a circular playlist
    }
};

// Driver function to test the Playlist
int main() {
    Playlist myPlaylist;

    // Add songs to the playlist
    myPlaylist.addSong("Song A");
    myPlaylist.addSong("Song B");
    myPlaylist.addSong("Song C");
    myPlaylist.addSong("Song D");

    // Play all songs
    myPlaylist.playAllSongs();

    // Remove a song and display the playlist again
    myPlaylist.removeSong("Song B");
    myPlaylist.playAllSongs();

    // Remove another song and display the playlist
    myPlaylist.removeSong("Song A");
    myPlaylist.playAllSongs();

    return 0;
}
