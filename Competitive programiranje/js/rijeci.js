const inputArray = [5, 19, 8, 1]

let currentSum = inputArray.reduce((sum,val) => sum + val, 0);
const target = currentSum/2;
let counter = 0;

while(currentSum > target) {
    const maxNum = Math.max(...inputArray);
    const indexOfMax = inputArray.indexOf(maxNum);
    currentSum -= maxNum / 2;
    inputArray[indexOfMax] /= 2;
    counter++;
}
console.log(counter)