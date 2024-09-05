# Reproduce for a Memory Leak in ROOT

## Build & Test
  
  ```bash
  mkdir build 
  cd build
  cmake ..
  make
  ./gen
  ./read
  ./read_old
  ```

## Behavior

During `./read` and `./read_old`, the output are like:
  ```
  a_member::a_member()  at 0x1da0b810
  a_member::a_member()  at 0x1de04590
  a_member::a_member()  at 0x1a504dd0
  a_member::a_member()  at 0x1de02f60
  a_member::~a_member() at 0x1de02f60
  ```
or
  ```
  a_member::a_member()  at 0x33280cb0
  a_member::a_member()  at 0x331d3a90
  a_member::a_member()  at 0x331d39d0
  a_member::a_member()  at 0x331d3720
  ```

The destructor is called only once, which is not expected. This could indicate a memory leak.

## What's special for this code?

`#pragma link C++ class TestData;` in `TestDataLinkDef.h`. If changing it to `#pragma link C++ class TestData+;` it won't reproduce the memory leak:
  ```
  a_member::a_member()  at 0x2dbf3d40
  a_member::a_member()  at 0x2db3bda0
  a_member::~a_member() at 0x2dbf3d40
  a_member::a_member()  at 0x2dbf3d40
  a_member::~a_member() at 0x2db3bda0
  a_member::a_member()  at 0x2db3bda0
  a_member::~a_member() at 0x2dbf3d40
  a_member::~a_member() at 0x2db3bda0
  ```
or
  ```
  a_member::a_member() at 0x40435f50
  a_member::a_member() at 0x3feeb270
  a_member::~a_member() at 0x40435f50
  a_member::a_member() at 0x40435f50
  a_member::~a_member() at 0x3feeb270
  a_member::a_member() at 0x3feeb270
  a_member::~a_member() at 0x40435f50
  ```
Which don't seems to have any serious memory leak.