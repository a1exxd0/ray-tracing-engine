# ray tracing engine
Added CI/CD.

# build notes
Set up environment:
```sh
# for running tests
sudo apt-get update
sudo apt-get install libgtest-dev

mkdir build
cd build && cmake ..
```
Install [Google Benchmark](https://github.com/google/benchmark). 
Then you have 2 options for builds:
```sh
# ensure you are in build directory

# default standard (slow run) build
cmake --build .

# for long runs
cmake --build . --config release
```
Then when running the executable:
```sh
./main > img.ppm
eog img.ppn
```