

function solution(array, m) {
    const obj = {}
    for (let i = 0; i < array.length; i++) {
        for (let j = i + 1; j < array.length; j++) {
            if(Math.abs(array[i]-array[j]) % m === 0) {
                obj[i] = true;
                obj[j] = true;
            }
        }
    }
    return Object.keys(obj).length || 1
}

console.log(solution([-3,-2,0,1,1,7,8], 3))