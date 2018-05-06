# Introduction to data structures

I started reading the basic book [Data structures in C](https://www.amazon.com/Data-Structures-C-Noel-Kalicharan/dp/1438253273/) and these are my notes and tests.

To build the unit tests and run it you need to have [Criterion](https://github.com/Snaipe/Criterion) and [Meson](http://mesonbuild.com/) with [Ninja](https://ninja-build.org/) installed (I will put a makefile later when I finish the book).

To build the project (once you have the requirements installed):

```
meson builddir
```

And you can run the tests:

```
ninja -C builddir tests
```

My notes lives in the Markdown document [Basic data structures in C](Basic_data_structures_in_C.md), and the exercises lives in a Python notebook [Data_structures_in_C.ipynb](Data_structures_in_C.ipynb). 
