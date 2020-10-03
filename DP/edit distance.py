# Function to find Levenshtein Distance between X and Y
# m and n are the number of characters in X and Y respectively
def dist(X, m, Y, n):

	# base case: empty strings (case 1)
	if m == 0:
		return n

	if n == 0:
		return m

	# if last characters of the strings match (case 2)
	cost = 0 if (X[m - 1] == Y[n - 1]) else 1

	return min(dist(X, m - 1, Y, n) + 1,			# deletion (case 3a))
			   dist(X, m, Y, n - 1) + 1,			# insertion (case 3b))
			   dist(X, m - 1, Y, n - 1) + cost)	 # substitution (case 2 + 3c)


if __name__ == '__main__':

	X = "kitten"
	Y = "sitting"

	print("The Levenshtein Distance is", dist(X, len(X), Y, len(Y)))
