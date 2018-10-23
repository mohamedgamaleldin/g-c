build: Dockerfile
	docker build -t go-c -f Dockerfile .
run:
	gcc -o g-hash g-hash.c
	./g-hash
clean:
	docker rm -f $(docker ps -a)
	docker rmi -f $(docker images -f "dangling=true" q)