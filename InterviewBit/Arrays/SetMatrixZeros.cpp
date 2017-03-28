 int r = A.size();
 int c = A[0].size();
 bool firstRowHasZero = false, firstColHasZero = false;

for(int j=0;j<c;j++){
     if(A[0][j]==0 ){
         firstRowHasZero=true;
         break;
     }
 }
 
 for(int j=0;j<r;j++){
     if(A[j][0]==0){
         firstColHasZero=true;
         break;
         
     }
 }
 
 for(int i =1;i<r;i++){
     for (int j=1;j<c;j++){
        if(A[i][j]==0){
            A[i][0]=0;
            A[0][j]=0;
        }
     }
 }
 
 
 for(int i=1;i<r;i++){
     for(int j=1;j<c;j++){
         if(A[i][0]==0 || A[0][j]==0){
             A[i][j]=0;
         }
     }
 }
 
 if(firstRowHasZero){
     for(int i=0;i<c;i++){
         A[0][i]=0;
     }
 }
 
 if(firstColHasZero){
     for(int i=0;i<r;i++){
         A[i][0]=0;
     }
 }





 /////////////////////////////////////////////////OTRA VERSION



 void Solution::setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int row = matrix.size();
        if (row==0){return;}
        int col = matrix[0].size();
        if (col==0){return;}
         
        bool fc0=false;
        bool fr0=false;
         
        for (int i=0;i<col;i++){
            if (matrix[0][i]==0){fr0 = true;}
        }
         
        for (int i=0;i<row;i++){
            if (matrix[i][0]==0){fc0 = true;}
        }
         
        for (int i=1;i<row;i++){
            for (int j=1;j<col;j++){
                if (matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
         
         
        for (int i=1;i<col;i++){
            if (matrix[0][i]==0){
                for(int j=0;j<row;j++){
                    matrix[j][i]=0;
                }
            }
        }
         
        for (int i=1;i<row;i++){
            if (matrix[i][0]==0){
                for(int j=0;j<col;j++){
                    matrix[i][j]=0;
                }
            }
        }
         
        if (fr0){
            for (int i=0;i<col;i++){matrix[0][i]=0;}
        }
        if (fc0){
            for (int i=0;i<row;i++){matrix[i][0]=0;}
        }
         
        return;
         
    }