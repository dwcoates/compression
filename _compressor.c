#include <Python.h>
#include "compressor.h"

static char module_docstring[] = "Fast lossy string compression module.";

static char basic_docstring[] = "Compress the string.";

static PyObject *compressor_basic(PyObject *self, PyObject *args)
{
	const char *str;
	const unsigned int str_pos;
	const unsigned int N;
	uint64_t result;

	if (!PyArg_ParseTuple(args, "sII", &str, &str_pos, &N))
		return NULL;

	result = basic(str, str_pos, N);

	return Py_BuildValue("K", result);
}

static PyMethodDef module_methods[] = {
  {"basic", compressor_basic, METH_VARARGS, basic_docstring},
  {NULL, NULL, 0, NULL}
};

PyMODINIT_FUNC init_compressor(void)
{
	Py_InitModule3("_compressor", module_methods, module_docstring);
}

