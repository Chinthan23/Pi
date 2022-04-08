CC=g++
all_sources=main.cpp Division.cpp Mulitply.cpp Addition.cpp Subtraction.cpp Squareroot.cpp	 #all the .cpp files which are to be compiled

assignment:					 #creating excutable file
		$(CC) -o assignment $(all_sources) -std=c++14

clean:								 #removing the executable file and the object file
	rm assignment 
