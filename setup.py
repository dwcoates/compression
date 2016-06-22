from distutils.core import setup, Extension

setup(ext_modules=[Extension("_compressor", ["_compressor.c", "compressor.c"])])
