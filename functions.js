function range(start, end, step){
    let result = new Array(end - start + 1);
    let value = start;
    let index = 0;
    while(index < result.length){
        result[index] = value;
        index++;
        value++;
    }
    console.log(result);
    return result;
}

function sum(input){
    //let result = 0;
    //input.reduce((result, value) => result += value);

    return input.reduce( (result, value)=> result += value)
    //return result;
}

console.log(sum(range(1, 10)));