CC=g++
all_sources=main.cpp Division.cpp Mulitply.cpp Addition.cpp Subtraction.cpp Squareroot.cpp	 #all the .cpp files which are to be compiled
all_objs=$(all_sources:.c=.o)					 #object files created from the .c files

assignment: $(all_objs) 					 #creating excutable file
		$(CC) -o assignment $(all_objs) -std=c++14
%.o: %.c 							 #creating object files
	$(CC) -c $(all_sources) 

clean:								 #removing the executable file and the object file
	rm assignment *.o
