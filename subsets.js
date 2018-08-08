function subsets(input){
    let ret = [];
    function backtrack(input, output, level){
        if(level >= input.length){
            ret.push(output);
            return;
        }
        backtrack(input, output, level+1);
        backtrack(input, output + input[level], level+1);
    }

    backtrack(input, "", 0);
    return ret;
}

console.log(subsets('abc'));