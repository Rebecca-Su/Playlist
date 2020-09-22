#include "playlist.h"

void Song::createSong(std::string in_a, std::string in_t)
{
	this->artist = in_a;
	this->title = in_t;
}

std::string Song::getArtist()
{
	return this->artist;
}

std::string Song::getTitle()
{
	return this->title;
}

PlayList::~PlayList()
{
	delete[] p_list;
	p_list = nullptr;
}

void PlayList::createList(int in_size)
{
	this->size = in_size;
	this->p_list = new Song[size];

	std::cout << "success" << std::endl;
}
 void PlayList::addSong(Song song)
 {
	 bool is_inserted = false;
	 for(int i = 0; i < this->size; i++)
	 {
	 	 Song s = this->p_list[i];
		 if((s.getArtist() == song.getArtist()) &&(s.getTitle() == song.getTitle())){
			 break;
		 }
		 else if((this->p_list[i].getArtist() == "") && (this->p_list[i].getTitle() == ""))
		 {
			 this->p_list[i] = song;
			 is_inserted = true;
			 std::cout << "success" << std::endl;
			 break;
		 }
	 }
	 if(!is_inserted)
	 {
		 std::cout << "can not insert " << song.getTitle() << ";" << song.getArtist()<< std::endl;
	 }
 }

void PlayList::playSong(int pos)
{
	if(!(pos >= this->size) || (pos < 1))
	{
		std::string artist = this->p_list[pos - 1].getArtist();
		std::string title = this->p_list[pos - 1].getTitle();

		if(artist == "" && title == "")
			std::cout << "can not play " << pos << std::endl;
		else
			std::cout << "played " << pos << " " << title << ";" << artist << std::endl;

	}
	else
		std::cout << "can not erase " << pos << std::endl;
}

void PlayList::eraseSong(int pos)
{
	if(!(pos >= this->size)|| (pos < 1))
	{
		Song song;
		std::string artist = this->p_list[pos - 1].getArtist();
		std::string title = this->p_list[pos - 1].getTitle();

		if((title == "") && (artist == ""))
			std::cout << "can not erase " << pos << std::endl;
		else
		{
			this->p_list[pos - 1] = song;
			for(int i = pos; i < size; i++)
			{
				this->p_list[i - 1] = this->p_list[i];
			}
			this->p_list[size - 1] = song;
			std::cout << "success" << std::endl;
		}
	}
	else
		std::cout << "can not erase " << pos << std::endl;
}

