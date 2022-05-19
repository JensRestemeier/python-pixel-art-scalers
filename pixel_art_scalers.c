#include <Python.h>
#include "structmember.h"
#include <stdbool.h>

#include "hqx.h"
#include "scaler_nearestneighbor.h"
#include "scaler_scalex.h"
#include "xbr_filters.h"

#define PY3K (PY_VERSION_HEX >= 0x03000000)

#if PY3K
#define Py_TPFLAGS_CHECKTYPES 0
#endif

#if !PY3K
#define Py_RETURN_NOTIMPLEMENTED return Py_INCREF(Py_NotImplemented), Py_NotImplemented
#define PyLong_AS_LONG(op) PyLong_AsLong(op)
#define PyExtNumber_Check(op) (PyLong_Check(op) || PyInt_Check(op) || PyFloat_Check(op) || PyBool_Check(op))
#endif
bool PyExtNumber_Check(PyObject* arg) {
#if PY3K
	if (PyFloat_Check(arg) || PyLong_Check(arg) || PyBool_Check(arg)) {
#else
	if (PyFloat_Check(arg) || PyInt_Check(arg) || PyLong_Check(arg) ||  PyBool_Check(arg)) {
#endif
		return true;
	}
	if (arg->ob_type->tp_as_number != NULL && arg->ob_type->tp_as_number->nb_float != NULL) {
		PyObject* temp = PyNumber_Float(arg);
		if (temp != NULL) {
			Py_DECREF(temp);
			return true;
		}
		PyErr_Clear();
	}
	return false;
}

double PyExtNumber_AsDouble(PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return PyFloat_AS_DOUBLE(arg);
	}
#if !PY3K
	if (PyInt_Check(arg)) {
		return (double)PyInt_AS_LONG(arg);
	}
#endif
	if (PyLong_Check(arg)) {
		return (double)PyLong_AsDouble(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1.0 : 0.0;
	}
	PyObject* arg_as_float = PyNumber_Float(arg);
	double out = PyFloat_AS_DOUBLE(arg_as_float);
	Py_DECREF(arg_as_float);
	return out;
}

long PyExtNumber_AsLong(PyObject* arg) {
#if !PY3K
	if (PyInt_Check(arg)) {
		return PyInt_AS_LONG(arg);
	}
#endif
	if (PyLong_Check(arg)) {
		return PyLong_AS_LONG(arg);
	}
	if (PyFloat_Check(arg)) {
		return (long)PyFloat_AS_DOUBLE(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1 : 0;
	}
	PyObject* arg_as_long = PyNumber_Long(arg);
	long out = PyLong_AS_LONG(arg_as_long);
	Py_DECREF(arg_as_long);
	return out;
}

float PyExtNumber_AsFloat(PyObject* arg) {
	if (PyFloat_Check(arg)) {
		return (float)PyFloat_AS_DOUBLE(arg);
	}
#if !PY3K
	if (PyInt_Check(arg)) {
		return (float)PyInt_AS_LONG(arg);
	}
#endif
	if (PyLong_Check(arg)) {
		return (float)PyLong_AS_LONG(arg);
	}
	if (PyBool_Check(arg)) {
		return (arg == Py_True) ? 1.f : 0.f;
	}
	PyObject* arg_as_float = PyNumber_Float(arg);
	float out = (float)PyFloat_AS_DOUBLE(arg_as_float);
	Py_DECREF(arg_as_float);
	return out;
}


#define Py_IS_NOTIMPLEMENTED(op) (op == NULL || (PyObject*)op == Py_NotImplemented) // find out if op is NULL or NotImplemented

#define PyType_AS_CSTRING(op) op->ob_type->tp_name

#define Py_RAISE_TYPEERROR_O(str, obj) PyErr_Format(PyExc_TypeError, "%s'%s'", str, PyType_AS_CSTRING(obj))
#define Py_RAISE_TYPEERROR_2O(str, obj1, obj2) PyErr_Format(PyExc_TypeError, "%s'%s' and '%s'", str, PyType_AS_CSTRING(obj1), PyType_AS_CSTRING(obj2))

static char * attr_name_to_cstr(PyObject * name) {
#if PY3K
	return PyBytes_AsString(PyUnicode_AsASCIIString(name));
#else
	return PyString_AsString(name);
#endif
}

static PyObject*
py_hq2x_32(PyObject* self, PyObject* args) {
	Py_buffer src;
	int width;
	int height;

	if (PyArg_ParseTuple(args, "y*ii", &src, &width, &height)) {
		int scale = 2;
		int dest_width = width * scale;
		int dest_height = height * scale;
		int dest_buffer_size = dest_width * dest_height * 4;
		void * dest_buffer = malloc(dest_buffer_size);

		hq2x_32((uint32_t*)src.buf, (uint32_t*)dest_buffer, width, height);
		PyBuffer_Release(&src);

		PyObject * _dest = PyBytes_FromStringAndSize(dest_buffer, dest_buffer_size);
		PyObject * _dest_width = PyLong_FromUnsignedLong(dest_width);
		PyObject * _dest_height = PyLong_FromUnsignedLong(dest_height);
		free(dest_buffer);

		return PyTuple_Pack(3, _dest, _dest_width, _dest_height);
	}
	Py_RETURN_NONE;
}

static PyObject*
py_hq3x_32(PyObject* self, PyObject* args) {
	Py_buffer src;
	int width;
	int height;

	if (PyArg_ParseTuple(args, "y*ii", &src, &width, &height)) {
		int scale = 3;
		int dest_width = width * scale;
		int dest_height = height * scale;
		int dest_buffer_size = dest_width * dest_height * 4;
		void * dest_buffer = malloc(dest_buffer_size);

		hq3x_32((uint32_t*)src.buf, (uint32_t*)dest_buffer, width, height);
		PyBuffer_Release(&src);

		PyObject * _dest = PyBytes_FromStringAndSize(dest_buffer, dest_buffer_size);
		PyObject * _dest_width = PyLong_FromUnsignedLong(dest_width);
		PyObject * _dest_height = PyLong_FromUnsignedLong(dest_height);
		free(dest_buffer);

		return PyTuple_Pack(3, _dest, _dest_width, _dest_height);
	}
	Py_RETURN_NONE;
}

static PyObject*
py_hq4x_32(PyObject* self, PyObject* args) {
	Py_buffer src;
	int width;
	int height;

	if (PyArg_ParseTuple(args, "y*ii", &src, &width, &height)) {
		int scale = 4;
		int dest_width = width * scale;
		int dest_height = height * scale;
		int dest_buffer_size = dest_width * dest_height * 4;
		void * dest_buffer = malloc(dest_buffer_size);

		hq4x_32((uint32_t*)src.buf, (uint32_t*)dest_buffer, width, height);
		PyBuffer_Release(&src);

		PyObject * _dest = PyBytes_FromStringAndSize(dest_buffer, dest_buffer_size);
		PyObject * _dest_width = PyLong_FromUnsignedLong(dest_width);
		PyObject * _dest_height = PyLong_FromUnsignedLong(dest_height);
		free(dest_buffer);

		return PyTuple_Pack(3, _dest, _dest_width, _dest_height);
	}
	Py_RETURN_NONE;
}

static PyObject*
py_xbr_filter_xbr2x(PyObject* self, PyObject* args) {
	Py_buffer src;
	int width;
	int height;

	if (PyArg_ParseTuple(args, "y*ii", &src, &width, &height)) {
		int scale = 2;
		int dest_width = width * scale;
		int dest_height = height * scale;
		int dest_buffer_size = dest_width * dest_height * 4;
		void * dest_buffer = malloc(dest_buffer_size);

		xbr_filter_xbr2x((uint32_t*)src.buf, (uint32_t*)dest_buffer, width, height);
		PyBuffer_Release(&src);

		PyObject * _dest = PyBytes_FromStringAndSize(dest_buffer, dest_buffer_size);
		PyObject * _dest_width = PyLong_FromUnsignedLong(dest_width);
		PyObject * _dest_height = PyLong_FromUnsignedLong(dest_height);
		free(dest_buffer);

		return PyTuple_Pack(3, _dest, _dest_width, _dest_height);
	}
	Py_RETURN_NONE;
}

static PyObject*
py_xbr_filter_xbr3x(PyObject* self, PyObject* args) {
	Py_buffer src;
	int width;
	int height;

	if (PyArg_ParseTuple(args, "y*ii", &src, &width, &height)) {
		int scale = 3;
		int dest_width = width * scale;
		int dest_height = height * scale;
		int dest_buffer_size = dest_width * dest_height * 4;
		void * dest_buffer = malloc(dest_buffer_size);

		xbr_filter_xbr3x((uint32_t*)src.buf, (uint32_t*)dest_buffer, width, height);
		PyBuffer_Release(&src);

		PyObject * _dest = PyBytes_FromStringAndSize(dest_buffer, dest_buffer_size);
		PyObject * _dest_width = PyLong_FromUnsignedLong(dest_width);
		PyObject * _dest_height = PyLong_FromUnsignedLong(dest_height);
		free(dest_buffer);

		return PyTuple_Pack(3, _dest, _dest_width, _dest_height);
	}
	Py_RETURN_NONE;
}

static PyObject*
py_xbr_filter_xbr4x(PyObject* self, PyObject* args) {
	Py_buffer src;
	int width;
	int height;

	if (PyArg_ParseTuple(args, "y*ii", &src, &width, &height)) {
		int scale = 4;
		int dest_width = width * scale;
		int dest_height = height * scale;
		int dest_buffer_size = dest_width * dest_height * 4;
		void * dest_buffer = malloc(dest_buffer_size);

		xbr_filter_xbr4x((uint32_t*)src.buf, (uint32_t*)dest_buffer, width, height);
		PyBuffer_Release(&src);

		PyObject * _dest = PyBytes_FromStringAndSize(dest_buffer, dest_buffer_size);
		PyObject * _dest_width = PyLong_FromUnsignedLong(dest_width);
		PyObject * _dest_height = PyLong_FromUnsignedLong(dest_height);
		free(dest_buffer);

		return PyTuple_Pack(3, _dest, _dest_width, _dest_height);
	}
	Py_RETURN_NONE;
}

static PyObject*
py_scaler_scalex_2x(PyObject* self, PyObject* args) {
	Py_buffer src;
	int width;
	int height;

	if (PyArg_ParseTuple(args, "y*ii", &src, &width, &height)) {
		int scale = 2;
		int dest_width = width * scale;
		int dest_height = height * scale;
		int dest_buffer_size = dest_width * dest_height * 4;
		void * dest_buffer = malloc(dest_buffer_size);

		scaler_scalex_2x((uint32_t*)src.buf, (uint32_t*)dest_buffer, width, height);
		PyBuffer_Release(&src);

		PyObject * _dest = PyBytes_FromStringAndSize(dest_buffer, dest_buffer_size);
		PyObject * _dest_width = PyLong_FromUnsignedLong(dest_width);
		PyObject * _dest_height = PyLong_FromUnsignedLong(dest_height);
		free(dest_buffer);

		return PyTuple_Pack(3, _dest, _dest_width, _dest_height);
	}
	Py_RETURN_NONE;
}

static PyObject*
py_scaler_scalex_3x(PyObject* self, PyObject* args) {
	Py_buffer src;
	int width;
	int height;

	if (PyArg_ParseTuple(args, "y*ii", &src, &width, &height)) {
		int scale = 3;
		int dest_width = width * scale;
		int dest_height = height * scale;
		int dest_buffer_size = dest_width * dest_height * 4;
		void * dest_buffer = malloc(dest_buffer_size);

		scaler_scalex_3x((uint32_t*)src.buf, (uint32_t*)dest_buffer, width, height);
		PyBuffer_Release(&src);

		PyObject * _dest = PyBytes_FromStringAndSize(dest_buffer, dest_buffer_size);
		PyObject * _dest_width = PyLong_FromUnsignedLong(dest_width);
		PyObject * _dest_height = PyLong_FromUnsignedLong(dest_height);
		free(dest_buffer);

		return PyTuple_Pack(3, _dest, _dest_width, _dest_height);
	}
	Py_RETURN_NONE;
}

static PyObject*
py_scaler_scalex_4x(PyObject* self, PyObject* args) {
	Py_buffer src;
	int width;
	int height;

	if (PyArg_ParseTuple(args, "y*ii", &src, &width, &height)) {
		int scale = 4;
		int dest_width = width * scale;
		int dest_height = height * scale;
		int dest_buffer_size = dest_width * dest_height * 4;
		void * dest_buffer = malloc(dest_buffer_size);

		scaler_scalex_4x((uint32_t*)src.buf, (uint32_t*)dest_buffer, width, height);
		PyBuffer_Release(&src);

		PyObject * _dest = PyBytes_FromStringAndSize(dest_buffer, dest_buffer_size);
		PyObject * _dest_width = PyLong_FromUnsignedLong(dest_width);
		PyObject * _dest_height = PyLong_FromUnsignedLong(dest_height);
		free(dest_buffer);

		return PyTuple_Pack(3, _dest, _dest_width, _dest_height);
	}
	Py_RETURN_NONE;
}

static PyMethodDef templatemethods[] = {
	/* PyMethodDef, a structure used to describe a method of an extension type.
		* reference:
		* https://docs.python.org/3/c-api/structures.html#c.PyMethodDef
		*/
	{ "py_hq2x_32", (PyCFunction)py_hq2x_32, METH_VARARGS, "HQ2X algorithm" },
	{ "py_hq3x_32", (PyCFunction)py_hq3x_32, METH_VARARGS, "HQ2X algorithm" },
	{ "py_hq4x_32", (PyCFunction)py_hq4x_32, METH_VARARGS, "HQ2X algorithm" },
	{ "py_xbr_filter_xbr2x", (PyCFunction)py_xbr_filter_xbr2x, METH_VARARGS, "XBR2X algorithm" },
	{ "py_xbr_filter_xbr3x", (PyCFunction)py_xbr_filter_xbr3x, METH_VARARGS, "XBR3X algorithm" },
	{ "py_xbr_filter_xbr4x", (PyCFunction)py_xbr_filter_xbr4x, METH_VARARGS, "XBR4X algorithm" },
	{ "py_scaler_scalex_2x", (PyCFunction)py_scaler_scalex_2x, METH_VARARGS, "Scalex 2x algorithm" },
	{ "py_scaler_scalex_3x", (PyCFunction)py_scaler_scalex_3x, METH_VARARGS, "Scalex 3x algorithm" },
	{ "py_scaler_scalex_4x", (PyCFunction)py_scaler_scalex_4x, METH_VARARGS, "Scalex 4x algorithm" },
	{ NULL, NULL, 0, NULL }
};

#if PY3K
static PyModuleDef templatemodule = {

	PyModuleDef_HEAD_INIT,
	"_pixel_art_scalers",
	"A simple template for Python's C-API",
	-1,
	templatemethods, NULL, NULL, NULL, NULL
};
#endif

PyMODINIT_FUNC
#if PY3K
	PyInit__pixel_art_scalers(void)
#else
	inittemplate(void)
#endif
{
	PyObject* mainmod = PyImport_AddModule("__main__");
	PyObject* maindict = PyModule_GetDict(mainmod);

	PyObject* m;

#if PY3K
	m = PyModule_Create(&templatemodule);
#else
	m = Py_InitModule3("_pixel_art_scalers", templatemethods, "A simple template for Python's C-API");
#endif
	if (m == NULL)
#if PY3K
		return NULL;
#else
		return;
#endif

	hqxInit();

#if PY3K
	return m;
#endif
}

