# Verification

- All four C++ programs compiled with Microsoft Visual C++ 19.29 using C++17.
- Java source compiled with Microsoft OpenJDK 21.
- A Swing construction check loaded five destinations and all five images at the expected width without displaying a window.
- All included Python exercises passed syntax compilation.

Run `python tests/check_examples.py build/Release` after a Visual Studio CMake build, or `python tests/check_examples.py build` for a single-configuration generator. This exercises calculator validation, clock rollover, a compound-interest example, temperature conversion, and exiting the text adventure.

These are focused smoke checks, not exhaustive validation of every interactive exercise or platform. The Java interface was constructed and resources checked; it was not manually tested across screen sizes. Original classroom limitations remain documented in the language READMEs.
