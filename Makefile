CC=g++

.PHONY:
	clean
	install

main: *.cpp
	$(CC) -g -o blobmyth $^

clean:
	rm -f blobmyth

prefix=/usr/local
    
install: blobmyth
	install -m 0755 $^ $(prefix)/bin
