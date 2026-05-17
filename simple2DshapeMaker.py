#!/bin/python3
import tkinter as tk

points = []

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
    print("Points clicked:")
    for i, (x, y) in enumerate(points, 1):
        print(f"  Point {i}: ({x}, {y})")

def clear_canvas():
    global points
    points=[]
    canvas.delete("all")

window = tk.Tk()
window.title("Click to Mark Points")

canvas = tk.Canvas(window, width=500, height=400, bg='white')
canvas.pack(pady=10)

canvas.bind("<Button-1>", on_click)

button = tk.Button(window, text="Print Coordinates", command=print_coords)
button.pack(side=tk.LEFT,pady=5)

button = tk.Button(window, text="Clear", command=clear_canvas)
button.pack(side=tk.LEFT,pady=5)

window.mainloop()