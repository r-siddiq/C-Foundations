# C++ Foundations

A collection of early C++ console programs. Each source file builds to its own executable and demonstrates a core concept (I/O, arithmetic, selection, loops, arrays, functions, and C‑strings).

> **Tooling:** CMake creates one executable per `*.cpp` (named after the file). The project targets **C++20**.

---

## 📁 Project Layout

```
C++ Foundations/
├─ CMakeLists.txt
├─ RahimSiddiq_Lab2.cpp
├─ RahimSiddiq_Lab3.cpp
├─ RahimSiddiq_Lab4.cpp
├─ RahimSiddiq_Lab5.cpp
├─ RahimSiddiq_Lab6.cpp
├─ RahimSiddiq_Lab7.cpp
└─ RahimSiddiq_Lab8.cpp
```

---

## 🛠️ Prerequisites

- CMake **≥ 3.25**
- A C++20 compiler
  - Windows: MSVC (Visual Studio 2022)
  - macOS: Apple Clang (Xcode tools)
  - Linux: GCC 12+ or Clang 15+

No third‑party libraries are required.

---

## 🚀 Build Once, Run Any Program

From the repository root:

### Windows (Visual Studio generator)
```powershell
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Release
# Run any executable created by CMake:
.\build\Release\RahimSiddiq_Lab2.exe
.\build\Release\RahimSiddiq_Lab3.exe
.\build\Release\RahimSiddiq_Lab4.exe
.\build\Release\RahimSiddiq_Lab5.exe
.\build\Release\RahimSiddiq_Lab6.exe
.\build\Release\RahimSiddiq_Lab7.exe
.\build\Release\RahimSiddiq_Lab8.exe
```

### macOS / Linux (default Makefiles or Ninja)
```bash
cmake -S . -B build
cmake --build build -j
# Run any executable created by CMake:
./build/RahimSiddiq_Lab2
./build/RahimSiddiq_Lab3
./build/RahimSiddiq_Lab4
./build/RahimSiddiq_Lab5
./build/RahimSiddiq_Lab6
./build/RahimSiddiq_Lab7
./build/RahimSiddiq_Lab8
```

> 💡 CMake detects all `*.cpp` in the folder and makes one target per file. Add another `Foo.cpp` and rerun the two CMake commands above—CMake will generate a `Foo` executable automatically.

---

## 📚 Program Index

| Executable | What it does | Core topics | Typical interaction |
|---|---|---|---|
| `RahimSiddiq_Lab2` | Prints a formatted **Costco‑style receipt**, sums subtotal, applies tax, and prints total. | I/O, constants, strings, arithmetic | No input; it prints a sample receipt.|
| `RahimSiddiq_Lab3` | Computes how many **squares fit inside a circle** by **area ratio** (circle area ÷ square area). | I/O, `iomanip`, numeric constants | Prompts for circle **diameter** and square **side**.|
| `RahimSiddiq_Lab4` | Calculates an employee’s **net pay** using either **hourly** (with overtime) **or commission tiers**—whichever is higher. | Input validation, conditionals, `iomanip` | Prompts for **hours worked** and **weekly sales**.|
| `RahimSiddiq_Lab5` | Aggregates an egg batch: totals **white/brown**, **percentages**, and **dozens** per type. | Loops, validation, integer vs. floating‑point math | Prompts for number of **baskets**, then counts per basket.|
| `RahimSiddiq_Lab6` | PC **configurator & pricer**: user chooses CPU speed, storage, RAM, and touchscreen; program computes price. | **Functions**, pass‑by‑reference, decomposition, loops, formatting | Repeats builds until the user quits.|
| `RahimSiddiq_Lab7` | Builds a **recycled plastics purchase order** with a table for each plastic type, weight, unit price, and line total. | **Arrays**, parallel arrays, tabular output | Prompts for pounds per material type.|
| `RahimSiddiq_Lab8` | **Password helper** that enforces: length 6–20, no spaces, at least one uppercase, lowercase, digit, and punctuation; then confirmation. | **C‑strings**, `<cctype>`, `<cstring>`, loops | Prompts for a password until all rules pass, then confirm.|

---

## 📝 Program Notes

### Lab 2 — “Costco receipt”
- Hard‑coded item names and prices; computes subtotal, tax, and total.
- Demonstrates string use, constants, and simple arithmetic.

**Run:** `./RahimSiddiq_Lab2` (no input required)

---

### Lab 3 — “Squares in a circle”
- Asks for circle **diameter** and square **side length**.
- Uses `PI` constant; computes areas and prints `numSquares` with formatting.
- Note: result uses **area ratio**; it does **not** model geometric packing efficiency.

**Run:** `./RahimSiddiq_Lab3`  
**Input:** `diameter`, then `square side`

---

### Lab 4 — “Retail pay: hourly vs. commission”
- Validates non‑negative **hours** and **sales**.
- Computes hourly pay (with overtime threshold) and commission via four tiers; prints the larger (“net pay”).

**Run:** `./RahimSiddiq_Lab4`  
**Input:** `hours worked`, `weekly sales`

---

### Lab 5 — “Egg batch stats”
- Prompts for number of **baskets**, then loops to collect **white** and **brown** counts per basket.
- Prints totals, **percentages**, and **carton dozens** for each type.

**Run:** `./RahimSiddiq_Lab5`  
**Input:** `num baskets`, then per‑basket counts for white, then brown

---

### Lab 6 — “PC builder & pricer”
- Three‑function design:
  - `userInput(...)` gathers & validates selections (by reference).
  - `calculateTotal(...)` derives price from base + increments (CPU, storage, RAM, touchscreen) with markup.
  - `displayBuild(...)` prints the summary.
- Loop allows building multiple configurations.

**Run:** `./RahimSiddiq_Lab6`  
**Input:** CPU GHz, storage (GB), RAM (GB), touchscreen Y/N, then optionally build another

---

### Lab 7 — “Recycled plastics purchase order”
- Parallel arrays for **type names**, **prices per lb**, **entered weights**, and **line totals**.
- Prints an aligned table and grand totals (weight and cost).

**Run:** `./RahimSiddiq_Lab7`  
**Input:** pounds for each listed plastic type

---

### Lab 8 — “Password generator & validator”
- Enforces rules via `<cctype>` checks across a C‑string buffer.
- Repeats with specific hints until all rules pass; then asks to **confirm** (must match).

**Run:** `./RahimSiddiq_Lab8`  
**Input:** password string (6–20 chars, no spaces, at least one: upper, lower, digit, punctuation), then confirmation

---

## 🔧 Building Tips

- If you add new `.cpp` files at the top level, CMake will automatically create a new executable for each on the next configure/generate step.
- On Windows, the built executables live under `build\{Debug|Release}\` when using Visual Studio generators.
- If a program appears to “hang,” it’s usually waiting for input—check the “Typical interaction” column or the “Run” notes above.

---

## ✅ License / Usage

These are educational exercises; feel free to use, modify, and extend for learning purposes.