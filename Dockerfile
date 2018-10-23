FROM alpine:3.8

# --prefix for ./configure to control path of libs
# ./configure --enable-frame-pointers because of x86_64 arch
# add libtool to make configure.ac work
# apk add linux-headers for make gperftools
# docker cp <containerId>:/file/path/within/container /host/path/target (copy prof files back to host from container)
# use make install to output libraries in /usr/local/lib
# virtual is to add the apk packages in a virtual space so you can delete the .build_deps easily (don't use it for required packages)
# enhancement: use --virtual with .build_deps for apk add automake autoconf make linux-headers libtool g++
# if workdir is not set, it uses it from the base image (Alpine) and container will start in root
# use docker history <container_name> to get info on intermediate containers
# add this when compiling gcc -fno-omit-frame-pointer

RUN apk update && \
	apk upgrade && \
	apk add --no-cache git gcc g++ automake autoconf make linux-headers libtool

RUN git clone https://github.com/gperftools/gperftools && \
	cd gperftools && \
	./autogen.sh && \
	./configure --enable-frame-pointers && \
	make install

RUN cd / && \
	mkdir ggg && \
	cd $_

WORKDIR /ggg

COPY main.c .

RUN gcc -o main main.c -fno-omit-frame-pointer -Wl,--no-as-needed,-ltcmalloc,--as-needed && \
	HEAPPROFILE=main.hprof ./main