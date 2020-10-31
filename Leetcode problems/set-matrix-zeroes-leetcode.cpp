class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      bool rowflag = false;
      bool colflag = false;
      for(int rowindex = 0 ; rowindex < matrix.size() ; rowindex++)
      {
            if(matrix[rowindex][0] == 0)
                colflag = true;
            
          for(int colindex = 1; colindex < matrix[0].size(); colindex++)
          {
              if(matrix[rowindex][colindex] == 0)
              {
                  matrix[rowindex][0] = 0;
                  matrix[0][colindex] = 0;
              }
          }
          
          
      }
        for(int rowindex = 1 ; rowindex < matrix.size();rowindex++)
        {
            for(int colindex = 1 ; colindex<matrix[0].size();colindex++)
            {
               if(matrix[0][colindex] == 0 || matrix[rowindex][0] == 0)
                   matrix[rowindex][colindex] = 0;
            }
        }
        if(matrix[0][0] == 0)
        {
            for(int colindex = 0; colindex < matrix[0].size();colindex++)
             matrix[0][colindex] = 0;
        }
        if(colflag == true)
        {
            
            for(int rowindex = 0; rowindex < matrix.size();rowindex++)
             matrix[rowindex][0] = 0;
        
        } 
    }
};
