# ConfigForge

<div align="center">

![ConfigForge Logo](https://img.shields.io/badge/ConfigForge-v1.0.0-blue?style=for-the-badge&logo=gear)

**Modern C++ Configuration File Manager**

[![C++ Standard](https://img.shields.io/badge/C%2B%2B-20-blue?style=flat-square&logo=cplusplus)](https://en.cppreference.com/w/cpp/20)
[![CMake](https://img.shields.io/badge/CMake-3.20+-green?style=flat-square&logo=cmake)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey?style=flat-square)](https://github.com/dubskysteam/configforge)

*Validate, convert, merge, and transform JSON, YAML, TOML, and INI files with ease*

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Contributing](#-contributing)

</div>

---

## 🚀 Features

<table>
<tr>
<td width="50%">

### 🔍 **Validation & Analysis**
- Schema-based validation
- Syntax error detection
- Configuration linting
- Format compliance checking

### 🔄 **Format Conversion**
- JSON ↔ YAML ↔ TOML ↔ INI
- Pretty-printing options
- Encoding preservation
- Batch processing

</td>
<td width="50%">

### 🔀 **Intelligent Merging**
- Deep merge strategies
- Conflict resolution
- Override policies
- Backup generation

### ⚡ **Advanced Features**
- Hot-reload detection
- Environment variable expansion
- Template processing
- Plugin architecture

</td>
</tr>
</table>

---

## 📁 Project Structure

```
ConfigForge/
├── 📂 src/                    # Source files
│   ├── main.cpp               # Application entry point
│   └── 📂 parsers/            # Format-specific parsers
├── 📂 include/                # Header files
│   └── 📂 configforge/        # Public API headers
├── 📂 tests/                  # Unit tests
├── 📂 docs/                   # Documentation
├── 📂 examples/               # Usage examples
├── 📂 build/                  # Build output
├── CMakeLists.txt             # CMake configuration
├── README.md                  # This file
└── LICENSE                    # Not decided yet
```

---

## 🛠️ Installation

### Prerequisites

<div align="center">

| Requirement | Version | Status |
|------------|---------|--------|
| ![CMake](https://img.shields.io/badge/CMake-3.20+-blue?logo=cmake) | 3.20+ | Required |
| ![C++](https://img.shields.io/badge/C++-20-blue?logo=cplusplus) | C++20 | Required |
| ![Git](https://img.shields.io/badge/Git-Any-red?logo=git) | Any | Required |

</div>

### Quick Start

```
# Clone the repository
git clone https://github.com/dubskysteam/configforge.git
cd configforge

# Configure with CMake
cmake -S . -B build

# Build the project
cmake --build build --config Release

# Run ConfigForge
./build/ConfigForge --help
```

### Platform-Specific Instructions

<details>
<summary><strong>🪟 Windows (MSVC)</strong></summary>

```
# Using Visual Studio Developer Command Prompt
git clone https://github.com/dubskysteam/configforge.git
cd configforge
cmake -S . -B build -G "Visual Studio 17 2022"
cmake --build build --config Release
```

</details>

<details>
<summary><strong>🐧 Linux (GCC/Clang)</strong></summary>

```
# Install dependencies (Ubuntu/Debian)
sudo apt update
sudo apt install build-essential cmake git

# Build project
git clone https://github.com/dubskysteam/configforge.git
cd configforge
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(nproc)
```

</details>

<details>
<summary><strong>🍎 macOS (Xcode/Homebrew)</strong></summary>

```
# Install dependencies
brew install cmake

# Build project
git clone https://github.com/dubskysteam/configforge.git
cd configforge
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j$(sysctl -n hw.ncpu)
```

</details>

---

## 💻 Usage

### Basic Commands

<div style="background: linear-gradient(135deg, #667eea 0%, #764ba2 100%); padding: 20px; border-radius: 10px; color: white; margin: 10px 0;">

**🔍 Validate Configuration**
```
ConfigForge validate config.json
ConfigForge validate config.yaml --schema schema.json --strict
```

</div>

<div style="background: linear-gradient(135deg, #f093fb 0%, #f5576c 100%); padding: 20px; border-radius: 10px; color: white; margin: 10px 0;">

**🔄 Convert Formats**
```
ConfigForge convert config.json --output config.yaml
ConfigForge convert settings.toml --format json --pretty
```

</div>

<div style="background: linear-gradient(135deg, #4facfe 0%, #00f2fe 100%); padding: 20px; border-radius: 10px; color: white; margin: 10px 0;">

**🔀 Merge Configurations**
```
ConfigForge merge base.json override.json --output final.json
ConfigForge merge *.yaml --strategy deep --output merged.yaml
```

</div>

### Advanced Usage

```
# Verbose output with debug logging
ConfigForge validate config.json --verbose --log-level debug

# Watch for file changes
ConfigForge watch --dir ./configs --action validate

# Batch conversion
ConfigForge convert *.json --format yaml --output-dir ./yaml_configs
```

---

## 🔧 Development

### Build Configuration

```
# Debug build
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

# Release with debug info
cmake -S . -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo

# Custom compiler
cmake -S . -B build -DCMAKE_CXX_COMPILER=clang++
```

### Running Tests

```
# Build and run tests
cmake --build build --target test

# Verbose test output
ctest --test-dir build --verbose
```

---

## 📝 Commit Message Convention

<div align="center">

| Type | Description | Example |
|------|-------------|---------|
| `feat` | ✨ New feature | `feat(parser): add YAML format support` |
| `fix` | 🐛 Bug fix | `fix(cli): handle missing input files gracefully` |
| `docs` | 📚 Documentation | `docs(readme): update installation instructions` |
| `style` | 💎 Code style | `style(format): apply clang-format rules` |
| `refactor` | ♻️ Code refactoring | `refactor(parser): extract common validation logic` |
| `perf` | ⚡ Performance | `perf(merge): optimize deep merge algorithm` |
| `test` | 🧪 Testing | `test(json): add edge case validation tests` |
| `chore` | 🔧 Maintenance | `chore(deps): update nlohmann/json to v3.11.3` |
| `ci` | 👷 CI/CD | `ci(github): add automated testing workflow` |
| `build` | 📦 Build system | `build(cmake): add Windows MSVC support` |

</div>

### Commit Format

```
<type>(<scope>): <subject>

<body>

<footer>
```

---

<div align="center">

[🐛 Report Bug](https://github.com/dubskysteam/configforge/issues) • [💡 Request Feature](https://github.com/dubskysteam/configforge/issues)