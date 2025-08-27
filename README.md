# C++ Foundations

A collection of early C++ console programs. Each source file builds to its own executable and demonstrates a core concept (I/O, arithmetic, selection, loops, arrays, functions, and C‑strings).

> **Tooling:** CMake creates one executable per `*.cpp` (named after the file). The project targets **C++20**.

---

## 📁 Project Layout

```
c-foundations/
├─ CMakeLists.txt
├─ README.md
├─ currency_denominations.cpp      # break amount into bills/coins
├─ merge_sorted_arrays.cpp         # two-pointer merge into one sorted array
├─ linked_list_basics.cpp          # singly linked list (ID/grade)
├─ sample_receipt.cpp              # formatted store receipt
├─ squares_in_circle.cpp           # area ratio: how many squares fit in a circle
├─ wage_calculator.cpp             # retail pay: hourly vs. commission
├─ eggfarm_batch_calculator.cpp    # egg batch totals, percentages, dozens
├─ pc_build_configurator.cpp       # PC builder & price estimator (functions)
├─ plastics_purchase_order.cpp     # recycled plastics purchase order
└─ password_helper.cpp             # password rules + confirmation (C-strings)
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
.uild\Release\currency_denominations.exe
.uild\Release\merge_sorted_arrays.exe
.uild\Release\linked_list_basics.exe
.uild\Release\sample_receipt.exe
.uild\Release\squares_in_circle.exe
.uild\Release\wage_calculator.exe
.uild\Release\eggfarm_batch_calculator.exe
.uild\Release\pc_build_configurator.exe
.uild\Release\plastics_purchase_order.exe
.uild\Release\password_helper.exe
```

### macOS / Linux (default Makefiles or Ninja)
```bash
cmake -S . -B build
cmake --build build -j
# Run any executable created by CMake:
./build/currency_denominations
./build/merge_sorted_arrays
./build/linked_list_basics
./build/sample_receipt
./build/squares_in_circle
./build/wage_calculator
./build/eggfarm_batch_calculator
./build/pc_build_configurator
./build/plastics_purchase_order
./build/password_helper
```

> 💡 CMake detects all `*.cpp` in the folder and makes one target per file. Add another `Foo.cpp` and rerun the two CMake commands above—CMake will generate a `Foo` executable automatically.

---

## 📚 Program Index

| Executable (target) | What it does | Core topics | Typical interaction |
|---|---|---|---|
| `currency_denominations` | Breaks a money amount into **bills & coins** (100s…1s, quarters…pennies). | integer arithmetic, modulo, formatting | Prompts for an amount like `123.45` |
| `merge_sorted_arrays` | Merges two **pre‑sorted arrays** into a single sorted array via the **two‑pointer merge** step. | arrays, loops, algorithmic complexity | No input (arrays auto‑generated) |
| `linked_list_basics` | Creates and traverses a **singly linked list** of students (random ID, grade); counts total and `A` grades. | structs, pointers, traversal | No input |
| `sample_receipt` | Prints a formatted **store receipt**, sums subtotal, applies tax, and prints total. | I/O, constants, strings, arithmetic | No input |
| `squares_in_circle` | Computes how many **squares fit inside a circle** by **area ratio** (circle area ÷ square area). | I/O, `iomanip`, numeric constants | Prompts for circle **diameter** and square **side** |
| `wage_calculator` | Calculates an employee’s **net pay** using either **hourly** (with overtime) **or commission tiers**—whichever is higher. | input validation, conditionals, `iomanip` | Prompts for **hours worked** and **weekly sales** |
| `eggfarm_batch_calculator` | Aggregates an egg batch: totals **white/brown**, **percentages**, and **dozens** per type. | loops, validation, integer & floating‑point math | Prompts for **baskets**, then counts per basket |
| `pc_build_configurator` | PC **configurator & pricer**: choose CPU speed, storage, RAM, touchscreen; computes price. | **functions**, pass‑by‑reference, decomposition | Repeats builds until the user quits |
| `plastics_purchase_order` | Builds a **recycled plastics purchase order** with weights, unit prices, line totals, and grand totals. | **arrays**, table formatting | Prompts for pounds per plastic type |
| `password_helper` | **Password helper** that enforces: length 6–20, no spaces, at least one uppercase, lowercase, digit, and punctuation; then confirmation. | **C‑strings**, `<cctype>`, `<cstring>`, loops | Prompts until rules pass; then confirm |

## 📝 Program Notes

### currency_denominations — “Currency breakdown”
- Prompts for a money amount.
- Computes number of bills ($100…$1) and coins (quarters, dimes, nickels, pennies).
- Demonstrates integer division and modulo.

**Run:** `./currency_denominations`

---

### merge_sorted_arrays — “Merge step”
- Generates two strictly increasing integer arrays.
- Uses the classic **two‑pointer merge** to produce a combined sorted array.

**Run:** `./merge_sorted_arrays` (no input)

---

### linked_list_basics — “Student linked list”
- Builds a small linked list of `Student` nodes with random IDs and grades.
- Traverses the list, printing values, counting nodes, and tallying `A` grades.

**Run:** `./linked_list_basics` (no input)

---

### sample_receipt — “Store receipt”
- Hard‑coded item names and prices; computes subtotal, tax, and total.
- Demonstrates formatted output and use of constants.

**Run:** `./sample_receipt` (no input)

---

### squares_in_circle — “Squares in a circle”
- Asks for circle **diameter** and square **side length**.
- Computes areas and divides to estimate how many squares “fit” inside.

**Run:** `./squares_in_circle`  
**Input:** `diameter`, then `square side`

---

### wage_calculator — “Retail pay”
- Validates non‑negative **hours** and **sales**.
- Computes hourly pay (with overtime) vs commission (tiered) and prints the higher.

**Run:** `./wage_calculator`  
**Input:** `hours worked`, `weekly sales`

---

### eggfarm_batch_calculator — “Egg batch stats”
- Prompts for number of **baskets**, then counts **white** and **brown** eggs per basket.
- Prints totals, percentages, and dozen counts.

**Run:** `./eggfarm_batch_calculator`  
**Input:** `num baskets`, then counts for white and brown per basket

---

### pc_build_configurator — “PC builder & pricer”
- Three‑function design:
  - `userInput(...)` gathers selections.
  - `calculateTotal(...)` derives cost from base + increments.
  - `displayBuild(...)` prints results.
- Loops to allow multiple builds.

**Run:** `./pc_build_configurator`  
**Input:** CPU GHz, storage GB, RAM GB, touchscreen Y/N

---

### plastics_purchase_order — “Recycled plastics order”
- Parallel arrays for plastic types, prices, user‑entered weights, and line totals.
- Prints an aligned purchase order with totals.

**Run:** `./plastics_purchase_order`  
**Input:** pounds for each plastic type

---

### password_helper — “Password generator & validator”
- Enforces password rules: 6–20 chars, no spaces, ≥1 upper, lower, digit, punctuation.
- Prompts until valid, then requires re‑entry to confirm.

**Run:** `./password_helper`  
**Input:** password string, then confirmation

---

## 🔧 Building Tips

- If you add new `.cpp` files at the top level, CMake will automatically create a new executable for each on the next configure/generate step.
- On Windows, the built executables live under `build\{Debug|Release}\` when using Visual Studio generators.
- If a program appears to “hang,” it’s usually waiting for input—check the “Typical interaction” column or the “Run” notes above.

---

## ✅ License / Usage

These are educational exercises; feel free to use, modify, and extend for learning purposes.
