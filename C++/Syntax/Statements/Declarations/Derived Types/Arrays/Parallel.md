### Parallel Arrays
Two (or more) arrays are called parallel if their corresponding components hold related information.

These statements declare two parallel arrays:

  int studentId[50];
  char courseGrade[50];

Suppose you need to input data into these arrays, and the data is provided in a file in the following form:

  studentId courseGrade

For example, a sample data set is:

  23456 A
  86723 B
  22356 C
  92733 B
  11892 D
  ...

Suppose that the input file is opened using the ifstream variable infile. Because the size of each array is 50, a maximum of 50 elements can be stored into each array.

Moreover, it is possible that there may be fewer than 50 students in the class. Therefore, while reading the data, we also count the number of students and ensure that the array indices do not go out of bounds. The following loop reads the data into the parallel arrays studentId and courseGrade:

  int noOfStudents = 0;
  infile >> studentId[noOfStudents] >> courseGrade[noOfStudents];

  while (infile && noOfStudents++ < 50) {
    infile >> studentId[noOfStudents] >> courseGrade[noOfStudents];
  }

Note that, in general, when swapping values in one array, the corresponding values in parallel arrays must also be swapped.
