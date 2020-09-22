playlistdriver: playlistdriver.cpp playlist.h playlist.cpp
	g++ -std=c++11 -o playlistdriver playlistdriver.cpp playlist.cpp
    
clean:
	rm -f playlistdriver
