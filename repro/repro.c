#include <Python.h>
#include <stdio.h>

#if PY_MAJOR_VERSION >= 3
#define IS_PY3K
#endif

static PyObject *repro_decref(PyObject *self, PyObject *args)
{
    PyObject *obj;
    if (!PyArg_ParseTuple(args, "O", &obj)) {
            return NULL;
        }
    Py_DECREF(obj);
    Py_RETURN_NONE;
}

static PyMethodDef ReproMethods[] = {
    { "decref", repro_decref, METH_VARARGS, "Decrement ref count on obj" },
    { NULL, NULL, 0, NULL }
};

#ifdef IS_PY3K
static struct PyModuleDef repromodule = {
    PyModuleDef_HEAD_INIT, "repro", NULL, -1, ReproMethods
};

PyMODINIT_FUNC PyInit_repro(void)
{
    return PyModule_Create(&repromodule);
}
#else
PyMODINIT_FUNC initrepro(void)
{
    (void) Py_InitModule("repro", ReproMethods);
}
#endif

