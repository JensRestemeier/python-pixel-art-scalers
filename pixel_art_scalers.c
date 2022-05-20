#include <Python.h>

#include "hqx.h"
#include "scaler_nearestneighbor.h"
#include "scaler_scalex.h"
#include "xbr_filters.h"

#define PY3K (PY_VERSION_HEX >= 0x03000000)

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
	"A simple wrapper for gimp-pixel-art-scaler",
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
	m = Py_InitModule3("_pixel_art_scalers", templatemethods, "A simple wrapper for gimp-pixel-art-scaler");
#endif
	if (m == NULL)
#if PY3K
		return NULL;
#else
		return;
#endif

	hqxInit();
	xbr_init_data();

#if PY3K
	return m;
#endif
}

