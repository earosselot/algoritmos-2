# Build and run:
#   docker build -t clion/ubuntu/cpp-env:1.0 -f Dockerfile.cpp-env-ubuntu .

FROM alpine

# RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install tzdata

RUN apk add --update gcc g++ gdb clang make ninja cmake autoconf automake dos2unix rsync tar python3
RUN apk add --update valgrind
RUN rm -rf /tmp/* /var/cache/apk/*
RUN cmake --version