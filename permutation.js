function getPermutation(input){
    let result = [];
    function backtrack(input, output, level, totalLevel){
        if(level >= totalLevel){
            result.push(output);
            return;
        }
        for(let i = 0; i < input.length; i++){
            let newInput = input.substr(0,i) + input.substr(i+1, input.length);
            let newOutput = output + input[i];
            backtrack(newInput, newOutput, level+1, totalLevel);
        }
    }
    backtrack(input, "", 0, input.length);
    console.log("total permutation: ", result.length);
    return result;
}
console.log(getPermutation("1234"));