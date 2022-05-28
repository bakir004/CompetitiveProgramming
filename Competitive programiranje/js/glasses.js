function solution(n, k) {
    let required = n;
    let lowerBound = n * (n + 1) / 2;

    let stepper = 2;

    if(k > n) {
        return -1;
    }

    while(true) {
        if(k >= lowerBound) {
            return required;
        } else {
            lowerBound -= stepper
            required--;
            stepper++;
        }
    }
}

console.log(solution(10, 5))