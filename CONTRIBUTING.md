# Contributing to CoLand 🏛️

First off, thank you for considering contributing to CoLand! 🎉  
Your help is what makes this project better.

---

## How Can I Contribute?

### Reporting Bugs 🐛

If you find a bug, please open an issue on GitHub with:

- A clear title and description
- Steps to reproduce the issue
- Expected vs actual behavior
- Your OS and compiler version
- If possible, a minimal code example

### Suggesting Features 💡

Feature requests are welcome! Please open an issue and clearly describe:

- What you want to add
- Why it's useful
- How it should work (if you have ideas)

### Pull Requests 🔧

1. Fork the repository.
2. Create a new branch:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Make your changes.
4. Test your changes.
5. Commit with a clear message:
   ```bash
   git commit -m "feat: add your feature description"
   ```
6. Push to your fork:
   ```bash
   git push origin feature/your-feature-name
   ```
7. Open a Pull Request.

---

## Code Style

- C++17 standard
- Use `snake_case` for functions and variables
- Use `PascalCase` for classes
- Use `m_` prefix for class members (e.g., `m_name`)
- Use `k` prefix for constants (e.g., `kMaxAge`)

Example:

```cpp
class Colonist {
private:
    std::string m_name;
    int m_age;
    static const int kMaxAge = 120;

public:
    void set_name(const std::string& name);
};
```

---

## Development Setup

### Prerequisites

- CMake 3.15+
- C++17 compiler (Clang, GCC, or MSVC)
- Git

### Build

```bash
git clone https://github.com/your-username/CoLand.git
cd CoLand
mkdir build && cd build
cmake .. -DENABLE_GUI=ON
cmake --build .
```

### Build Options

| Option | Description |
|--------|-------------|
| `-DENABLE_GUI=ON` | Build with Raylib GUI |
| `-DENABLE_GUI=OFF` | Build with TUI (console) |
| `-DCMAKE_BUILD_TYPE=Debug` | Debug build |
| `-DCMAKE_BUILD_TYPE=Release` | Release build |

---

## Testing

To run tests (if any):

```bash
ctest
```

---

## License

By contributing, you agree that your contributions will be licensed under the **GNU General Public License v3.0**.

---

## Contact

For questions, open an issue or contact:

- GitHub: [@Sharzhukov](https://github.com/Sharzhukov)
- Email: sharzhukov@sharzhukov.ru
