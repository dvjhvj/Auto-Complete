# Secure Auto-Complete System

A auto-complete system built with **Trie** data structure and **Universal Hashing** to prevent Algorithmic Denial-of-Service (DoS) attacks.

## Team & Roles

| Member | Role | Focus Area |
| :--- | :--- | :--- |
| **Nguyen Quoc Bao Khang** | **Hashing & Security** | Implemented Universal Hashing logic, Collision Resolution (Separate Chaining), and security checks against Hash Flooding. |
| **Le Si Nhat Khue** | **Trie & System** | Architected the Trie structure, developed DFS traversal algorithms for suggestions, and built the Console User Interface. |

## Build & Run (VS Code & CMake)

This project uses **CMake**. The easiest way to run it is via Visual Studio Code with the **CMake Tools** extension.

### Prerequisites
* **Visual Studio Code** installed.
* **C/C++ Extension** and **CMake Tools** extension installed in VS Code.

### Steps to Build & Run
1. **Open the project** folder in VS Code.
2. **Configure:**
   * Press `Ctrl` + `Shift` + `P` (or `Ctrl` + `P` then type `>`) to open the Command Palette.
   * Type and select: **`CMake: Configure`**.
   * *Note: If asked to select a kit, choose your installed compiler (e.g., GCC or Clang).*
3. **Build:**
   * Press `Ctrl` + `Shift` + `P`.
   * Type and select: **`CMake: Build`**.
4. **Run:**
   * Press `Ctrl` + `Shift` + `P`.
   * Type and select: **`CMake: Run Without Debugging`**.

*(Alternatively, you can use the "Play" button in the status bar at the bottom of VS Code once CMake is configured).*

