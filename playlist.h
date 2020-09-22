#include <iostream>
#include <string>

class Song
{
public:
	void createSong(std::string in_a, std::string in_t);
	std::string getArtist();
	std::string getTitle();
private:
	std::string artist;
	std::string title;
};

class PlayList
{
public:
	~PlayList();
	void createList(int in_size);
	void addSong(Song song);
	void playSong(int pos);
	void eraseSong(int pos);
private:
	friend class Song;
	int size;
	Song *p_list;
};

