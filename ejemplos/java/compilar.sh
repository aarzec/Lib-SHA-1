# get the java home
JAVA_HOME=$(readlink -f /usr/bin/javac | sed "s:bin/javac::")

javac SHA1Lib.java
javac SHA1Lib.java -h .
gcc -fPIC -shared -o libsha1.so sha1lib_jni.c -lssl -lcrypto -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux
