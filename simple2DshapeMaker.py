#!/bin/python3
import tkinter as tk

points = []
window_width=800
window_height=600

def on_click(event):
    x, y = event.x, event.y
    if points:
        prev_x,prev_y=points[-1]
        if prev_x==x and prev_y==y:return
    canvas.create_oval(x-3, y-3, x+3, y+3, fill='black')
    if points:
        prev_x,prev_y=points[-1]
        canvas.create_line(x,y,prev_x,prev_y)
    points.append((x, y))

def print_coords():
    global window_width, window_height
    mid_width = window_width // 2
    mid_height = window_height // 2
    
    print("Points clicked:")
    with open("shape.txt", "w") as file:
        for i, (x, y) in enumerate(points, 1):
            print(f"Point {i}: ({x}, {y})")
            
            # Convert to range [-1, 1]
            # First, center the coordinates around 0
            centered_x = x - mid_width
            centered_y = y - mid_height
            
            # Then normalize to [-1, 1]
            norm_x = centered_x / mid_width
            norm_y = centered_y / mid_height
            
            # Round for cleaner output (optional)
            norm_x = round(norm_x, 5)
            norm_y = -round(norm_y, 5) # invert the y axis in the opengl normalization
            
            print(f"Norm Points: ({norm_x}, {norm_y})")
            file.write(f"{norm_x}f, {norm_y}f, 0.0f,\n")

def clear_canvas():
    global points
    points=[]
    canvas.delete("all")

window = tk.Tk()
window.title("Click to Mark Points")

canvas = tk.Canvas(window, width=window_width, height=window_height, bg='white')
canvas.pack(pady=10)

canvas.bind("<Button-1>", on_click)

button = tk.Button(window, text="Print Coordinates", command=print_coords)
button.pack(side=tk.LEFT,pady=5)

button = tk.Button(window, text="Clear", command=clear_canvas)
button.pack(side=tk.LEFT,pady=5)

window.mainloop()