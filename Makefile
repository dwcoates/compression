all:
	swig -python compressor.i
	gcc -fpic -c compressormodule.c compressor_wrap.c -I/usr/include/python2.7/ -lc
	gcc -shared compressormodule.o compressor_wrap.o -o _compressor.so
