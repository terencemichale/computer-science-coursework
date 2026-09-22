# C++ exercises — CS 210

Build each project separately with a C++17 compiler. The commands below use GCC/Clang; Windows users can use a compatible compiler or a Visual Studio developer terminal.

| Folder | Build command from that folder | Run behavior |
| --- | --- | --- |
| `investment-calculator` | `g++ -std=c++17 bankingMain.cpp banking.cpp -o investment-calculator` | Compare growth with and without monthly deposits |
| `chada-clocks` | `g++ -std=c++17 main.cpp -o chada-clocks` | Display and adjust 12/24-hour clocks |
| `calculator` | `g++ -std=c++17 main.cpp -o calculator` | Integer arithmetic; division truncates |
| `temperature-converter` | `g++ -std=c++17 FahrenheitToCelsius.cpp -o temperature-converter` | Read the included input file; write `CelsiusTemperature.txt` |

Run the output executable from its exercise folder. Alternatively, build all four from the repository root with `cmake -S . -B build` and `cmake --build build --config Release`. Local verification notes identify what was tested. These examples demonstrate coursework progression and are not financial tools or production utilities.

Portfolio fixes to the calculator use standard `int main`, validate malformed expressions, and reject zero divisors. The investment program explicitly includes its numeric-limits dependency. Other original comments are retained as learning history. The calculator is intended for small integers; arithmetic overflow and exhaustive boundary validation remain learning opportunities.
