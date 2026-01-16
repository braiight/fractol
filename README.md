*This project has been created as part of the 42 curriculum by gumallet.*

# fract_ol

A fun program where you can explore the wonderful world of fractals.

## How to execute ?
 - For simplicity's sake, I have included the MLX library from Codam directly in the repository. However, if you encounter any issues, please delete the MLX42 folder and [git clone this](https://github.com/codam-coding-college/MLX42) at the root of the repository.
 - Run `make` at the root of the repository.
 - Run `./fractol <argument>` where `<argument>` can be one of the following:

 `Mandelbrot`
 - This will let you visualize the famous Mandelbrot set. you can move around using the `wasd` keys, and zoom in and out using the mouse wheel.

`Julia_Dynamic`
 - Move your mouse around inside the window and watch the Julia sets evolve!

`Julia_Fixed a b`
 - This lets you see the Julia set of a specific complex number.
 - `a` and `b` are the real and imaginary values of said complex number.
 - `a` and `b` *must* be decimal numbers between -2 and 2.
 - Move around with the `wasd` keys and zoom in and out with the mouse wheel.

`Ship`
 - This will let you visualize the Burning Ship fractal.
 - Move around with `wasd` keys and zoom in and out with the mouse wheel.

### Note:
 - For all fractals, pressing `c` will change the color palette.

## Performance tips
 - You can modify the different rendering macros in the `fractol.h` header file to tune performance.
 - `WIDTH` and `HEIGHT` change the window's size. A bigger window means slower performance. *Note: I didn't implement correct scaling, so please keep `WIDTH` and `HEIGHT` identical to avoid having spread-out/squished fractals.*
 - `MAX_ITER`, `MAX_ITER_JULIA`, and `MAX_ITER_SHIP` modify the maximum number of iterations before determining if a number is within its set or not. Higher iterations = prettier, more detailed fractals at the cost of performance. I do not recommend going over 200.
