/* This project takes a sudoku grid and checks to see if it is valid
The input is a sudoku grid (In a text file)
The output is the same sudoku grid with a YES/NO statement to indicate valid or in valid
There are 3 threads that are used to check the sudoku grid with the verify_Sudoku function
The first thread checks the rows with the verify_Sudoku_Row function
The second thread checks the columns with the verify_Sudoku_Column function
The third thread checks the subgrids with the verify_Sudoku_Grid function
The main function creates the threads and waits for them to finish
The main function then checks the thread_select results and prints whether the Sudoku grid is valid/invalid
Work done by OSELUNOSEN EHI-DOUGLAS*/


#include <pthread.h> // for pthread_create
#include <stdio.h> // for printf
#include <stdlib.h>

// Size of column and row 
#define GRID_SIZE 9 
// Number of threads
#define NUM_THREADS 3


// Define data structure to hold Sudoku grid
typedef struct {
  int grid[GRID_SIZE][GRID_SIZE]; // 2D array to hold Sudoku grid
  int thread_select; // used to choose which function to run
} SudokuGrid; 

// Define Row Function 
void *verify_Sudoku_Row(void *args){
  SudokuGrid *grid = (SudokuGrid *)args; // Cast to SudokuGrid pointer

   // Check rows
  for (int i = 0; i < GRID_SIZE; i++) { // Loop through rows
  for (int j = 0; j < GRID_SIZE; j++) { // Loop through columns
      int value = grid->grid[i][j];  // Get value from grid
  for (int k = j; k < GRID_SIZE; k++) {  // Loop through columns
  if (grid->grid[i][(k+1) % 9] == value) { // Check if value is already in row
      return (void *) -1; // Return -1 if value is invalid
    }
  if((k + 2 ) % 9 == 0) { // Check if we have reached the end of the row
     break; // Break out of inner loop
  }}}}
  pthread_exit(NULL); // Exit thread
}

// Define Column Function  
void *verify_Sudoku_Column(void *args){
  SudokuGrid *grid = (SudokuGrid *)args; // Cast to SudokuGrid pointer

  // Check columns
  for (int i = 0; i < GRID_SIZE; i++) { // Loop through rows
  for (int j = 0; j < GRID_SIZE; j++) { // Loop through columns
      int value = grid->grid[j][i]; // Get value from grid
  for (int k = j; k < GRID_SIZE; k++) { // Loop through columns
  // Check if value is invalid
  if (grid->grid[(k+1) % 9][i] ==value) { 
    return (void *) -1; // Return -1 if value is invalid
  }
  if((k + 2 ) % 9 == 0) { // Check if we have reached the end of the column
    break; }}}} 
  pthread_exit(NULL); // Exit thread
}

// Define thread function
void *verify_Sudoku_Grid(void *args) {
  // Cast args to the appropriate type
 SudokuGrid *grid = (SudokuGrid *)args; // Cast to SudokuGrid pointer

  // Check subgrids
  for (int i = 0; i < GRID_SIZE; i += 3) { // Loop through rows
    int size_row_grid =+ 3; // Size of subgrid row
  for (int m = 0; m < GRID_SIZE; m += 3){  // Loop through columns
    int size_Column_grid =+ 3; // Size of subgrid column
  for (int j = i; j < size_row_grid; j++) { // Loop through rows
  for (int k = m; k < size_Column_grid; k++) { // Loop through columns
      int value = grid->grid[j][k]; // Get value from grid
  for (int l = k; l < size_Column_grid; l++) { // Loop through columns
          {
  if (value == grid->grid[j][(l+1) % size_Column_grid]) { // Check if value is invalid
    return (void *) -1; // Return -1 if value is invalid
      }
  if ((l+2) % size_Column_grid == 0){ // Check if we have reached the end of the column
    break; // Break out of inner loop
  }}}}}}}

  pthread_exit(NULL); // Exit thread
}

// Define Verify function
void *verify_Sudoku(void *args) {
      void *ret, *ret1, *ret2; // Declare return values for each thread
      SudokuGrid *grid = (SudokuGrid *)args; // Cast to SudokuGrid pointer

      switch (grid->thread_select) { // Switch statement to choose which function to run
          case 0: // Row thread
      ret = verify_Sudoku_Row(grid); // Call Row thread
      return ret; // Return return value from Row thread
      break; // Exit switch statement
          case 1: // Column thread
      ret1 = verify_Sudoku_Column(grid); // Call Column thread
      return ret1; // Return return value from Column thread
      break; // Exit switch statement
      case 2: // Subgrid thread
      ret2 = verify_Sudoku_Grid(grid); // Call Subgrid thread
      return ret2; // Return return value from Subgrid thread
      break; // Exit switch statement
      default: // Default case
        printf(" INVALID "); // Print error message
      }
      pthread_exit(NULL); // Exit thread
  }


int main() {
  int ret, ret1, ret2; // Declare return values for each create thread
  void * t_return, *t_return1, *t_return2; // Declare return values for each join thread
  SudokuGrid grid, grid1, grid2; // Declare SudokuGrid variable

printf("The sudoku Numbers: \n ");

  // Read Sudoku grid from standard input
  for (int i = 0; i < GRID_SIZE; i++) {
  for (int j = 0; j < GRID_SIZE; j++) {
  scanf("%d", &grid.grid[i][j]);

  // Handle input error
  if (grid.grid[i][j] < 1 || grid.grid[i][j] > GRID_SIZE || i > (GRID_SIZE - 1) || j > (GRID_SIZE - 1)){ // Check if input is valid
  perror("\t INVALID \n"); // Print error message
  return -1; // Exit program with error code
          }}}

  // different grids for the different threads
  grid1 = grid; // Copy grid to grid1
  grid2 = grid; // Copy grid to grid2

  // Declare threads
   pthread_t threads[NUM_THREADS];

  // Create threads
  for (int i = 0; i < 3; i++){

  if (i == 0){ // Row thread
    grid.thread_select = 0; // Set thread_select to 0
  ret = pthread_create(&threads[i], NULL, verify_Sudoku, &grid);
  }
  else if (i == 1){ // Column thread
    grid1.thread_select = 1; // Set thread_select to 1
  ret1 = pthread_create(&threads[i], NULL, verify_Sudoku, &grid1);
  }
  else if (i == 2){ // Subgrid thread
    grid2.thread_select = 2; // Set thread_select to 2
  ret2 = pthread_create(&threads[i], NULL, verify_Sudoku, &grid2);
  }
  }

  if (ret != 0 || ret1 != 0 || ret2 != 0){ // Check if any threads failed
  perror("Error creating thread\n"); // Print error message
  return 1; // Exit program with error code
  }

  // Wait for threads to finish
  // Join threads
   pthread_join(threads[0],&t_return); // Join Row thread 
   pthread_join(threads[1], &t_return1); // Join Column thread
   pthread_join(threads[2], &t_return2); // Join Subgrid thread


  // Check thread_select results and print whether the Sudoku grid is valid 
  if (t_return != NULL  || t_return1 != NULL || t_return2 != NULL){
  printf("---------------------\n");

  for (int i = 0; i < GRID_SIZE; i++) { // Print Sudoku grid
  for (int j = 0; j < GRID_SIZE; j++) { 
     printf(" %d ", grid.grid[i][j]);
   }
     printf("\n"); 
    }  
     printf("NO\n"); // Print "NO" if any thread returned -1
  }

  else {
	 printf("---------------------\n");

    for (int i = 0; i < 9; i++) { // Print Sudoku grid
    for (int j = 0; j < 9; j++) {
    printf(" %d ", grid.grid[i][j]);
      }
    printf("\n");
     } 
    printf("YES\n"); // Print "YES" if all threads returned NULL
  }

    return 0;
}
