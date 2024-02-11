# 103cipher

## Module: B-MAT-100 (Grade: A)

## Project Description
 Encryption and Decryption via matrix computation in C

### USAGE
 ./103cipher message key flag
# Result: 100% (Mark: 20)
<details>
<summary>Click to expand test results</summary>

### 1-rigor (100% Passed)
| Test | Status |
| --- | --- |
| 1a-no arguments | PASSED |
| 1b-not enough arguments | PASSED |
| 1c-too many arguments | PASSED |
| 1d-incorrect argument 1 | PASSED |
| 1e-incorrect argument 2 | PASSED |
| 1f-output instructions 1 | PASSED |
| 1g-output instructions 2 | PASSED |

### 2-matrix (100% Passed)
| Test | Status |
| --- | --- |
| 2a-length of key: 1 | PASSED |
| 2b-length of key: 3 | PASSED |
| 2c-length of key: 4 | PASSED |
| 2d-length of key: 7 | PASSED |
| 2e-length of key: 8 | PASSED |
| 2f-length of key: 9 | PASSED |
| 2g-length of key: 13 | PASSED |
| 2h-length of key: 14 | PASSED |

### 3-encryption (100% Passed)
| Test | Status |
| --- | --- |
| 3a-length of key: 1 | PASSED |
| 3b-length of key: 3 | PASSED |
| 3c-length of key: 4 | PASSED |
| 3d-length of key: 7 | PASSED |
| 3e-length of key: 8 | PASSED |
| 3f-length of key: 9 | PASSED |
| 3g-length of key: 13 | PASSED |
| 3h-length of key: 14 | PASSED |

### 4-decryption (100% Passed)
| Test | Status |
| --- | --- |
| 4a-length of key: 1 | PASSED |
| 4b-length of key: 3 | PASSED |
| 4c-length of key: 4 | PASSED |
| 4d-length of key: 9 | PASSED |
| 4e-no invert, length of key: 2 | PASSED |
| 4f-no invert, length of key: 5 | PASSED |

### 5-decryption size 4 (bonus) (100% Passed)
| Test | Status |
| --- | --- |
| 5a-length of key: 16 | PASSED |
| 5b-length of key: 16 bis | PASSED |

</details>


## Bonuses
Matrix inversion for all square matrix size

## Tests
a test.sh script that encrypt and decrypt a message to check the inversion and everything

