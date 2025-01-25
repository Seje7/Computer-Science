
class Multiplication {
  public static void main(String[] args) {

    int[][] tabless = 
      {{4, 3, 0, 9, 2, 7, 1, 5, 6, 10,}, 
       {9,1,7,2,4,5,6,8,3,0}, {91,0,7,2,4,5,6,8,3,0},
  {9,107,2,4,5,6,8,3,0}, {2, 4, 0 ,7 ,10, 5, 3, 1,9, 8}};

    createMultiplicationTable(tabless);
    
    
  }
  public static int[][] createMultiplicationTable(int[][] table) {
      table = new int[5][10];
    for(int i =0; i < 5; i++){
      for(int j = 0; j < 10; j++){
        table[i][j] = (i+1)*(j+1);

        System.out.println(table[i][j]);
      }
      
    }
    return table;
    }
}
