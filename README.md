

# Design Patterns in C++ (with Aura)

Welcome to the **Design Patterns** repository!  
This project implements essential **Design Patterns** in **C++**, organized modularly using the [Aura](https://github.com/vishal-ahirwar/aura) project setup.  
It’s designed to be **scalable**, **clean**, and **ready for learning and reference**.



## 🏗️ Folder Structure

```
design-patterns/
├── adapter/                  # Adapter Pattern Implementation
├── bridge/                   # Bridge Pattern Implementation
├── singleton/                # Singleton Pattern
├── factory-method/           # Factory Method Pattern
├── abstract-factory/         # Abstract Factory Pattern
├── prototype/                # Prototype Pattern
├── builder/                  # Builder Pattern
├── observer/                 # Observer Pattern
├── strategy/                 # Strategy Pattern
├── template-method/          # Template Method Pattern
├── command/                  # Command Pattern
├── state/                    # State Pattern
├── decorator/                # Decorator Pattern
├── composite/                # Composite Pattern
├── proxy/                    # Proxy Pattern
├── facade/                   # Facade Pattern
├── mediator/                 # Mediator Pattern
├── memento/                  # Memento Pattern
├── chain-of-responsibility/  # Chain of Responsibility Pattern
├── interpreter/              # Interpreter Pattern
├── iterator/                 # Iterator Pattern
├── visitor/                  # Visitor Pattern
├── design-patterns/          # Shared base or common utilities
├── res/                      # Assets, diagrams, documentation resources
├── .gitignore                # Git ignore rules
├── CMakeLists.txt            # Top-level CMake build configuration
├── CMakePresets.json         # CMake configuration presets
├── vcpkg.json                # vcpkg manifest for dependency management
```

---

## ⚡ Technologies Used

- **C++23**  
- **CMake**
- **vcpkg** (for managing external libraries if needed)
- **Aura CLI** (for project and build automation)

---

## 📦 Building the Project

Make sure you have:
- CMake 3.20+
- Ninja (optional but faster builds)
- vcpkg (auto-handled if using Aura)
- aura (optional)
  
### Quick Build
```bash
aura build <design-pattern name>
```
or manually:
```bash
cmake --preset default
cmake --build --preset default
```

---

## 🎯 Goals

- Implement all classic **Design Patterns** in clean, modern C++.
- Keep each pattern **isolated** and **easy to understand**.
- Use **minimal dependencies** — focus on the core concepts.

---

## 🤝 Contributing

Contributions are welcome! Feel free to open issues or pull requests if you have suggestions, improvements, or new ideas.

---

## 📜 License

This project is licensed under the **MIT License**. See [LICENSE](LICENSE) for details.

---

### 🔥 Made with love and C++ by [Vishal Ahirwar](https://github.com/vishal-ahirwar)
