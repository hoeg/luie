FROM ubuntu

RUN apt-get update && apt-get -y install \
	build-essential \
	clang-3.8 \
	git \
	libreadline-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /src

RUN git clone https://github.com/lua/lua.git 

WORKDIR /src/lua

RUN make

