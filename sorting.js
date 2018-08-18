function insertionSort(input){
    let i = 1;
    for(; i < input.length; i++){
        let j = 0;
        for(; j < i; j++){
            if(input[i] <input[j]){
                break;
            }
        }
        //move data
        let m = input[i];
        for(let k = i-1; k >=j; k--){
            input[k+1] = input[k];
        }
        input[j]= m;
    }
    return input;
}

console.log(insertionSort([1,2,3,4,5,6,]))
console.log(insertionSort([3,2,4,5,9,10,2]))