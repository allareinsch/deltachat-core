import setuptools
import os
import re


def main():
    long_description, version = read_meta()
    setuptools.setup(
        name='deltachat',
        version=version,
        description='Python bindings for deltachat-core using CFFI',
        long_description = long_description,
        author='holger krekel, bjoern petersen and contributors',
        setup_requires=['cffi>=1.0.0'],
        install_requires=['cffi>=1.0.0', 'requests', 'attrs'],
        packages=setuptools.find_packages('src'),
        package_dir={'': 'src'},
        cffi_modules=['src/deltachat/_build.py:ffibuilder'],
        classifiers=[
            'Development Status :: 3 - Alpha',
            'Intended Audience :: Developers',
            'License :: OSI Approved :: GNU General Public License (GPL)',
            'Programming Language :: Python :: 3',
            'Topic :: Communications :: Email',
            'Topic :: Software Development :: Libraries',
        ],
    )


def read_meta():
    with open('README.rst') as fd:
        long_description = fd.read()
    with open(os.path.join("src", "deltachat", "__init__.py")) as f:
        for line in f:
            m = re.match('__version__ = "(\S*).*"', line)
            if m:
                version, = m.groups()

    with open("README.rst") as f:
        long_desc = f.read()
    return long_desc, version


if __name__ == "__main__":
    main()

