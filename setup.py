"""A setuptools based setup module.
See:
https://packaging.python.org/en/latest/distributing.html
https://github.com/pypa/sampleproject
"""

# Always prefer setuptools over distutils
from setuptools import setup, Extension
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
    url='https://github.com/JensRestemeier/python-pixel-art-scalers',

    # Author details
    author='Jens Ch. Restemeier',
    author_email="jens.restemeier@gmail.com",

    # Choose your license
    license='GPL3',

    install_requires=[
        'pillow',  
    ],

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
        'License :: OSI Approved :: GNU General Public License v3 (GPLv3)',

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

    keywords=['pixel art', 'hqx', 'xbr', 'scalex'],

    packages=['pixel_art_scalers'],

    platforms = ["Windows", "Linux", "MacOS"],
    
    include_package_data=True,

    ext_modules = [module1],
)
