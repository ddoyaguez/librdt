# LibRDT

LibRDT is an ANSI C library aimed at giving some basic structures to work with,
such as linked lists and binary search trees.
It is designed with reusability as it's first priority.

LibRDT includes an exhaustive documentation (Doxygen) and an exhaustive test suite (coded in ANSI C).

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

In order to compile LibRDT you will need the following packages:
* libc6
* libc6-dev

In order to generate the documentation you will need the following packages:
* doxygen
* texlive
* texlive-base
* texlive-extra-utils
* texlive-generic-extra
* texlive-latex-extra


### Installing

Open a terminal.

Clone this git repository (in order to tho this you need the package git installed)
```
git clone https://github.com/ddoyaguez/librdt.git
```

Enter the source top directory
```
cd librdt
```

Configure the package. If this step fails see 'Prerequisites'
```
./configure
```

Compile librdt
```
make
```

Install
```
sudo make install
```

In order to compile your C code against librdt you have to use the flag -lrdt in every gcc compilation line of your Makefile

## Running the tests

The tests can be run executing in the source top directory the next command:
```
make check
```

## Generating the documentation

The documentation can be built using Doxygen
From the source top directory, enter into the doc directory.
```
cd doc
```

Execute Doxygen
```
doxygen Doxyfile
```

This will generate html documentation (you can open it with your web browser opening the file doc/html/index.html), PDF documentation (doc/latex/refman.pdf) and man pages (doc/man/man3)


## Built With

* [Autotools](https://www.gnu.org/software/automake/) - The build system used
* [Doxygen](http://www.stack.nl/~dimitri/doxygen/) - The documentation generator used

## Contributing

Contributions are welcome. I encourage you to contact me via email (daviddoyaguez@gmail.com)
and putting in the subject the prefix [librdt] and a brief explaination of your idea.
Longer explaination on the email body.
This library is aimed at being lightweight, well documented and reusable, but any (ANY) ideas are welcome.
Every pull request should compile without warnings and not break the tests.
New functions or structures should be documented with Doxygen (not generating Doxygen warnings).
It is necessary to include new test cases in the pull request, so it can be possible to test the new functionality.
All test cases shall pass [Valgrind](http://valgrind.org/) without memory leaks or errors.

## Versioning

We use [SemVer](http://semver.org/) for versioning.

## Authors

* **David Doyágüez** - *Initial work* - [ddoyaguez](https://github.com/ddoyaguez)


## License

This project is licensed under the GPLv3 License - see the [LICENSE](LICENSE) file for details

## TO-DO

* Implementation of a hash table would be very appreciated
* Revision of the Autotools configuration
