int * insertionSort(int original[], int length) {
	int i, j, atual;

	for (i = 1; i < length; i++) {
		atual = original[i];
		j = i - 1;

		while ((j >= 0) && (atual < original[j])) {
			original[j + 1] = original[j];
			j = j - 1;
		}

		original[j + 1] = atual;
	}

	return (int * )original;
}
