
const getMaxSum = (A)=>{
    if(!A.length)
        return 0;
    let ans = 0;
    let sum = 0;
    for(const element of A){
        sum += element;
        ans = Math.max(sum,ans);
        if(sum<0){
            sum=0;
        }
    }
    return ans;
}

const array = [1,2,3,4,-1,5];
console.log(getMaxSum(array));