drawer:   ..\temp\main.o ..\temp\drawer.o
	g++ -g ..\temp\main.o ..\temp\drawer.o -o ..\drawer

..\temp\drawer.o:   drawer.cpp drawer.h
	g++ -c -g drawer.cpp -o ..\temp\drawer.o
..\temp\main.o:     main.cpp drawer.h
	g++ -c -g main.cpp -o ..\temp\main.o