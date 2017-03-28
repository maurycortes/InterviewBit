//MI VERSION - Timelimit

int Solution::maximumGap(const vector<int> &A) {
    int maxDistance=0;
    for(int i=0; i<A.size()-1; i++)
    {
        for(int j=i+1; j<A.size(); j++)
        {
            if(A[j] >= A[i])
            {
                if(j-i > maxDistance)
                    maxDistance = j-i;
            }
        }
    }
    return maxDistance;
}





//Otra VERSION - MEJOR

int Solution::maximumGap(const vector<int> &A) {
    vector<bool> tempArr(A.size());
    int min = A[0];
    int max_distance = 0;
    int i = A.size()-1;
    int j = A.size()-1;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] > min){
            tempArr[i] = false;
        }
        else{
            min = A[i];
            tempArr[i] = true;
        }
    }

    LOOP:while(i >= 0){
        if(tempArr[i] == false){
            i--;
            goto LOOP;
        }
        while((A[i] > A[j]) && (j > i)){
            j--;
        }
        if((j-i) > max_distance){
            max_distance = j-i;
        }
        i--;
    }
    return max_distance;
}