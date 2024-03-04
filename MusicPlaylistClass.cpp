#include <iostream>
#include <string>
using namespace std;

class MusicPlaylist {
private:
    string musicData[20] = {};
    string currentTrack;
    int count = 0;
public:
    void add(string currMusic) {
        musicData[count] = currMusic;
        count++;
    }
    void setCurrentTrack(int x) {
        currentTrack = musicData[x-1];
    }
    string play() {
        return currentTrack;
    }
};

int main()
{
    MusicPlaylist mp;
    mp.add("Shape of You");
    mp.add("That's What I Like");
    mp.add("Humble");
    mp.setCurrentTrack(1);
    cout << mp.play() << endl; // แสดงเพลงลำดับที่ 1 คือ Shape of You
}