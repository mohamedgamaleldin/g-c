build: Dockerfile
	docker build -t go-c -f Dockerfile .
run:
	gcc -o hashmap hashmap.c
	./hashmap
clean:
	docker rm -f $(docker ps -a)
	docker rmi -f $(docker images -f "dangling=true" q)