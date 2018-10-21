build: Dockerfile
	docker build -t go-c -f Dockerfile .
run:
	docker run --interactive -t go-c sh
clean:
	docker rmi $(docker images -f "dangling=true" q)