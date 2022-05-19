"""A setuptools based setup module.
See:
https://packaging.python.org/en/latest/distributing.html
https://github.com/pypa/sampleproject
"""

# Always prefer setuptools over distutils
from setuptools import setup, find_packages, Extension
# To use a consistent encoding
from codecs import open
from os import path

module1 = Extension('_pixel_art_scalers',
                    sources = ['pixel_art_scalers.c'] +
                    [path.normpath(path.join('gimp-plugin-pixel-art-scalers/src', x)) for x in [
                        'hq2x.c',
                        'hq3x.c',
                        'hq4x.c',
                        'hqx_init.c',
                        'scaler_scalex.c',
                        'xbr.c'
                    ]],
                    include_dirs=['gimp-plugin-pixel-art-scalers/src'])

here = path.abspath(path.dirname(__file__))

setup(
    name='pixel-art-scalers',

    # Versions should comply with PEP440.  For a discussion on single-sourcing
    # the version across setup.py and the project code, see
    # https://packaging.python.org/en/latest/single_source_version.html
    version='0.0.1',

    description='Wrapper for pixel art scaler plugin',
    long_description="",

    # The project's main homepage.
    url='',

    # Author details
    author='Jens Ch. Restemeier',
    author_email="jens.restemeier@gmail.com",

    # Choose your license
    license='GPL3',

##    install_requires=[],

    # See https://pypi.python.org/pypi?%3Aaction=list_classifiers
    classifiers=[
        # How mature is this project? Common values are
        #   3 - Alpha
        #   4 - Beta
        #   5 - Production/Stable
        'Development Status :: 3 - Alpha',

        # Indicate who your project is intended for
        'Intended Audience :: Developers',

        # Pick your license as you wish (should match "license" above)
        'License :: Public Domain',

        # Specify the Python versions you support here. In particular, ensure
        # that you indicate whether you support Python 2, Python 3 or both.
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 3',
        
        'Operating System :: Microsoft :: Windows',
        'Operating System :: POSIX :: Linux',
        "Operating System :: MacOS",
        "Operating System :: OS Independent",
        
        'Topic :: Software Development :: Libraries'
        
    ],

    # What does your project relate to?
    keywords='pixel art',

    # You can just specify the packages manually here if your project is
    # simple. Or you can use find_packages().
    packages=['pixel_art_scalers'],

    platforms = ["Windows", "Linux", "MacOS"],
    
    include_package_data=True,

    ext_modules = [module1],

    # List run-time dependencies here.  These will be installed by pip when
    # your project is installed. For an analysis of "install_requires" vs pip's
    # requirements files see:
    # https://packaging.python.org/en/latest/requirements.html

    # List additional groups of dependencies here (e.g. development
    # dependencies). You can install these using the following syntax,
    # for example:
    # $ pip install -e .[dev,test]

    # If there are data files included in your packages that need to be
    # installed, specify them here.  If using Python 2.6 or less, then these
    # have to be included in MANIFEST.in as well.

    # Although 'package_data' is the preferred approach, in some case you may
    # need to place data files outside of your packages. See:
    # http://docs.python.org/3.4/distutils/setupscript.html#installing-additional-files # noqa
    # In this case, 'data_file' will be installed into '<sys.prefix>/my_data'

    # To provide executable scripts, use entry points in preference to the
    # "scripts" keyword. Entry points provide cross-platform support and allow
    # pip to create the appropriate form of executable for the target platform.
)
