shopt -s globstar
g++ -Wall -fPIC -shared -o libsha1.so ./src/libsha1.cpp -lssl -lcrypto
