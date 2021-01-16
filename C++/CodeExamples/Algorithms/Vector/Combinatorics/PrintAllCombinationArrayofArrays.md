using namespace std;

// function to print combinations that contain
// one element from each of the given arrays
void print(vector<vector<int>>& arr) {
    // number of arrays
    int n = arr.size();

    // to keep track of next element in each of
    // the n arrays
    int* indices = new int[n];

    // initialize with first element's index
    for (int i = 0; i < n; i++)
        indices[i] = 0;

    while (1) {
        // print current combination
        for (int i = 0; i < n; i++)
            cout << arr[i][indices[i]] << " ";
        cout << endl;

        // find the rightmost array that has more
        // elements left after the current element
        // in that array
        int next = n - 1;
        while (next >= 0 &&
              (indices[next] + 1 >= arr[next].size()))
            next--;

        // no such array is found so no more
        // combinations left
        if (next < 0)
            return;

        // if found move to next element in that
        // array
        indices[next]++;

        // for all arrays to the right of this
        // array current index again points to
        // first element
        for (int i = next + 1; i < n; i++)
            indices[i] = 0;
    }
}


We keep an array of size equal to the total no of arrays. This array called indices helps us keep track of the index of the current element in each of the n arrays. Initially, it is initialized with all 0s indicating the current index in each array is that of the first element. We keep printing the combinations until no new combinations can be found. Starting from the rightmost array we check if more elements are there in that array. If yes, we increment the entry for that array in indices i.e. moves to the next element in that array. We also make the current indices 0 in all the arrays to the right of this array. We keep moving left to check all arrays until one such array is found. If no more arrays are found we stop there.
