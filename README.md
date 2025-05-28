
# 2D Grid Game Engine (Raylib + C)

This project is a learning-focused 2D grid-based game engine built in C using [Raylib](https://www.raylib.com/).
It serves as a foundation for experimenting with tile-based mechanics, screen transitions, and map editing.

---

## 📁 Project Structure

```
2D-Grid-game-engine-using-Raylib/
├── build/              # Compiled binaries
├── src/                # Main source code (.c)
├── CMakeLists          # Build script using CMake
└── README.md           # This file
```

---

## ⚙️ Setup Instructions

### 1. Install Raylib

Follow the official Raylib installation guide: [Raylib Wiki](https://github.com/raysan5/raylib/wiki)

### 2. Build the Project

Ensure you have `CMake` and a C compiler installed. Then, in the project root directory, run:

```bash
make
```

This will compile the project and place the executable in the `build/` directory.

---

## 🕹️ How to Use

### Map and Grid Configuration

To customize the map and grid sizes, modify the following variables in `main.c`:

- `iMapSize` – Define the map dimensions (width and height).
- `iGridSize` – Set the size of each grid cell.

**Note:** Currently, these settings are hardcoded. To apply changes, you must recompile the project after editing these values.

### Screen Navigation

The engine includes three screens:

- **TITLE** – The initial screen displayed upon launching the game.
- **GAMEPLAY** – The main game screen.
- **MAPCREATION** – A screen for creating and editing maps.

**Note:** Ensure that a map is created before starting the game; otherwise, pressing `PLAY` will have no effect.

---

## 🧪 Features

- Basic 2D grid rendering using Raylib.
- Multiple screen management (Title, Gameplay, Map Creation).
- Customizable map and grid sizes via source code.

---

## 📌 Notes

- The engine is in an early development stage and primarily serves educational purposes.

---

## 🧱 Dependencies

- [Raylib](https://www.raylib.com/) – A simple and easy-to-use library to learn game programming.

---

## 🧑‍💻 Author

- **Arthur Naue** – [GitHub Profile](https://github.com/ArthurNaue)
