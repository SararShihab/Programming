import math
x1,y1 = map(int, input("Enter first coordinate: ").split())
x2,y2 = map(int, input("Enter second coordinate: ").split())
dist = math.sqrt(pow((x2-x1), 2)+pow((y2-y1), 2))
print(f"Euclidean distance: {dist:.4f}")