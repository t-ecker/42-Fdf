# fdf - 42 School

### 🏆 Score: **125/100** (+25 for bonus)

## 📚 About the Project

**fdf** is a project that involves creating a simple 3D visualizer using a custom graphics library. The goal is to display 3D models of 2D maps by projecting points onto the screen, and connecting them. The project requires handling user inputs, applying transformations (like rotation, zooming, and moving), and rendering the 3D models in an interactive window.

### 🧠 My Approach

1. **Data Parsing**: Parsing a map file that contains the 3D coordinates of points. This data is read, stored, and prepared for rendering.
2. **Creating the 3D Projection**: I applied mathematical transformations to convert 3D coordinates into 2D screen coordinates. This includes rotation, scaling, and translation operations.
3. **Graphics Library**: For rendering, I used the **[MLX42](https://github.com/codam-coding-college/MLX42)** graphics library, which is needed for creating windows, drawing shapes, and handling user input.
4. **User Interaction**: I implemented controls for rotating the map, zooming in and out, and moving/changing the view to allow users to interact with the visualisation.
5. **Appearance**: To enhance the visual appeal, I implemented color gradients and an Interface.

### 📚 What I Learned

- **2D and 3D Transformations**: Applying geometric transformations such as rotation and scaling to visualize 3D objects in a 2D space.
- **User Input Handling**: Managing keyboard and mouse inputs for interaction with the program.
- **Graphics Programming**: Working with a custom graphics library and learning about pixel manipulation for rendering.

## 🚀 Usage

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/t-ecker/42-Fdf.git
cd fdf
```

### 2️⃣ Compile the Program

```bash
make bonus
```
> **Note**: The "bonus" version provides the best experience

### 3️⃣ Run the Program

```bash
./fdf_bonus maps/map_file.fdf
```

Where `map_file.fdf` is a file containing the 3D map data.

## 🏁 Conclusion

**fdf** demonstrates how to visualize 3D models in a 2D space by applying geometric transformations and using custom graphics libraries. It provides an introduction to graphical programming, user interaction, and map parsing, offering a foundation for building more complex visualisations.
