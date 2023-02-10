import numpy as np

def solve(W, H, x1, y1, x2, y2, w, h):
	top_left = x1 * (H - y2)
	top_right = (W - x2) * (H - y2)
	bottom_left = x1 * y1
	bottom_right = (W - x2) * y1
	corner_choice = np.argmax([top_left, top_right, bottom_left, bottom_right])		

	dx, dy = 0, 0
	if corner_choice == 1 or corner_choice == 3:
		if x2 > (W-w):
			dx = x2-(W-w)
	elif x1 < w:
		dx = w-x1

	if corner_choice == 0 or corner_choice == 1:
		if y2 > (H-h):
			dy = y2-(H-h)
	elif y1 < h:
		dy = h-y1

	return min(dx, dy)
    
test_cases = int(input())

for i in range(test_cases):
	W, H = [int(x) for x in input().split(" ")]
	x1, y1, x2, y2 = [int(x) for x in input().split(" ")]
	w, h = [int(x) for x in input().split(" ")]
	print(solve(W, H, x1, y1, x2, y2, w, h))
