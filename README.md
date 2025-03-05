# a way to create an object and initialize it only when needed from the passed lambda function.

**Author**: Peter Foelsche |
**Date**: October 2024..January 2025 |
**Location**: Austin, TX, USA |
**Email**: [peter_foelsche@outlook.com](mailto:peter_foelsche@outlook.com)

## Introduction

Often I used to have the following problem: I needed to create an object with a scope which differed from the point at which I knew if it was actually needed.
This gave me the idea of make_lazy.
