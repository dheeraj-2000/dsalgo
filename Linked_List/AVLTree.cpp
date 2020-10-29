#include <stdio.h>
#include <stdlib.h>

struct tree
{
	int x;
	int height;
	struct tree *left;
	struct tree *right;
} * root;

int max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int getHeight(struct tree *curr)
{
	if (curr == NULL)
		return 0;
	return curr->height;
}

int getBalanceFactor(struct tree *curr)
{
	if (curr == NULL)
		return 0;
	return getHeight(curr->left) - getHeight(curr->right);
}

struct tree *rightRotate(struct tree *curr)
{
	struct tree *pivot = curr->left;
	struct tree *cut = pivot->right;

	pivot->right = curr;
	curr->left = cut;

	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	pivot->height = max(getHeight(pivot->left), getHeight(pivot->right)) + 1;

	return pivot;
}

struct tree *leftRotate(struct tree *curr)
{
	struct tree *pivot = curr->right;
	struct tree *cut = pivot->left;

	pivot->left = curr;
	curr->right = cut;

	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	pivot->height = max(getHeight(pivot->left), getHeight(pivot->right)) + 1;

	return pivot;
}

struct tree *insert(struct tree *curr, int x)
{
	if (curr == NULL)
	{
		curr = (struct tree *)malloc(sizeof(struct tree));
		curr->x = x;
		curr->height = 1;
		curr->left = curr->right = NULL;
	}
	else if (x < curr->x)
	{
		curr->left = insert(curr->left, x);
	}
	else
	{
		curr->right = insert(curr->right, x);
	}

	int height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	int balanceFactor = getBalanceFactor(curr);

	curr->height = height;

	if (balanceFactor > 1 && x < curr->left->x)
	{
		return rightRotate(curr);
	}

	if (balanceFactor > 1 && x > curr->left->x)
	{
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}

	if (balanceFactor < -1 && x > curr->right->x)
	{
		return leftRotate(curr);
	}

	if (balanceFactor < -1 && x < curr->right->x)
	{
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	return curr;
}

struct tree *maxNode(struct tree *curr)
{
	while (curr->right != NULL)
	{
		curr = curr->right;
	}
	return curr;
}

struct tree *remove(struct tree *curr, int x)
{
	if (curr == NULL)
	{
		printf("%d is not found", x);
		return NULL;
	}
	else
	{
		if (x < curr->x)
			curr->left = remove(curr->left, x);
		else if (x > curr->x)
			curr->right = remove(curr->right, x);
		else
		{
			if (curr->left == NULL && curr->right == NULL)
			{ //leaf
				free(curr);
				curr = NULL;
			}
			else if (curr->left == NULL)
			{
				struct tree *temp = curr;
				curr = curr->right;
				free(temp);
			}
			else if (curr->right == NULL)
			{
				struct tree *temp = curr;
				curr = curr->left;
				free(temp);
			}
			else
			{
				struct tree *temp = maxNode(curr->left);
				curr->x = temp->x;
				curr->left = remove(curr->left, temp->x);
			}
		}
	}

	if (curr == NULL)
	{
		return curr;
	}
	curr->height = max(getHeight(curr->left), getHeight(curr->right)) + 1;
	int balanceFactor = getBalanceFactor(curr);

	if (balanceFactor > 1 && getBalanceFactor(curr->left) >= 0)
	{
		return rightRotate(curr);
	}
	if (balanceFactor > 1 && getBalanceFactor(curr->left) < 0)
	{
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	if (balanceFactor < -1 && getBalanceFactor(curr->right) <= 0)
	{
		return leftRotate(curr);
	}
	if (balanceFactor < -1 && getBalanceFactor(curr->right) > 0)
	{
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	return curr;
}

void inOrder(struct tree *curr)
{
	if (curr != NULL)
	{
		inOrder(curr->left);
		printf("Value : %d Height : %d BalanceFactor : %d\n", curr->x, curr->height, getBalanceFactor(curr));
		inOrder(curr->right);
	}
}

int main()
{
	root = insert(root, 10);
	root = insert(root, 15);
	root = insert(root, 20);
	root = insert(root, 5);
	root = insert(root, 1);
	root = insert(root, 12);
	root = insert(root, 13);
	root = insert(root, 11);
	root = insert(root, 21);
	root = insert(root, 14);
	inOrder(root);
	puts("");
	root = remove(root, 12);
	inOrder(root);
	puts("");
	root = remove(root, 15);
	inOrder(root);
	puts("");

	return 0;
}
