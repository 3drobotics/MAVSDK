<img alt="MAVSDK" src="https://mavsdk.mavlink.io/develop/assets/site/sdk_logo_full.png" width="400">

[![travis-ci build status](https://travis-ci.org/mavlink/MAVSDK.svg?branch=develop)](https://travis-ci.org/mavlink/MAVSDK)
[![Coverage Status](https://coveralls.io/repos/github/mavlink/MAVSDK/badge.svg?branch=develop)](https://coveralls.io/github/mavlink/MAVSDK?branch=develop)

## Description

[MAVSDK](https://mavsdk.mavlink.io/develop/en/) is a set of libraries providing a high-level API to [MAVLink](https://mavlink.io/en/).
It aims to be:
- Easy to use with a simple API supporting both synchronous (blocking) API calls and asynchronous API calls using callbacks.
- Fast and lightweight.
- Cross-platform (Linux, Mac, Windows, iOS, Android).
- Extensible (using compile-time plugins).
- Fully compliant with the MAVLink common microservices standard/definitions.

The core library is written in C++ and is used as the common "backend" to auto-generated front end libraries for different programming languages. The generated libraries share similar APIs (because they are autogenerated from a common interface) but follow idiomatic patterns expected by end users (for example, the Python library is installed from PyPi using *pip*, and includes everything you need to get up and running).

This repo contains the source code for the C++ core.
Other important repos include:
- [MAVSDK-Proto](https://github.com/mavlink/MAVSDK-Proto) - Collection of proto files used by gRPC in MAVSDK (common interface definitions)
- [MAVSDK-Python](https://github.com/mavlink/MAVSDK-Python) - MAVSDK client for Python
- [MAVSDK-Swift](https://github.com/mavlink/MAVSDK-Swift) - MAVSDK client for Swift.
- [MAVSDK-Java](https://github.com/mavlink/MAVSDK-Java) - MAVSDK client for Java.
- [MAVSDK-JavaScript](https://github.com/mavlink/MAVSDK-JavaScript) - JS Wrapper for MAVSDK using grpc-web to generate static http client compatible with Envoy Proxy
- [Other repos](https://github.com/mavlink?q=MAVSDK) - Docs, examples, etc.


## Status

- C++ core library (2016). Reliable and stable - used in production.
- MAVSDK-Swift (2018): Reliable and stable - used in production.
- MAVSDK-Python (2019): First PyPi release 2019.
- MAVSDK-Java (2019): Prototype.
- MAVSDK-JavaScript (2019). Proof of concept.



## Docs (Build instructions etc.)

Instructions for how to use the C++ library can be found in the [SDK Guide](https://mavsdk.mavlink.io/develop/en/) (links to other programming languages can be found from the documentation sidebar).

Quick Links:

- [QuickStart](https://mavsdk.mavlink.io/develop/en/cpp/#getting-started)
- [C++ API Overview](https://mavsdk.mavlink.io/develop/en/cpp/#api-overview)
- [Building the Library](https://mavsdk.mavlink.io/develop/en/contributing/build.html)
- [Examples](https://mavsdk.mavlink.io/develop/en/examples/)
- [API Reference](https://mavsdk.mavlink.io/develop/en/api_reference/)
- [FAQ](https://mavsdk.mavlink.io/develop/en/getting_started/faq.html)


## License

This project is licensed under the permissive BSD 3-clause, see [LICENSE.md](LICENSE.md).
