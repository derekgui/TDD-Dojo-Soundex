# TDD Dojo Soundex project

This project is the first TDD Dojo series project that I was inspired by the book [Modern C++ Programming with Test-Driven Development](https://pragprog.com/book/lotdd/modern-c-programming-with-test-driven-development)-`Jeff Langr`. 
It serves as a purpose that continuely sharpen my tdd skills with repeatedly practice agains the same example. 
As in the book saying: In addition to continually seeking new knowledge, successful professionals practice their craft on a regular basis. Musicians use scales as warm-up exercises, cosmetic surgeons practice on cadavers, athletes run drills and scrimmages, speakers warm up in front of a mirror, and martial arts practioners practice **katas**. 

### Note
Each branch is a new attempt and the master branch is project starter code.

### Spec
The Soundex algorithm encodes words into a letter plus three digits, mapping similarly sounding words to the same encoding which helps make searching more effective. Here are the rules, per [Wikipedia](http://en.wikipedia.org/wiki/Soundex):
1. Retain the first letter. Drop all other occurrences of a, e, i, o, u, y, h, w.
2. Replace consonants with digits (after the first letter):
    - b, f, p, v: 1
    - c, g, j, k, q, s, x, z: 2
    - d, t : 3
    - l: 4
    - m, n: 5
    - r: 6
3. If two adjacent letters encode to the same number, encode them instead as a single number. Also, do so if two letters with the same number are separated by h or w (but code them twice if separated by a vowel). This rule also applies to the first letter.
4. Stop when you have a letter and three digits. Zero-pad if needed.

## Dependencies for Running Locally
* cmake >= 2.8
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Cloning

When cloning this project, be sure to use the `--recurse-submodules` flag. Using HTTPS:
```
git clone https://github.com/derekgui/TDD-Dojo-Soundex.git 
--recurse-submodules
```
or with SSH:
```
git clone git@github.com:derekgui/TDD-Dojo-Soundex.git 
--recurse-submodules
```

## Compiling and Running

### Compiling
To compile the project, first, create a `build` directory and change to that directory:
```
mkdir build && cd build
```
From within the `build` directory, then run `cmake` and `make` as follows:
```
cmake ..
make
```
### Run Testing

The executables will be placed in the `bin` directory. From within `build`, you can run the project as follows:
```
../bin/test
```