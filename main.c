#include <stdio.h>
#include <unistd.h>

void a(int x);
void b(int x);
void c(int x);

int main() {

	for(int i=0;i<5;i++) {
		printf("Calling a.\n");
		a(0);
		printf("a done.\n");
		c(1);
	}

	return 0;
}

void a(int x) {
	for(int i=0;i<100000;i++) {
		b(x);
	}
}

void b(int x) {
	for(int i=0;i<90000;i++) {
		x++;
	}
}

void c(int x) {
	sleep(x);
}