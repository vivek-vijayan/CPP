/*
    Music Play list
    --------------
    Using double linked list

    Developer : Vivek Vijayan
*/

#include "iostream"

class Music
{

public:
    int musicId;
    std::string musicName;
    std::string album;
    std::string artist;
    std::string genre;

    Music *current, *previous, *next;

public:
    Music(int id, std::string name, std::string albumx, std::string artistx, std::string genrex)
    {
        musicId = id;
        musicName = name;
        album = albumx;
        artist = artistx;
        genre = genrex;
    }

private:
    int totalLikes;

public:
    bool likeMusic()
    {
        totalLikes++;
        return true;
    }

public:
    bool dislikeMusic()
    {
        totalLikes--;
        return false;
    }
};

Music *currentSong;

void play(Music *song)
{
    std::cout << "Playing .....  : " << song->musicName << std::endl;
    if (song->next == NULL)
        {std::cout << "[2] Previous" << std::endl;}
    else if (song->previous == NULL)
        {std::cout << "[1] Next" << std::endl;}
    else
        {std::cout << "[1] Next          [2] Previous" << std::endl;}
}

Music *goPrevious(Music *current)
{
    currentSong = current->previous;
    return currentSong;
}

Music *goNext(Music *current)
{
    currentSong = current->next;
    return currentSong;
}

int main()
{
    Music *m1 = new Music(1, "Song 1", "NewSong", "Vivek", "free");
    Music *m2 = new Music(1, "Song 2", "NewSong", "Vivek", "free");
    Music *m3 = new Music(1, "Song 3", "NewSong", "Vivek", "free");
    Music *m4 = new Music(1, "Song 4", "NewSong", "Vivek", "free");
    Music *m5 = new Music(1, "Song 5", "NewSong", "Vivek", "free");

    

    m1->next = m2;
    m2->next = m3;
    m3->next = m4;
    m4->next = m5;
    m5->next = NULL;

    m1->previous = NULL;
    m2->previous = m1;
    m3->previous = m2;
    m4->previous = m3;
    m5->previous = m4;

    currentSong = m1;
    play(currentSong);

    int option = 0;

    while (true)
    {
        std::cin >> option;
        if (option == 1)
        {
            if (currentSong->next != NULL)
                play(goNext(currentSong));
        }
        else
        {
            if (currentSong->previous != NULL)
                play(goPrevious(currentSong));
        }
    }
    return 0;
}