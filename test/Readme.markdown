
BCL Tests
=========

Build and run unit tests using GoogleTest
-----------------------------------------

Build out of Source
```bash
mkdir build && cd build && cmake ../ && cmake --build .
```

Run tests after building:
```bash
# from the build dir
./test/bcl_tests
```

Successful Tests!
```bash
[==========] Running 43 tests from 11 test suites.
[----------] Global test environment set-up.
[----------] 6 tests from base58check
[ RUN      ] base58check.public_address_export
[       OK ] base58check.public_address_export (6 ms)
[ RUN      ] base58check.public_address_import
[       OK ] base58check.public_address_import (4 ms)
[ RUN      ] base58check.private_key_export
[       OK ] base58check.private_key_export (14 ms)
[ RUN      ] base58check.private_key_import
[       OK ] base58check.private_key_import (15 ms)
[ RUN      ] base58check.extended_private_key_export
[       OK ] base58check.extended_private_key_export (77 ms)
[ RUN      ] base58check.extended_private_key_import
[       OK ] base58check.extended_private_key_import (147 ms)
[----------] 6 tests from base58check (263 ms total)

[----------] 7 tests from curve_point
[ RUN      ] curve_point.replace
[       OK ] curve_point.replace (0 ms)
[ RUN      ] curve_point.twice
[       OK ] curve_point.twice (6 ms)
[ RUN      ] curve_point.add
[       OK ] curve_point.add (11 ms)
[ RUN      ] curve_point.multiply
[       OK ] curve_point.multiply (472 ms)
[ RUN      ] curve_point.multiply_mod_order
[       OK ] curve_point.multiply_mod_order (3169 ms)
[ RUN      ] curve_point.is_on_curve
[       OK ] curve_point.is_on_curve (4 ms)
[ RUN      ] curve_point.private_exponent_to_public_point
[       OK ] curve_point.private_exponent_to_public_point (61 ms)
[----------] 7 tests from curve_point (3723 ms total)

[----------] 2 tests from ecdsa
[ RUN      ] ecdsa.sign_and_verify
[       OK ] ecdsa.sign_and_verify (19063 ms)
[ RUN      ] ecdsa.verify
[       OK ] ecdsa.verify (12477 ms)
[----------] 2 tests from ecdsa (31540 ms total)

[----------] 1 test from extended_private_key
[ RUN      ] extended_private_key.child_keys
[       OK ] extended_private_key.child_keys (78 ms)
[----------] 1 test from extended_private_key (78 ms total)

[----------] 8 tests from field_int
[ RUN      ] field_int.comparison
[       OK ] field_int.comparison (0 ms)
[ RUN      ] field_int.add
[       OK ] field_int.add (0 ms)
[ RUN      ] field_int.subtract
[       OK ] field_int.subtract (0 ms)
[ RUN      ] field_int.multiply2
[       OK ] field_int.multiply2 (0 ms)
[ RUN      ] field_int.multiply
[       OK ] field_int.multiply (0 ms)
[ RUN      ] field_int.square
[       OK ] field_int.square (0 ms)
[ RUN      ] field_int.reciprocal
[       OK ] field_int.reciprocal (16 ms)
[ RUN      ] field_int.constructor_uint256
[       OK ] field_int.constructor_uint256 (0 ms)
[----------] 8 tests from field_int (17 ms total)

[----------] 1 test from keccak
[ RUN      ] keccak.tests
[       OK ] keccak.tests (1 ms)
[----------] 1 test from keccak (1 ms total)

[----------] 1 test from ripemd160
[ RUN      ] ripemd160.hashing
[       OK ] ripemd160.hashing (2 ms)
[----------] 1 test from ripemd160 (2 ms total)

[----------] 4 tests from sha256
[ RUN      ] sha256.single_hash
[       OK ] sha256.single_hash (1 ms)
[ RUN      ] sha256.double_hash
[       OK ] sha256.double_hash (0 ms)
[ RUN      ] sha256.hmac
[       OK ] sha256.hmac (0 ms)
[ RUN      ] sha256.stateful_hasher
[       OK ] sha256.stateful_hasher (0 ms)
[----------] 4 tests from sha256 (46 ms total)

[----------] 2 tests from sha256hash
[ RUN      ] sha256hash.equality
[       OK ] sha256hash.equality (0 ms)
[ RUN      ] sha256hash.get_byte
[       OK ] sha256hash.get_byte (0 ms)
[----------] 2 tests from sha256hash (0 ms total)

[----------] 2 tests from sha512
[ RUN      ] sha512.single_hash
[       OK ] sha512.single_hash (7 ms)
[ RUN      ] sha512.hmac
[       OK ] sha512.hmac (0 ms)
[----------] 2 tests from sha512 (8 ms total)

[----------] 9 tests from uint256
[ RUN      ] uint256.comparison
[       OK ] uint256.comparison (0 ms)
[ RUN      ] uint256.add
[       OK ] uint256.add (0 ms)
[ RUN      ] uint256.subtract
[       OK ] uint256.subtract (0 ms)
[ RUN      ] uint256.shift_left_1
[       OK ] uint256.shift_left_1 (0 ms)
[ RUN      ] uint256.shift_right_1
[       OK ] uint256.shift_right_1 (0 ms)
[ RUN      ] uint256.reciprocal
[       OK ] uint256.reciprocal (27 ms)
[ RUN      ] uint256.replace_and_swap
[       OK ] uint256.replace_and_swap (0 ms)
[ RUN      ] uint256.constructor_bytes
[       OK ] uint256.constructor_bytes (0 ms)
[ RUN      ] uint256.get_big_endian_bytes
[       OK ] uint256.get_big_endian_bytes (0 ms)
[----------] 9 tests from uint256 (27 ms total)

[----------] Global test environment tear-down
[==========] 43 tests from 11 test suites ran. (35705 ms total)
[  PASSED  ] 43 tests.
```
