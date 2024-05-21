# Overview

I have learned some simple CUDA programming in the past, but I haven't studied it in depth.
In the next period of weeks, I want to use my free time to learn CUDA programming systematically.
In my plan, I need to read through the latest CUDA documents and take notes.

## Programming Environments

NVIDIA releases a new major version of CUDA approximately every two years, and with the latest version being 12.4, some of the APIs from older tutorials have been marked as deprecated or even removed. This note will not explore the history of API changes, but will be based on CUDA 12.4.

| env      | version |
|----------|---------|
| OS       | Ubuntu 22.04 |
| Compiler | GCC 10.3 |
| CUDA | 12.4 |
| CUDNN | 9.1 |

> You can find cuda release date in [CUDA Archive](https://developer.nvidia.com/cuda-toolkit-archive)
{style = "note"}

## Sample Code

The sample code can be found in [https://github.com/malanore-z/cuda_learning_notes](https://github.com/malanore-z/cuda_learning_notes).

Every commit in the master branch is compilable, and can be unit-tested.  
And the commit message will be prefixed with one of the following types of prefixes:

[feat]
: Add new features. Typically, it corresponds to a section in this note.

[fix]
: Fix existing bugs.

[patch]
: Add new features or parameters to base components or methods without changing the original feature.

[chore]
: Something do not affect the features of code. For example, typo, style, refactor, etc.

The sample code uses C++ 20.
