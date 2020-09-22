#include "playlist.h"

int main()
{
	std::string thisLine;
	std::string command;
	std::string param;
	PlayList list;
	Song song;

	while(!std::cin.eof())
	{
		std::getline(std::cin,thisLine);

		if(std::cin.eof())
			break;

        command = thisLine.substr(0, 1);
		param = thisLine.substr(2, thisLine.size() - 1);

		if(command == "m")
		{
			list.createList(std::stoi(param));
		}
		else if(command == "i")
		{
			int pos = param.find(";");
			std::string title = param.substr(0, pos);
			std::string artist = param.substr(pos + 1, param.size());
			song.createSong(artist, title);
			list.addSong(song);
		}
		else if(command == "p")
		{
			list.playSong(std::stoi(param));
		}
		else if(command == "e")
		{
			list.eraseSong(std::stoi(param));
		}
		else
		{
			std::cout << "Invalid";
		}
	}

	return 0;
}
