# Personal_BookMark_Manager

A **Personal Bookmark Manager** that lets you save, organize, and access your web bookmarks securely, using a C++ backend and a web-based interface.

---

**🌐 [Live Demo](https://project.harshishere.in.net/player.html?video=Personal_Bookmark_manager_Showcase%20-%20Made%20with%20Clipchamp.mp4)**

---

## Features

- **Add, view, and organize bookmarks:** Store and manage your favorite web links efficiently.
- **Web-based interface:** Access your bookmarks through a user-friendly browser interface.
- **Bookmark persistence:** Bookmarks are saved in `bookmarks.json` for data durability.
- **C++ backend:** Backend logic and endpoints written in C++ (`main.cpp`).
- **Custom templates:** Modular organization with `static` and `templates` folders for UI.

## Project Structure

| Folder / File   | Purpose                                  |
| --------------- | ---------------------------------------- |
| .vscode         | Editor configurations                    |
| include         | Header files and definitions             |
| static          | Static assets (CSS, JS, images)          |
| templates       | HTML templates for web UI                |
| bookmarks.json  | Saved user bookmarks (data storage)      |
| main.cpp        | Main backend logic (C++ source)          |

## Technologies Used

- **C++ (31.5%)** — Backend logic and data handling
- **HTML (56.6%)** — User interface
- **CSS (11.9%)** — Styling and layout

## Setup & Usage

### 1. Clone the repository

    
      git clone https://github.com/harshsaxena213/Personal_BookMark_Manager
      cd Personal_BookMark_Manager
    


### 2. Install Dependencies

- [Crow C++ microframework](https://github.com/CrowCpp/Crow) (header-only)
- [ASIO standalone library](https://think-async.com/Asio) (header-only)
- C++17 or later compiler (e.g., g++, clang++)
- (Optional) CMake for build configuration

> **Tip:** You can install Crow and its dependencies via package managers like `vcpkg` or `conan`:
> ```
> vcpkg install crow
> ```
> or add to `conanfile.txt`:
> ```
> [requires]
> crowcpp-crow/1.2.1
> ```

### 3. Build the project

Compile the `main.cpp` file with a C++17 compatible compiler:


Make sure all dependencies (Crow, ASIO) are properly included in the include path.

### 4. Run the application

Execute the compiled binary:


Open your web browser and navigate to the address and port specified in `main.cpp` (usually `http://localhost:80` or similar) to access the bookmark manager.

## Contribution

Pull requests are welcome! For significant changes, please open an issue first to discuss your ideas.


> **Note:** For more detailed setup or dependency instructions, review the source code in `main.cpp` and the headers in the `include` folder.
