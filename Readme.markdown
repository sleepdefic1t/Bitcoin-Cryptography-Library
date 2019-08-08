BCL: Nayuki's Bitcoin Cryptography Library
==========================================
> A fork of Nayuki's Bitcoin Cryptography Library using CMake, PlatformIO & GoogleTest 

about
-----

All credit for [github.com/nayuki/Bitcoin-Cryptography-Library](https://github.com/nayuki/Bitcoin-Cryptography-Library) goes to [Nayuki](https://www.nayuki.io).
Although this fork _does_ rearrange quite a few things, it attempts to change very little of the original code itself. It is primarily concerned with repackaging BCL, an already-excellent library, to better suit my own uses.
Please see the changelog for more details. 

Requirements
------------

-   Git
-   Cmake

This project builds out of source
---------------------------------

```bash
mkdir build && cd build && cmake ../ && cmake --build .
```

Run tests after building:
```bash
# from the build dir
./test/bcl_tests
```



TODO
----
-    limit fixture sizes for IoT.
-    improve tests cases.
-    re-implement X8664 code.
-    re-implement CountOps.

Nayuki's Bitcoin cryptography library
=====================================

This project implements the cryptographic primitives used in the Bitcoin system,
especially elliptic curve operations and hash functions.

The code is written in two independent versions in C++. It includes a
test suite of over a thousand test vectors that cover every feature provided by
the library.

The library is open-source, and is written by Nayuki from the ground up. It is
designed with portability and clarity in mind, and is rigorously verified for
correctness and quality.

More details about features and design principles are on the main web page:
[https://www.nayuki.io/page/bitcoin-cryptography-library](https://www.nayuki.io/page/bitcoin-cryptography-library)


License
-------

Copyright © 2019 Project Nayuki. (MIT License)

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

* The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

* The Software is provided "as is", without warranty of any kind, express or
  implied, including but not limited to the warranties of merchantability,
  fitness for a particular purpose and noninfringement. In no event shall the
  authors or copyright holders be liable for any claim, damages or other
  liability, whether in an action of contract, tort or otherwise, arising from,
  out of or in connection with the Software or the use or other dealings in the
  Software.
